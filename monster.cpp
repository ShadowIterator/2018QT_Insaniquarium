
#include "monster.h"
#include "gamea.h"

namespace SI
{


	Monster::Monster(const SI_String& fileName, QObject *parent): Fish(parent)
	{
	//		qDebug() << "constructor fish";
		__initInfo(fileName);
		prodCounter = 0;
		V.x = getProperty("V.x").toInt();
		V.y = getProperty("V.y").toInt();
//		HP = getProperty("hp").toInt();
//		clkCount = 0;
	}

	void Monster::hunting(const SI_String &info)
	{
		int HP = getProperty("hp").toInt();
		int clkCount = getProperty("clk_count").toInt();
		if(HP <= 0)
		{
			die("no HP");
			emit pscene->_product(getProperty("award"), P.x, P.y, this, noinfo);
//			emit pscene->_product("")
		}
		if(clkCount > 0)
		{
			--clkCount;
			setProperty("clk_count", SI_String::number(clkCount));
			return ;
		}
		Fish::hunting(info);
//		SI_String foodType = getProperty("food_type");
//		Point2lf foodP;
//		DB mindist2 = 1e100;
//		DB foodDist2;
//		ObjectWidget* ptar = nullptr;
//		for(auto item: pscene->objs)
//		{
//			qDebug() << item->obj->getProperty("type");
//			if(!item->validable() || !foodType.contains(item->obj->getProperty("type")))
//				continue;
//			foodP = item->getPosition();
//			if(judgeOverlap(P, foodP))
//			{
//				eat(item->obj, noinfo);
//				return ;
//			}
//			foodDist2 = dist2(P, foodP);
//			if(foodDist2 < mindist2)
//			{
//				mindist2 = foodDist2;
//				ptar = item;
//			}
//		}
//		if(ptar != nullptr)
//		{
//			V = foodP - P;
//			V._reLength(getProperty("speed").toInt());
//		}
//		else
//			hang(noinfo);
	}
}
