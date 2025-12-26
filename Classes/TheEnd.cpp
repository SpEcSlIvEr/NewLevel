#include "TheEnd.h"

Scene* TheEnd::createScene()
{
	auto scene = create();
  auto layer = LayerColor::create(Color4B(255, 64, 0, 64));
  scene->leyer = layer;
  scene->addChild(layer, -2);
	return scene;
}

bool TheEnd::init()
{
    if (!Scene::init())
    {
        return false;
    }


	score = 0;
	string tempScore = "The End";
	scoreLabel = Label::createWithTTF(tempScore.c_str(), "fonts/Marker Felt.ttf", 45);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(scoreLabel);

	auto taxi = EventListenerKeyboard::create();
	taxi->onKeyPressed = CC_CALLBACK_2(TheEnd::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(taxi, this);

    return true;
}

void TheEnd::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{

	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->popScene();
	}
}