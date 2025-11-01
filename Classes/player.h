
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
	~T_rex();

	/*CREATE_FUNC(T_rex);*/
};







#endif // !_PLAYER_