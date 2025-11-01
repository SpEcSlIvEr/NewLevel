#ifndef __BGLAYER__
#define __BGLAYER__

#include "cocos2d.h"
#include "enemy.h"
#include "player.h"

using namespace cocos2d;

class BgLayer : public Layer
{
public:
	
	static Layer* createLayer(PhysicsWorld* sceneWorld);
	virtual bool init();
	void SetPhysicsWorld(PhysicsWorld* world) { sceneWorld = world; };
	PhysicsWorld* sceneWorld;

	Sprite* cloud;

	T_rex* drakon;
	enemy* ptera;
	enemy* cactus;

	CREATE_FUNC(BgLayer);
};

#endif // __BGLAYER__