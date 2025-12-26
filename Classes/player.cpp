
#include "player.h"

T_rex::T_rex(Layer* layer)
{
	auto pinfo = AutoPolygon::generatePolygon("dino1.png");
	dragon = Sprite::create(pinfo);
	dragon->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height/ 2));
	hitbox = PhysicsBody::create(pinfo);
	hitbox->setDynamic(true);
	/*hitbox->setLinearDamping(0.1f);
	hitbox->setAngularDamping(0.1f);*/
	dragon->setTag(2);
	hitbox->setRotationEnable(false);
	hitbox->setCollisionBitmask(6);
	hitbox->setContactTestBitmask(6);
	hitbox->setCategoryBitmask(1);
	dragon->setPhysicsBody(hitbox);
	layer->addChild(dragon);

}

void T_rex::setHitbox(int x, int y)
{
	dragon->removeComponent(hitbox);
	hitbox = PhysicsBody::createBox(Size(x, y), PhysicsMaterial(50.0, 1.0, 0.0));
	hitbox->setRotationEnable(false);
	hitbox->setCollisionBitmask(6);
	hitbox->setContactTestBitmask(6);
	hitbox->setCategoryBitmask(1);
	hitbox->setDynamic(true);
	dragon->setPhysicsBody(hitbox);
}

void T_rex::Jump()
{
	int tempy = dragon->getPositionY();
	if (tempy <= (visibleSize.height / 2 - 150))
	{
		auto move = JumpBy::create(1.5, Vec2(0, 200), 200, 1);
		dragon->runAction(move);
	}
}

void T_rex::setPosition(float x, float y)
{
	dragon->setPosition(Vec2(origin.x + x, origin.y + y));
}

void getPosition()
{

}

void T_rex::setScale(double buba)
{
	dragon->setScale(buba);
}
T_rex::~T_rex()
{
	delete[]dragon, hitbox;
}