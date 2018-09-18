#include "fishwidget.h"
#include <QPainter>
//#include "ui_fishwidget.h"

fishWidget::fishWidget(QWidget *parent, Fish* f) :
    QWidget(parent),
    _fish(f)
{

}

fishWidget::~fishWidget()
{

}

void fishWidget::updatefish()
{
    _fish->refresh();
    QRect rect = this->geometry();
    int x = static_cast<int>(_fish->getPosition().x());
    int y = static_cast<int>(_fish->getPosition().y());
    int w = rect.width();
    int h = rect.height();
    this->setGeometry(x, y, w, h);
}

void fishWidget::hunting(QVector2D preyPos)
{
    HUNT_RESULT hr = _fish->hunt(preyPos);
    switch(hr)
    {
    case CHASING:
        isHunting = true;
        break;
    default:
        isHunting = false;
        break;
    }

    updatefish();
}

void fishWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.save();

    double fr;
    fr = (static_cast<double>(width()))/(static_cast<double>(height()));
    double pr = 39.0 / 34.0;
    _pic.load(_fish->getImgUrl());

    //自适应widget大小
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

void fishWidget::wandering()
{
    _fish->wander();
    this->update();
}

void fishWidget::growing()
{
    _fish->grow();
    isHunting = false;
}

FISH_TYPE fishWidget::getType()
{
    return _fish->getType();
}
