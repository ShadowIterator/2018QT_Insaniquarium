#include "goldwidget.h"
#include <QPainter>
#include <QDebug>

GoldWidget::GoldWidget
(QWidget *parent, QString url, int amount) : QWidget(parent), _imgurl(url), _amount(amount)
{

}

void GoldWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.save();

    //widget长宽比和图片长宽比
    double fr = (static_cast<double>(width()))/(static_cast<double>(height()));
    double pr = 60.0 / 58.0;
    _pic.load(_imgurl);

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

void GoldWidget::mousePressEvent(QMouseEvent* ev)
{
    emit gold_clicked(this);
    qDebug() << "clicked";
}
