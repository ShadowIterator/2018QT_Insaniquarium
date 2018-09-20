#include "carnivorewidget.h"

const SI_String settingFilePath_carnivore = ":/image/settings/carnivore.txt";

CarnivoreWidget::CarnivoreWidget(QWidget* parent)
	: ObjectWidget(settingFilePath_carnivore, parent)
{

}
