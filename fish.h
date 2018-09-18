#ifndef FISH_H
#define FISH_H
#include <QVector2D>
#include <QString>

enum FISH_TYPE
{
    GUBBI, CARNIVORE
};

enum GUBBI_TYPE
{
    SMALL, MEDIUM, LARGE
};

enum STATE
{
    NORMAL, HUNGRY, MORTAL
};

enum HUNT_RESULT
{
    ACQUIRE, CHASING, DISIMPASSIONED
};

//鱼的基类
class Fish
{
protected:
    FISH_TYPE _type;
    STATE _state;
    int _health;
    QVector2D _position;
    QString _ImgUrl;
    QVector2D _speed;

public:
    //接口
    FISH_TYPE getType() { return _type; }
    void setType(FISH_TYPE ft) { _type = ft; }

    STATE getState() { return _state; }
    void setState(STATE st)
    {
        if ((st >= NORMAL) && (st <= MORTAL)) _state = st;
    }

    int getHealth() { return _health; }
    void setHealth(int hp) { _health = hp; }

    QVector2D getSpeed() { return _speed; }
    void setSpeed(QVector2D sp) { _speed = sp; }

    QVector2D getPosition() { return _position; }
    void setPosition(QVector2D pos) { _position = pos; }

    //鱼的图片
    QString getImgUrl()
    {
        return _ImgUrl;
    }

    void setImgUrl(QString url)
    {
        _ImgUrl = url;
    }

    //constuctor
    Fish(STATE st = NORMAL): _state(st){}

    //模拟鱼的动作
    virtual void wander() = 0;
    virtual void grow() = 0;
    virtual void eat() = 0;
    virtual void swim(QVector2D pos) = 0;
    virtual HUNT_RESULT hunt(QVector2D pos) = 0;
    virtual void refresh() = 0;
    virtual int produceGold() = 0;
};

//Gubbi fish
class Gubbi: public Fish
{
private:
    GUBBI_TYPE _gtype;

public:
    Gubbi(STATE st = NORMAL);
    GUBBI_TYPE getGType() { return _gtype; }
    void setGType(GUBBI_TYPE gt) { _gtype = gt; }

    void wander();
    void grow();
    void swim(QVector2D pos);
    void eat();
    HUNT_RESULT hunt(QVector2D pos);
    void refresh();
    int produceGold();
};

class Carnivore:public Fish
{
private:
public:
    Carnivore(STATE st = NORMAL);
    void wander();
    void grow();
    void swim(QVector2D pos);
    void eat();
    HUNT_RESULT hunt(QVector2D pos);
    void refresh();
    int produceGold();
};

#endif // FISH_H

