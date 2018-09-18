#ifndef GOLDWIDGET_H
#define GOLDWIDGET_H

#include <QWidget>
#include <QImage>

class GoldWidget : public QWidget
{
    Q_OBJECT
protected:
    QString _imgurl;
    QImage _pic;

public:
    int _amount;
    explicit GoldWidget
    (QWidget *parent = nullptr,
     QString url = QString(":/image/resource/gold.png"),
     int amount = 100);

signals:
    void gold_clicked(GoldWidget* gptr);

public slots:

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* ev);
};

#endif // GOLDWIDGET_H
