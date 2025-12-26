#ifndef _FON_
#define _FON_
#include "cocos2d.h"
#include "dicoration.h"
using namespace cocos2d;
using namespace std;


class fon : public Layer
{
public:
	static Layer* createLayer();
	virtual bool init();

	Size visibleSize = Director::getInstance()->getVisibleSize(); 
	Vec2 origin = Director::getInstance()->getVisibleOrigin(); 
	dicoration* some;
	void update(float dt);
	//Sprite* cloud;
	//Sprite* cloud1;

	unsigned int score = 0;
	Label* scoreLabel;
	unsigned int score2 = 0;
	Label* scoreLabel2;
	

	

	CREATE_FUNC(fon);
};

#endif // _FON_