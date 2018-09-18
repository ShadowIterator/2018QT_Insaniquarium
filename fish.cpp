#include "fish.h"
#include "utils.h"

Gubbi::Gubbi(STATE st): Fish(st), _gtype(SMALL)
{
    setHealth(5000);
    Utils::prepRandom();
    int curX = Utils::genRandom(100, 600);
    int curY = Utils::genRandom(100, 400);
    setPosition(QVector2D(curX, curY));
    setImgUrl(QString(":/image/resource/fish1.png"));
    setType(GUBBI);
    setSpeed(QVector2D(0.6, 0.8));
}

Carnivore::Carnivore(STATE st):Fish(st)
{
    setHealth(5000);
    Utils::prepRandom();
    int curX = Utils::genRandom(100, 600);
    int curY = Utils::genRandom(100, 400);
    setPosition(QVector2D(curX, curY));
    setImgUrl(QString(":/image/resource/carnivore.png"));
    setType(CARNIVORE);
    setSpeed(QVector2D(0.6, 0.8));
}

void Gubbi::wander()
{
    int rand = Utils::genRandom(1,360);
    double temp_angle = 2 * 3.14159265 * (rand % 360) / 360;
    double final_x = 1.0 * cos(temp_angle);
    double final_y = 1.0 * sin(temp_angle);
    setSpeed(QVector2D(final_x, final_y));
}

void Carnivore::wander()
{
    int rand = Utils::genRandom(1,360);
    double temp_angle = 2 * 3.14159265 * (rand % 360) / 360;
    double final_x = 1.0 * cos(temp_angle);
    double final_y = 1.0 * sin(temp_angle);
    setSpeed(QVector2D(final_x, final_y));
}

void Gubbi::refresh()
{
    //健康状况
    setHealth(getHealth() - 1);
    STATE s = getState();
    if (getHealth() > 1000)
    {
        if(s != NORMAL)
        {
            setState(NORMAL);
            setSpeed(QVector2D(0.6, 0.8));
            setImgUrl(QString(":/image/resource/fish1.png"));
        }
    }
    if (getHealth() < 1000)
    {
        if(s != HUNGRY)
        {
             setState(HUNGRY);
             setSpeed(QVector2D(0.84, 1.13));
             setImgUrl(QString(":/image/resource/hungrygubbi.png"));
        }
    }
    if (getHealth() <= 0)
    {
        if(s != MORTAL)
        {
             setState(MORTAL);
             setSpeed(QVector2D(0, 0));
             setImgUrl(QString(":/image/resource/deadgubbi.png"));
        }
    }

    //位置更新
    setPosition(getPosition() + getSpeed());
    //防止越界
    double x = getPosition().x();
    double y = getPosition().y();
    if (x < 5)
    {
        x = 5;
    }

    if (y < 8)
    {
        y = 8;
    }

    if (x > 700)
    {
        x = 700;
    }

    if (y > 500)
    {
        y = 500;
    }
    this->setPosition(QVector2D(x, y));
}

void Carnivore::refresh()
{
    setHealth(getHealth() - 1);
    STATE s = getState();
    if (getHealth() > 1000)
    {
        if(s != NORMAL)
        {
            setState(NORMAL);
            setSpeed(QVector2D(0.6, 0.8));
            setImgUrl(QString(":/image/resource/fish1.png"));
        }
    }
    if (getHealth() < 1000)
    {
        if(s != NORMAL)
        {
             setState(HUNGRY);
             setSpeed(QVector2D(0.84, 1.13));
        }
    }
    if (getHealth() <= 0)
    {
        if(s != NORMAL)
        {
             setState(MORTAL);
             setSpeed(QVector2D(0, 0));
        }
    }

    //位置更新
    setPosition(getPosition() + getSpeed());
    //防止越界
    double x = getPosition().x();
    double y = getPosition().y();
    if (x < 5)
    {
        x = 5;
    }

    if (y < 8)
    {
        y = 8;
    }

    if (x > 700)
    {
        x = 700;
    }

    if (y > 500)
    {
        y = 500;
    }
    this->setPosition(QVector2D(x, y));
}

void Gubbi::swim(QVector2D pos)
{
    QVector2D directionVec = Utils::genVec(1.0, getPosition(), pos);
    setSpeed(directionVec);
    if (directionVec.x() > 0)
    {
       setImgUrl(QString(":/image/resource/fish2.png"));
    }
    else
    {
       setImgUrl(QString(":/image/resource/fish1.png"));
    }
}

void Carnivore::swim(QVector2D pos)
{
    QVector2D directionVec = Utils::genVec(1.0, getPosition(), pos);
    setSpeed(directionVec);
}

void Gubbi::grow()
{
    int health = getHealth();
    health += 5;
    if (health >= 5030)
    {
        setGType(MEDIUM);
    }
    if (health >= 5050)
    {
        setGType(LARGE);
    }
}

void Carnivore::grow()
{}

HUNT_RESULT Gubbi::hunt(QVector2D pos)
{
    if (Utils::judgeOverlap(getPosition(), pos))
    {
        grow();
        return ACQUIRE;
    }

    else
    {
        swim(pos);
        return CHASING;
    }
    return DISIMPASSIONED;
}

HUNT_RESULT Carnivore::hunt(QVector2D pos)
{
    if (Utils::judgeOverlap(getPosition(), pos))
    {
        grow();
        return ACQUIRE;
    }

    else
    {
        swim(pos);
        return CHASING;
    }
    return DISIMPASSIONED;
}

int Gubbi::produceGold()
{
    switch (_gtype)
    {
    case SMALL:
        return 0;
        break;
    case MEDIUM:
        return 15;
        break;
    case LARGE:
        return 35;
        break;
    default:
        return 0;
        break;
    }
}

int Carnivore::produceGold()
{
    return 200;
}

void Gubbi::eat()
{}
void Carnivore::eat()
{}
