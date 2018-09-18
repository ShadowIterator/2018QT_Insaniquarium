#ifndef OBJECTWIDGET_H
#define OBJECTWIDGET_H

#include <QWidget>
#include "global.h"
#include "abstract_fish.h"


using SI::SI_String;
class ObjectWidget : public QWidget
{
	Q_OBJECT
protected:
	QString _imgurl;
	QImage _pic;
	SI::Fish* obj;
public:
	explicit ObjectWidget
	(const SI::SI_String& fileName,
	QWidget *parent = 0);

signals:

public slots:

protected:
	void paintEvent(QPaintEvent* event);
};

#endif // OBJECTWIDGET_H
