
#include"abstract_fish.h"
#include"gamea.h"

const int WINDOW_W = 700;
const int WINDOW_H = 579;

namespace SI
{
	Fish::Fish(QObject *parent): SI_Object(parent)
	{

	}

	Fish::Fish(const Fish& tfish, QObject *parent): SI_Object(tfish)
	{
		pscene = tfish.pscene;
		P = tfish.P;
	}

	Fish::Fish(const SI_String& fileName, QObject *parent): SI_Object(parent)
	{
		qDebug() << "constructor fish";
		__initInfo(fileName);
		V.x = getProperty("V.x").toInt();
		V.y = getProperty("V.y").toInt();
	}

	void Fish::set_scene(GameA* tpscene)
	{
		pscene = tpscene;
	}

	void Fish::setPosition(DB x, DB y)
	{
		P.x = x;
		P.y = y;
	}

	void Fish::setVelocity(DB x, DB y)
	{
		qDebug() << "set Velocity";
		V.x = x;
		V.y = y;
	}

	void Fish::make_connection()
	{

	}

	void Fish::update()
	{
//		qDebug() << getProperty("type") << ": update";
		if(getProperty("hang_only") == "true")
		{
			hang(noinfo);
		}
		else
		{
			int hungry_decrease = getProperty("hungry_decrease").toInt();
			int hungry_index = getProperty("hungry_index").toInt();
			hungry_index -= hungry_decrease;
			setProperty("hungry_index", SI_String::number(hungry_index));
			if(hungry_index < getProperty("inc_speed_st").toInt())
				setProperty("speed", getProperty("inc_speed"));
			else
				setProperty("speed", getProperty("nor_speed"));
			if(hungry_index < getProperty("hunting_st"))
				hunting(noinfo);
			else
				hang(noinfo);
			grow(noinfo);
		}
		P += V;
		if(P.x < 10 || P.x > WINDOW_W - 10 || P.y < 10 || P.y > WINDOW_H - 10)
		{
			P -= V;
		}
	}

	void Fish::hunting(const SI_String &info)
	{
		SI_String foodType = getProperty("food_type");
		Point2lf foodP;
		DB mindist2 = 1e100;
		DB foodDist2;
		ObjectWidget* ptar = nullptr;
		for(auto item: pscene->objs)
		{
			if(!item->validable() || !foodType.contains(item->obj->getProperty("type")))
				continue;
			if(judgeOverlap(P, foodP))
			{
				eat(item->obj, noinfo);
				return ;
			}
			foodP = item->getPosition();
			foodDist2 = dist2(P, foodP);
			if(foodDist2 < mindist2)
			{
				mindist2 = foodDist2;
				ptar = item;
			}
		}
		V = foodP - P;
		V._reLength(getProperty("speed").toInt());
	}

	void Fish::eat(Fish* tar, const SI_String &info)
	{
		int hungry_increase = tar->getProperty("hungry_increase").toInt();
		int hungry_index = getProperty("hungry_index").toInt();
		hungry_index += hungry_increase;
		int enegy = getProperty("energy").toInt();
		enegy += hungry_increase;
		setProperty("hungry_index", SI_String::number(hungry_index));
		setProperty("enegy", SI_String::number(enegy));
		tar->die("eaten");

	}

	void Fish::hang(const SI_String &info)
	{
		int W = WINDOW_W;//pscene->Width();
		int H = WINDOW_H;//pscene->Height();
		int tx = rand() % W;
		int ty = rand() % H;
		V = Point2lf(tx, ty) - P;
		V._reLength(getProperty("speed").toInt());
	}

	void Fish::set_widget(QWidget *tpwidget)
	{
		pwidget = tpwidget;
	}

	void Fish::grow(const SI_String &info)
	{
		SI_String sgrowEnergy = getProperty("grow_energy");
		if(sgrowEnergy == "Impossible")
			return ;
		int igrowEnergy = sgrowEnergy.toInt();
		if(getProperty("grow_st").toInt() < igrowEnergy)
			emit pscene->_product(getProperty("next_stage"), P.x, P.y, this, noinfo);
		die("grow");
	}

	void Fish::product(const SI_String &info)
	{
		emit pscene->_product(getProperty("product"), P.x, P.y, this, noinfo);
	}

	void Fish::die(const SI_String &info)
	{
		pwidget->deleteLater();
	}

}
