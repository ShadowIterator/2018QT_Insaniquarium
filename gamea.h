#ifndef GAMEA_H
#define GAMEA_H

#include <QWidget>
#include <QVector>
#include "QString"
#include "fishwidget.h"
#include "fish.h"
#include <QDebug>
#include "QVBoxLayout"
#include "goldwidget.h"
#include "foodwidget.h"
//#include "objectwidget.h"

using SI::SI_Object;
using SI::SI_String;


namespace Ui {
class GameA;
}

class GameA : public QWidget
{
    Q_OBJECT

public:
    explicit GameA(QWidget *parent = 0);
    ~GameA();

    long int money;
    QVector<fishWidget*> fishs;
    QVector<GoldWidget*> golds;
//	QVector<ObjectWidget*> foods;
	QVector<ObjectWidget*> objs;
	QVector<ObjectWidget*> tmps;
	QVector<ObjectWidget*> apds;

private slots:
    void on_menu_clicked();
    void on_fish1_clicked();
    //void updatefish();
    void updateState();
    void addgold();
    void collectGold(GoldWidget* gptr);
    void fishMove();

    void on_pushButton_clicked();

signals:
	void _product(const SI_String&, int, int, SI_Object*, const SI_String&);
	void _increaseMoney(int, SI_Object*, const SI_String&);
private slots:
	void increaseMoney(int, SI_Object*, const SI_String&);
	void product(const SI_String& productName, int x, int y, SI_Object* src, const SI_String& info);
private:
    Ui::GameA *ui;
    QVBoxLayout *layout;

protected:
    //void paintEvent(QPaintEvent* event);
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // GAMEA_H
