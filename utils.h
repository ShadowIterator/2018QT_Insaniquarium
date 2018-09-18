#ifndef UTILS_H
#define UTILS_H
#include <QVector2D>
#include <QTime>

class Utils
{
public:
    static void prepRandom();
    static int genRandom(int lowBound = 0, int highBound = 10);
    static bool judgeOverlap(QVector2D pos1, QVector2D pos2);
    static QVector2D genVec(double len, QVector2D startVec, QVector2D endVec);
    static QVector2D genVec(double len, double ang);
};

#endif // UTILS_H
