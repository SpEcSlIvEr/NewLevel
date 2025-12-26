#ifndef __pterodactely__
#define __pterodactely__

#include <string.h>
#include "cocos2d.h"

using namespace cocos2d;
//using namespace std;

class enemy
{
private:
	Sprite* petra;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	PhysicsBody* hitbox;
public:
	enemy(Layer* ptero, std::string name); 
	void setPosition(int x, int y);
	void setPositionx(int x); 
	void setDynamic(bool proverka);
	int getPosx();
	void setHitbox();
	~enemy();

	/*CREATE_FUNC(enemy);*/
};

#endif // !__pterodactely__