#ifndef GOLDWIDGET_H
#define GOLDWIDGET_H

#include <QWidget>
#include <QImage>
#include "objectwidget.h"
#include "global.h"


class GoldWidget : public ObjectWidget
{
    Q_OBJECT
protected:

public:
    int _amount;
    explicit GoldWidget
	(QWidget *parent = nullptr, int amount = 100);
//     int amount = 100);

signals:
    void gold_clicked(GoldWidget* gptr);

public slots:

protected:
//    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* ev);
};

#endif // GOLDWIDGET_H
