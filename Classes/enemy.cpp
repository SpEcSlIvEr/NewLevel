
#include "enemy.h"


enemy::enemy(Layer* ptero, std::string name)
{
	petra = Sprite::create(name);
	petra->setPosition(Point(origin.x + visibleSize.width / 2 - 300, origin.y + visibleSize.height / 4 + 200));
	hitbox = PhysicsBody::createBox(Size(75, 75), PhysicsMaterial(0.0, 0.0, 0.0));
	hitbox->setDynamic(false);
	/*hitbox->setLinearDamping(0.1f);
	hitbox->setAngularDamping(0.1f);*/
	petra->setTag(2);
	hitbox->setRotationEnable(false);
	hitbox->setCollisionBitmask(1);
	hitbox->setContactTestBitmask(1);
	hitbox->setCategoryBitmask(4);
	petra->setPhysicsBody(hitbox);
	ptero->addChild(petra);

}

void enemy::setPosition(int x, int y)
{
	petra->setPosition(Vec2(origin.x + visibleSize.width / 2 + x, origin.y + visibleSize.height / 4 + y));
	
}

void enemy::setDynamic(bool proverka)
{
	hitbox->setDynamic(proverka);
}

void enemy::setHitbox()
{
	hitbox = PhysicsBody::createBox(petra->getContentSize(), PhysicsMaterial(0.0, 0.0, 0.0));
	petra->setPhysicsBody(hitbox);
}

void enemy::setPositionx(int x)
{
	int tempx = petra->getPositionX();
	tempx -= x;
	int tempy = petra->getPositionY();
	
	petra->setPosition(Vec2(tempx, tempy));
}

int enemy::getPosx()
{
	return petra->getPositionX();
}

enemy::~enemy()
{
	delete[]petra, hitbox;
}