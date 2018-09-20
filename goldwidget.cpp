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

//void GoldWidget::paintEvent(QPaintEvent *event)
//{
////    QPainter p(this);
////    p.setRenderHint(QPainter::Antialiasing, true);
////    p.save();

////    //widget长宽比和图片长宽比
////    double fr = (static_cast<double>(width()))/(static_cast<double>(height()));
////    double pr = 60.0 / 58.0;
////    _pic.load(_imgurl);

////    //自适应widget边框大小
////    double h, w;
////    if (fr > pr)
////    {
////        h = height();
////        w = pr * h;
////        p.translate((width() - w) / 2, 0);
////        _pic.scaled(QSize(w, h) ,Qt::KeepAspectRatio);
////        p.drawPixmap(0, 0, w, h, QPixmap::fromImage(_pic));
////    }
////    else
////    {
////        w = width();
////        h = w / pr;
////        p.translate(0, (height() - h) / 2);
////        _pic.scaled(QSize(w, h) ,Qt::KeepAspectRatio);
////        p.drawPixmap(0, 0, w, h, QPixmap::fromImage(_pic));
////    }
////    p.restore();
//}

void GoldWidget::mousePressEvent(QMouseEvent* ev)
{
//    emit gold_clicked(this);
	qDebug() << "gold clicked";
	if(obj->getProperty("valid") != "true")
		return ;
	obj->setProperty("valid", "false");
	this->hide();
//	this->deleteLater();
	qDebug() << "gold clicked start emit";
//	qDebug() << "gold clicked pscene" << obj->pscene;
	emit obj->pscene->_increaseMoney(obj->getProperty("money_increase").toInt(), this, SI::noinfo);
	qDebug() << "gold clicked emit done";
}
