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
		Vector2lf V;
		GameA* pscene;
		QWidget* pwidget;
		Point2lf tarP;
		int prodCounter;
	public:
		Fish(QObject* parent = 0);
		Fish(const Fish& tfish, QObject *parent = 0);
		Fish(const SI_String& fileName, QObject *parent = 0);

		void set_scene(GameA* tpscene);
		void set_widget(QWidget* tpwidget);
		void make_connection();
		void setPosition(DB x, DB y);
		void setVelocity(DB x, DB y);
	signals:
	public slots:
		virtual void update();
		virtual void hunting(const SI_String &info);
		virtual void hang(const SI_String &info);
		virtual void grow(const SI_String &info);
		virtual void product(const SI_String &info);
		virtual void die(const SI_String &info);
		virtual void eat(Fish* tar, const SI_String &info);
	};



}

#endif // ABSTRACT_FISH_H
