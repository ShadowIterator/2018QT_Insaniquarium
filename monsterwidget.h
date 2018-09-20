#ifndef MONSTERWIDGET_H
#define MONSTERWIDGET_H

#include <QWidget>
#include <QImage>
#include "objectwidget.h"
#include "global.h"


class MonsterWidget : public ObjectWidget
{
	Q_OBJECT
protected:

public:
	explicit MonsterWidget
	(QWidget *parent = nullptr);
//     int amount = 100);

public slots:

protected:
//    void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* ev);
};

#endif // MONSTERWIDGET_H
