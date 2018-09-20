#include "gubbiwidget.h"
#include <QPainter>
//#include "abstract_fish.h"

const SI_String settingFilePath = ":/image/settings/gubbi.txt";

GubbiWidget::GubbiWidget(QWidget *parent) : ObjectWidget(settingFilePath, parent)
{

}
