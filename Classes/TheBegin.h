#pragma once

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "sloymenu.h"

using namespace cocos2d;
using namespace std;

class TheBegin : public Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	Label* scoreLabel;
	LayerColor* leyer;

	CREATE_FUNC(TheBegin);
};
