#ifndef __BGLAYER__
#define __BGLAYER__

#include "cocos2d.h"
#include "enemy.h"
#include "player.h"
#include "TheEnd.h"
#include "TheBegin.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

class BgLayer : public Layer
{
public:
	
	static Layer* createLayer(PhysicsWorld* sceneWorld);
	virtual bool init();
	void SetPhysicsWorld(PhysicsWorld* world) { sceneWorld = world; };

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vector<SpriteFrame*> getAnimation(const char* format, int count);

	PhysicsWorld* sceneWorld;
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	MoveBy* move;
	Sprite* cloud;

	enemy* pol;
	PhysicsBody* polBody;
	T_rex* drakon;
	enemy* ptera;
	enemy* cactus;

	bool onContactBegin(PhysicsContact& contact);
	void update(float dt);

	CREATE_FUNC(BgLayer);
};

#endif // __BGLAYER__