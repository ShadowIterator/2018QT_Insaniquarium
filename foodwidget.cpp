#include "foodwidget.h"
#include <QPainter>

const SI_String settingFilePath = ":/image/settings/food.txt";

FoodWidget::FoodWidget(QWidget *parent) : ObjectWidget(settingFilePath, parent)
{

}
