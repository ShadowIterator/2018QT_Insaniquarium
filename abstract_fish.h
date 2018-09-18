#ifndef ABSTRACT_FISH_H
#define ABSTRACT_FISH_H

#include "global.h"
#include "si_object.h"
#include "si_geometry.hpp"

namespace SI
{

	class Fish:public SI_Object
	{
	public:
		Point2lf P;
		GameA* pscene;
	public:
		Fish(QObject* parent = 0);
		Fish(const Fish& tfish, QObject *parent = 0);
		Fish(const SI_String& fileName, QObject *parent = 0);

		void set_scene(GameA* tpscene);
		void make_connection();
	signals:
	public slots:
		void update(const SI_String &info);
		void hunting(const SI_String &info);
		void hang(const SI_String &info);
		void grow(const SI_String &info);
		void product(const SI_String &info);
		void die(const SI_String &info);
	};



}

#endif // ABSTRACT_FISH_H
