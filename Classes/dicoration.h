#ifndef _decor_
#define _decor_

#include "cocos2d.h";

using namespace cocos2d;
using namespace std;

class dicoration
{
private:
	Sprite* tuchka;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
public:
	dicoration(Layer* layer, string name);
	void setPosition(float x, float y);
	~dicoration();
};

#endif // _decor_