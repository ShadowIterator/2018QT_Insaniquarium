#include "gamea.h"
#include "ui_gamea.h"
#include "QHBoxLayout"
#include <QEvent>
#include <QMouseEvent>
#include "utils.h"
#include "si_geometry.hpp"
#include "objectwidget.h"
#include "gubbiwidget.h"
#include "diamondwidget.h"
#include "carnivorewidget.h"
#include "supercarnivore.h"

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
	timer->start(10);

    //fishmove
//    QTimer *timer3 = new QTimer(this);
//    connect(timer3,SIGNAL(timeout()),this,SLOT(fishMove()));
//    timer3->start(500);

    //gold
//    QTimer *timer2 = new QTimer(this);
//    connect(timer2,SIGNAL(timeout()),this,SLOT(addgold()));
//	timer2->start(1000);

    ui->gameView->installEventFilter(this);

	connect(this, SIGNAL(_increaseMoney(int, SI_Object*, const SI_String&)), this, SLOT(increaseMoney(int, SI_Object*, const SI_String&)));
	connect(this, SIGNAL(_product(SI_String,int,int,SI_Object*,SI_String)), this, SLOT(product(SI_String,int,int,SI_Object*,SI_String)));

//	emit _product("gold", 400, 400, nullptr, SI::noinfo);
//	emit _product("gold", 200, 100, nullptr, SI::noinfo);
//	emit _product("gubbi", 300, 300, nullptr, SI::noinfo);
//	emit _product("silver", 100, 100, nullptr, SI::noinfo);
//	emit _product("gold", 300, 300, nullptr, SI::noinfo);
//	emit _product("gubbi", 300, 300, nullptr, SI::noinfo);
	emit _product("middlegubbi", 400, 300, nullptr, SI::noinfo);
//	emit _product("supergubbi", 300, 300, nullptr, SI::noinfo);
//	emit _product("carnivore", 300, 300, nullptr, SI::noinfo);
//	emit _product("supercarnivore", 300, 300, nullptr, SI::noinfo);
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
//		Gubbi* gubbi = new Gubbi;
//		fishWidget* newfish = new fishWidget(ui->gameView, gubbi);
//		newfish->show();
//		fishs.push_back(newfish);
		emit _product("gubbi", 30, 30, nullptr, SI::noinfo);
    }
}

void GameA::updateState()
{
	tmps.clear();
//	qDebug() << "upd state " << objs.length();
	for(auto item: objs)
	{
//		qDebug() << "update: "<< item->obj->getProperty("type");
		item->update();
		if(item->obj->getProperty("valid") == "true")
			tmps.push_back(item);
	}
	update();
	objs.clear();
	for(auto item: tmps)
	{
		objs.push_back(item);
	}
	for(auto item: apds)
	{
		objs.push_back(item);
	}
	apds.clear();
//    for (auto item: fishs)
//    {
//        item->updatefish();
//        item->update();
//        if(item->getType() == GUBBI)
//        {
//			for (auto i = objs.begin(); i != objs.end(); )
//            {
//				ObjectWidget* food = *i;
//                if (Utils::judgeOverlap(QVector2D((*item).pos()), QVector2D((*food).pos())))
//                {
//                    item->growing();
//					i = objs.erase(i);
//                    food->deleteLater();
//                }
//                else
//                {
//                    i++;
//                }
//            }
//        }

//        if(item->getType() == CARNIVORE)
//        {
//            for (auto j = fishs.begin(); j != fishs.end();)
//            {
//                fishWidget* fish = *j;
//                if(fish->getType() == GUBBI)
//                {
//                    if (Utils::judgeOverlap(QVector2D((*item).pos()), QVector2D((*fish).pos())))
//                    {
//                        item->growing();
//                        j = fishs.erase(j);
//                        fish->deleteLater();
//                    }
//                    else
//                    {
//                        j++;
//                    }
//                }
//            }
//        }
//    }
}

void GameA::addgold()
{
	qDebug() << fishs.length();
    for(auto item: fishs)
    {
        QRect rect = item->geometry();
//		ObjectWidget* gold = new GoldWidget(ui->gameView);
//		gold->setPosition(rect.x() + 25, rect.y() + 34);
//		gold->setScene(this);
//		gold -> show();

		emit _product("gold", rect.x() + 25, rect.y() + 34, nullptr, SI::noinfo);


//        connect(gold, SIGNAL(gold_clicked(GoldWidget*)), this, SLOT(collectGold(GoldWidget*)));
//        golds.push_back(gold);
//        gold->setGeometry(, 15, 15);
    }
}

void GameA::collectGold(GoldWidget* gptr)
{
//	qDebug() << "collect gold";
//    money += gptr->_amount;
//    //gptr->hide();
//    gptr->deleteLater();
//    gptr = nullptr;
//    qDebug() << "delete";
//    update();
//    ui->money->setText(QString::number(money));
}

void GameA::increaseMoney(int amt, SI_Object* src, const SI::SI_String &info)
{
	update();
	qDebug() << "increaseMoney start";
	money += amt;
	money = SI::Max(money, 0);
	ui->money->setText(QString::number(money));
	qDebug() << "increaseMoney done";
}

void GameA::product(const SI::SI_String &productName, int x, int y, SI::SI_Object *src, const SI::SI_String &info)
{
//	SI_String productFilePath = ":/image/settings/" + productName;
	qDebug() << productName << ": " << x << " " << y;
	ObjectWidget* pobj = nullptr;
	if(productName == "food")
	{
		pobj = new FoodWidget(ui->gameView);
	}
	else if(productName == "gubbi")
	{
		pobj = new GubbiWidget(ui->gameView);
	}
	else if(productName == "gold")
	{
		pobj = new GoldWidget(ui->gameView);
	}
	else if(productName == "diamond")
	{
		pobj = new DiamondWidget(ui->gameView);
	}
	else if(productName == "carnivore")
	{
		pobj = new CarnivoreWidget(ui->gameView);
	}
	else if(productName == "supercarnivore")
	{
		pobj = new SuperCarnivoreWidget(ui->gameView);
	}
	else if(productName == "middlegubbi")
	{
		pobj = new ObjectWidget(":/image/settings/middlegubbi.txt", ui->gameView);
	}
	else if(productName == "supergubbi")
	{
		pobj = new ObjectWidget(":/image/settings/supergubbi.txt", ui->gameView);
	}
	else if(productName == "kinggubbi")
	{
		pobj = new ObjectWidget(":/image/settings/kinggubbi.txt", ui->gameView);
	}
	else if(productName == "silver")
	{
		pobj = new GoldWidget(":/image/settings/silver.txt", ui->gameView);
	}

	if(!pobj)
		return ;

	pobj->setPosition(x, y);
	pobj->setScene(this);
	pobj->show();
	apds.push_back(pobj);
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
			objs.push_back(food);
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
