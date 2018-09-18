#ifndef FOODWIDGET_H
#define FOODWIDGET_H

#include <QWidget>

class FoodWidget : public QWidget
{
    Q_OBJECT
protected:
    QString _imgurl;
    QImage _pic;

public:
    explicit FoodWidget
    (QWidget *parent = nullptr,
     QString url = QString(":/image/resource/food.png")
    );

signals:

public slots:

protected:
    void paintEvent(QPaintEvent* event);
};

#endif // FOODWIDGET_H
