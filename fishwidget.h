#ifndef FISHWIDGET_H
#define FISHWIDGET_H

#include <QWidget>
#include <QTimer>
#include "fish.h"
#include <QImage>

class fishWidget : public QWidget
{
    Q_OBJECT

private:
    Fish* _fish;
    QImage _pic;

public:
    bool isHunting = false;
    explicit fishWidget(QWidget *parent, Fish* f);
    ~fishWidget();

public slots:
    void hunting(QVector2D preyPos);
    void updatefish();
    int getGoldAmount()
    {
        return _fish->produceGold();
    }
    void wandering();
    void growing();
    FISH_TYPE getType();

protected:
    void paintEvent(QPaintEvent* event);

};

#endif // FISHWIDGET_H
