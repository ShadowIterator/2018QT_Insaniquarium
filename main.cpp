#include "mainwindow.h"
#include <QSplashScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/image/resource/aquarium1.jpg"));
    splash->show();
    a.processEvents();

    MainWindow w;
    w.show();

    splash->finish(&w);
    delete splash;
    return a.exec();
}
