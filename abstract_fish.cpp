
#include"abstract_fish.h"

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
		__initInfo(fileName);
		setProperty("hungry_index", "10000");
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
		V.x = x;
		V.y = y;
	}

	void Fish::make_connection()
	{

	}

	void Fish::update(const SI_String &info)
	{
		int hungry_decrease = getProperty("hungry_decrease").toInt();
		int hungry_index = getProperty("hungry_index").toInt();
		hungry_index -= hungry_decrease;

	}

	void Fish::hunting(const SI_String &info)
	{

	}

	void Fish::hang(const SI_String &info)
	{

	}

	void Fish::grow(const SI_String &info)
	{

	}

	void Fish::product(const SI_String &info)
	{

	}

	void Fish::die(const SI_String &info)
	{

	}

}