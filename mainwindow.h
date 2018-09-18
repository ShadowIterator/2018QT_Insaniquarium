#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "QDebug"//控制台输出

#include "QUrl"
#include "QDesktopServices"//帮助 跳转网页
#include "gamea.h"//游戏界面
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:

private:
    Ui::MainWindow *ui;
private slots:
    void on_AModel_clicked();
    void on_help_clicked();
    void on_exit_clicked();
};

#endif // MAINWINDOW_H
