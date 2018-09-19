#include "foodwidget.h"
#include <QPainter>
#include "food.h"

const SI_String settingFilePath = ":/image/settings/food.txt";

FoodWidget::FoodWidget(QWidget *parent) : ObjectWidget(parent)
{
	obj = new SI::Food(settingFilePath);
	obj->set_widget(this);
	_imgurl = obj->getProperty("img_url");
	W = obj->getProperty("width").toInt();
	H = obj->getProperty("height").toInt();
}
