
#ifndef _PLAYER_
#define _PLAYER_ 



#include "cocos2d.h";

using namespace cocos2d;

class T_rex
{ 
	private:
	Sprite* dragon;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	PhysicsBody* hitbox;

public: 
	T_rex(Layer* layer);
	void Jump();
	void setPosition(float x, float y);
	void setScale(double buba);
	int getPositiony();
	void setHitbox(int x, int y);

	~T_rex();

	/*CREATE_FUNC(T_rex);*/
};







#endif // !_PLAYER_