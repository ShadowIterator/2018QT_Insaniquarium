#include "gamea.h"
#include "ui_gamea.h"
#include "QHBoxLayout"
#include <QEvent>
#include <QMouseEvent>
#include "utils.h"
#include "si_geometry.hpp"
#include "objectwidget.h"

GameA::GameA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameA)
{
	qDebug() << "GameA this " << this ;
    ui->setupUi(this);
    this->setWindowTitle("游戏");
    this->setWindowModality(Qt::ApplicationModal); //阻塞除当前窗体之外的所有的窗体

	//初始金额1000.
    ui->money->setText("1000");
    this->money = 1000;

    //主计时器
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateState()));
    timer->start(5);

    //fishmove
    QTimer *timer3 = new QTimer(this);
    connect(timer3,SIGNAL(timeout()),this,SLOT(fishMove()));
    timer3->start(500);

    //gold
    QTimer *timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(addgold()));
	timer2->start(1000);

    ui->gameView->installEventFilter(this);

	connect(this, SIGNAL(_increaseMoney(int, ObjectWidget*, const SI_String&)), this, SLOT(increaseMoney(int, ObjectWidget*, const SI_String&)));
}

//防止内存泄漏
GameA::~GameA()
{
    delete ui;
    for (auto item: fishs)
    {
        delete item;
    }
    for (auto item: golds)
    {
        delete item;
    }
}


//菜单
void GameA::on_menu_clicked()
{

}

//购买第一种鱼
void GameA::on_fish1_clicked()
{
    if(money < 100)
    {
        return;
        //金钱不足
    }
    else
    {
        money -= 100;
        QString s = QString::number(this->money, 10);
        ui->money->setText(s);

        //加入新古比鱼
        Gubbi* gubbi = new Gubbi;
        fishWidget* newfish = new fishWidget(ui->gameView, gubbi);
        newfish->show();
        fishs.push_back(newfish);
    }
}

void GameA::updateState()
{
    for (auto item: fishs)
    {
        item->updatefish();
        item->update();
        if(item->getType() == GUBBI)
        {
            for (auto i = foods.begin(); i != foods.end(); )
            {
				ObjectWidget* food = *i;
                if (Utils::judgeOverlap(QVector2D((*item).pos()), QVector2D((*food).pos())))
                {
                    item->growing();
                    i = foods.erase(i);
                    food->deleteLater();
                }
                else
                {
                    i++;
                }
            }
        }

        if(item->getType() == CARNIVORE)
        {
            for (auto j = fishs.begin(); j != fishs.end();)
            {
                fishWidget* fish = *j;
                if(fish->getType() == GUBBI)
                {
                    if (Utils::judgeOverlap(QVector2D((*item).pos()), QVector2D((*fish).pos())))
                    {
                        item->growing();
                        j = fishs.erase(j);
                        fish->deleteLater();
                    }
                    else
                    {
                        j++;
                    }
                }
            }
        }
    }
}

void GameA::addgold()
{
    for(auto item: fishs)
    {
        QRect rect = item->geometry();
        GoldWidget* gold = new GoldWidget(ui->gameView);
		gold->setPosition(rect.x() + 25, rect.y() + 34);
		gold->setScene(this);
        gold -> show();
        connect(gold, SIGNAL(gold_clicked(GoldWidget*)), this, SLOT(collectGold(GoldWidget*)));
        golds.push_back(gold);
//        gold->setGeometry(, 15, 15);
    }
}

void GameA::collectGold(GoldWidget* gptr)
{
    money += gptr->_amount;
    //gptr->hide();
    gptr->deleteLater();
    gptr = nullptr;
    qDebug() << "delete";
    update();
    ui->money->setText(QString::number(money));
}

void GameA::increaseMoney(int amt, ObjectWidget* src, const SI::SI_String &info)
{
	update();
	qDebug() << "increaseMoney start";
	money += amt;
	money = SI::Max(money, 0);
	ui->money->setText(QString::number(money));
	qDebug() << "increaseMoney done";
}

bool GameA::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type()==QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent=static_cast<QMouseEvent*>(event);
        if (mouseEvent->buttons()&Qt::LeftButton && money >= 20)
        {
            qDebug() << "food";
			ObjectWidget* food = new FoodWidget(ui->gameView);
			food->setPosition(mouseEvent->x(), mouseEvent->y());
			food->setScene(this);
            foods.push_back(food);
			food->show();
            money -= 20;
            ui->money->setText(QString::number(money));

            for (auto item: fishs)
            {
                double minDist = (double)INT_MAX;
                fishWidget* minDistFish = nullptr;
                if (!item->isHunting && item->getType() == GUBBI)
                {
                    QVector2D currDiffVec = QVector2D(item->pos() - food->pos());
                    double currDist = currDiffVec.length();
                    if (currDist < minDist)
                    {
                        minDistFish = item;
                        minDist = currDist;
                    }
                    if (minDistFish != nullptr)
                    {
                        minDistFish->hunting(QVector2D(mouseEvent->x(), mouseEvent->y()));
                    }
                    break;
                }
            }
            return true;
        }
    }
    return false;
}

void GameA::fishMove()
{
    for(auto item: fishs)
    {
        if (!item->isHunting)
        {
            item->wandering();
        }
    }
}

//carnivore
void GameA::on_pushButton_clicked()
{
    if(money < 1000)
    {
        return;
        //金钱不足
    }
    else
    {
        money -= 1000;
        QString s = QString::number(this->money, 10);
        ui->money->setText(s);

        //加入新食肉鱼
        Carnivore* carnivore = new Carnivore;
        fishWidget* newfish = new fishWidget(ui->gameView, carnivore);
        newfish->show();
        fishs.push_back(newfish);
    }
}
