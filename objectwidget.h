#ifndef OBJECTWIDGET_H
#define OBJECTWIDGET_H

#include <QWidget>
#include "global.h"
#include "abstract_fish.h"
#include "si_geometry.hpp"

using SI::Point2lf;
using SI::SI_String;
using SI::DB;

class ObjectWidget : public QWidget
{
	Q_OBJECT
public:
	QString _imgurl;
	QImage _pic;
	SI::Fish* obj;
	DB W;
	DB H;
public:
	explicit ObjectWidget
	(const SI::SI_String& fileName,
	QWidget *parent = 0);
	explicit ObjectWidget
	(QWidget *parent = 0);

	virtual void setPosition(DB x, DB y);
	virtual void setScene(GameA* pscene);
	bool validable();
	Point2lf getPosition();
signals:

public slots:

public:
	virtual void update();
	virtual void paintEvent(QPaintEvent* event);
	virtual void mousePressEvent(QMouseEvent* ev);
};

#endif // OBJECTWIDGET_H
