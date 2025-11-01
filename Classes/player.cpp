
#include "mainlayer.h"

using namespace cocos2d;

T_rex::T_rex(Layer* layer)
{
	dragon = Sprite::create("dino1.png");
	dragon->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height/ 2));
	hitbox = PhysicsBody::createBox(Size(100, 100), PhysicsMaterial(50.0, 1.0, 0.0));
	hitbox->setDynamic(true);
	/*hitbox->setLinearDamping(0.1f);
	hitbox->setAngularDamping(0.1f);*/
	dragon->setTag(2);
	hitbox->setRotationEnable(true);
	hitbox->setCollisionBitmask(6);
	hitbox->setContactTestBitmask(6);
	hitbox->setCategoryBitmask(1);
	dragon->setPhysicsBody(hitbox);
	layer->addChild(dragon);
}

void T_rex::Jump()
{
	auto move = JumpBy::create(3, Vec2(0, 300), 300, 1);
	dragon->runAction(move);
}

T_rex::~T_rex()
{
	delete[]dragon, hitbox;
}