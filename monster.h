#ifndef MONSTER_H
#define MONSTER_H

#include "global.h"
#include "abstract_fish.h"

namespace SI
{
	class Monster: public Fish
	{
	public:
//		int HP;
//		int clkCount;
	public:
		Monster(const SI_String& fileName, QObject *parent = 0);

		virtual void hunting(const SI_String &info);
	};
}
#endif // MONSTER_H
