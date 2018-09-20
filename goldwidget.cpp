#include "goldwidget.h"
#include <QPainter>
#include <QDebug>
#include "gamea.h"

SI::SI_String settingFilePath = ":/image/settings/gold.txt";

GoldWidget::GoldWidget
(QWidget *parent, int amount) : ObjectWidget(settingFilePath, parent), _amount(amount)
{

}

GoldWidget::GoldWidget
(const SI_String& fileName, QWidget *parent): ObjectWidget(fileName, parent)
{

}


void GoldWidget::mousePressEvent(QMouseEvent* ev)
{
	qDebug() << "gold clicked";
	if(obj->getProperty("valid") != "true")
		return ;
	obj->die("clicked");
}
