#include"si_object.h"


namespace SI
{
	SI_Object::SI_Object(QObject* parent):QObject(parent)
	{
		properties.clear();
//		connect(this,SIGNAL(adjustProperty_(SI_String, SI_String, SI_String, SI_Object*, SI_String)),
//				this,SLOT(_adjustProperty_(SI_String, SI_String, SI_String, SI_Object*, SI_String)));
	}

	bool SI_Object::__initInfo(const SI_String& fileName)
	{
//		SI_String cardName=getProperty("name");
		QFile fobj;
		QTextStream objin;
//		SI_String cardPath,temp;
		SI_String temp;
//		cardPath=game->cardDir;
//		cardPath=cardPath+__tofileName(cardName)+".txt";
		fobj.setFileName(fileName);
		if(!fobj.open(QIODevice::ReadOnly))
		{
			qDebug()<<"open card file "<<fileName<<" failed"<<endl;
			return false;
		}
		objin.setDevice(&fobj);
		__inputQString(objin,temp);
		__readInfo(objin);
		fobj.close();
		return true;
	}

	void SI_Object::__readInfo(QTextStream &in)
	{
//		string temp;
		SI_String propertyName;
		SI_String propertyVal;

		__inputQString(in, propertyName);
		while(propertyName != "}")
		{
			__inputQString(in,propertyVal);
			setProperty(propertyName,propertyVal);
//			setProperty("ori_"+propertyName,propertyVal);
			__inputQString(in,propertyName);
		}

	}

	SI_Object::SI_Object(const SI_String& fileName, QObject* parent):QObject(parent)
	{

	}

	SI_Object::SI_Object(const SI_Object& tobj)
	{
		if(this!=&tobj)
		{
			properties = tobj.properties;
		}
	}

	void SI_Object::_adjustProperty_(SI_String propertyName, SI_String oriVal, SI_String tarVal, SI_Object *psrc, SI_String info)
	{

	}

	SI_String SI_Object::getProperty(const SI_String& propertyName) const
	{
		QMap<SI_String,SI_String>::const_iterator it=properties.find(propertyName);
		if(it == properties.end()) return "NoResult";
		return it.value();
	}

	QMap<SI_String,SI_String>::iterator SI_Object::getBegin()
	{
		QMap<SI_String,SI_String>::iterator it = properties.begin();
		return it;
	}

	QMap<SI_String,SI_String>::iterator SI_Object::getEnd()
	{
		return properties.end();
	}

	void SI_Object::setProperty(const SI_String& propertyName, const SI_String& propertyVal)
	{
		properties.insert(propertyName, propertyVal);
	}

}

