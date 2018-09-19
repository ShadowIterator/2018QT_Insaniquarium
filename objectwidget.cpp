#include "objectwidget.h"
#include <QPainter>

ObjectWidget::ObjectWidget(const SI_String& fileName, QWidget *parent) : QWidget(parent)
{
//	resize(300, 300);
	obj = new SI::Fish(fileName);
	_imgurl = obj->getProperty("img_url");
	W = obj->getProperty("width").toInt();
	H = obj->getProperty("height").toInt();
}

void ObjectWidget::setScene(GameA *pscene)
{
	obj->set_scene(pscene);
}

void ObjectWidget::setPosition(SI::DB x, SI::DB y)
{
	obj->setPosition(x, y);
}

void ObjectWidget::paintEvent(QPaintEvent *event)
{
//	qDebug() << "objectwidget paintEvent start";
	DB x = obj->P.x;
	DB y = obj->P.y;
	setGeometry(x, y, W, H);
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing, true);
	p.save();

	//widget长宽比和图片长宽比
	double fr = (static_cast<double>(W))/(static_cast<double>(H));
	double pr = 60.0 / 58.0;
	_pic.load(_imgurl);

//	qDebug() << width() << ' ' << height();
	//自适应widget边框大小
	double h, w;
	if (fr > pr)
	{
		h = height();
		w = pr * h;
		p.translate((width() - w) / 2, 0);
		_pic.scaled(QSize(w, h) ,Qt::KeepAspectRatio);
		p.drawPixmap(0, 0, w, h, QPixmap::fromImage(_pic));
	}
	else
	{
		w = width();
		h = w / pr;
		p.translate(0, (height() - h) / 2);
		_pic.scaled(QSize(w, h) ,Qt::KeepAspectRatio);
		p.drawPixmap(0, 0, w, h, QPixmap::fromImage(_pic));
	}
	p.restore();
}

void ObjectWidget::mousePressEvent(QMouseEvent *ev)
{

}
