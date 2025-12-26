#include "TheBegin.h"


Scene* TheBegin::createScene()
{
	auto scene = create();
	auto layer = LayerColor::create(Color4B(255, 137, 192, 179));
	scene->leyer = layer;
	scene->addChild(layer, -2);
	auto randlayer = sloy::createLayer();
	scene->addChild(randlayer, -1);
	return scene;
}

bool TheBegin::init() 
{
	if (!Scene::init())
	{
		return false;
	}

	string tempScore = "The Begin tap ENTER to started";
	scoreLabel = Label::createWithTTF(tempScore.c_str(), "fonts/Marker Felt.ttf", 45);
	scoreLabel->setColor(Color3B::BLACK);
	scoreLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(scoreLabel);

	auto taxi = EventListenerKeyboard::create();
	taxi->onKeyPressed = CC_CALLBACK_2(TheBegin::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(taxi, this);
	return true;
}

void TheBegin::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	
	 if (keyCode == EventKeyboard::KeyCode::KEY_ENTER)
	 {
		 auto next = HelloWorld::createScene();
		 Director::getInstance()->replaceScene(TransitionFade::create(0.5f, next));
	 }
}