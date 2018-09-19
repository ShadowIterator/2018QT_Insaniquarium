#ifndef FOOD_H
#define FOOD_H

#include "abstract_fish.h"
//#include "global.h"

namespace SI {

	class Food: public Fish
	{
	public:
		virtual void hang(const SI_String &info);
		Food(const SI_String& fileName, QObject *parent = 0);

	};

}

#endif // FOOD_H
