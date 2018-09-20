#include "monsterwidget.h"
#include "monster.h"
#include <QPainter>
#include <QDebug>
#include "gamea.h"
#include <QMouseEvent>

SI::SI_String settingFilePath_monster = ":/image/settings/monster.txt";

MonsterWidget::MonsterWidget
(QWidget *parent):  ObjectWidget(parent)
{
	obj = new SI::Monster(settingFilePath_monster);
	obj->set_widget(this);
	_imgurl = obj->getProperty("img_url");
	W = obj->getProperty("width").toInt();
	H = obj->getProperty("height").toInt();
}


void MonsterWidget::mousePressEvent(QMouseEvent* ev)
{
	qDebug() << "gold clicked";
	if(obj->getProperty("valid") != "true")
		return ;
	if(obj->getProperty("clk_count") != "0")
		return ;
	DB midx = obj->getProperty("width").toInt()/2;
	qDebug() << ev->x();
	if(ev->x() < midx)
		obj->setVelocity(obj->getProperty("inc_speed").toInt(), 0);
	else
		obj->setVelocity(-obj->getProperty("inc_speed").toInt(), 0);
//	obj->HP -= obj->getProperty("hp_decrease");
	int hp = obj->getProperty("hp").toInt();
	obj->setProperty("hp", SI_String::number(hp - obj->getProperty("hp_decrease").toInt()));
//	obj->clkCount = obj->getProperty("panic_tim").toInt();
	obj->setProperty("clk_count", obj->getProperty("panic_tim"));
//	obj->die("clicked");
}
