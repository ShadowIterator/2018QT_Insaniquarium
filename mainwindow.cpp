#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置标题
    this->setWindowTitle("怪怪水族馆");
}


MainWindow::~MainWindow()
{
    delete ui;
}

//a模式
void MainWindow::on_AModel_clicked()
{
    GameA * game = new GameA();
    game->show();
}


//帮助
void MainWindow::on_help_clicked()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("https://www.baidu.com/link?url=NEEGvxx3a2tCpvwQ-9LCFbxUpZBLlU6AnOrnK_Zo6bGfmOZShZ2FWD9s8mBl-tgwoCkrZuFRWmeoJvvSfk_SC9PoxHs349Sfneftvw2iL_ExQuN1eCRUiofW0IuJfvgTYtrMQIob_3itU4KXPsNqSq&wd=&eqid=acdaace40000abf1000000065b956a6b")));
}

void MainWindow::on_exit_clicked()
{
    qApp->quit();
}
