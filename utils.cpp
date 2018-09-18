#include "utils.h"

void Utils::prepRandom()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

int Utils::genRandom(int lowBound, int highBound)
{
    return ((qrand() % (highBound - lowBound)) + lowBound);
}

bool Utils::judgeOverlap(QVector2D pos1, QVector2D pos2)
{
    if (pos1.x() - pos2.x() > 5) return false;
    if (pos1.y() - pos2.y() > 5) return false;
    return true;
}

QVector2D Utils::genVec(double len, double ang)
{
    int incx = len * cos(ang);
    int incy = len * sin(ang);
    return QVector2D(incx, incy);
}

QVector2D Utils::genVec(double len, QVector2D startVec, QVector2D endVec)
{
    if (startVec == endVec)
    {
        return QVector2D(0, 0);
    }

    QVector2D diff = endVec - startVec;
    double diffLen = diff.length();

    return diff * len / diffLen;
}
