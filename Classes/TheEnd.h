#pragma once

#include "cocos2d.h"
#include "HelloWorldScene.h"
using namespace cocos2d;
using namespace std;

class TheEnd : public Scene
{
public:
    static Scene* createScene();
    virtual bool init();


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

    unsigned int score;
    Label* scoreLabel;
    LayerColor* leyer;
    CREATE_FUNC(TheEnd);
};


