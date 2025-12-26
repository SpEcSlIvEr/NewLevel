#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class sloy : public Layer
{
	public:
	static Layer* createLayer();
	virtual bool init();

	Size visibleSize = Director::getInstance()->getVisibleSize(); 
	Vec2 origin = Director::getInstance()->getVisibleOrigin(); 

	CREATE_FUNC(sloy);
};

