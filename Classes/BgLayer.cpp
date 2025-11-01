#include "BgLayer.h"

Layer* BgLayer::createLayer(PhysicsWorld* sceneWorld)
{
	auto sloy = BgLayer::create();
	sloy->SetPhysicsWorld(sceneWorld);
	return sloy;
}

bool BgLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    ptera = new enemy(this, "ptera.png");
    drakon = new T_rex(this);
    cactus = new enemy(this, "cacti-small1.png");
    cactus->setDynamic(false);
    cactus->setPosition(200, -56);

    return true;
}