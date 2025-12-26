#include "dicoration.h"

dicoration::dicoration(Layer* layer, string name)
{
	tuchka = Sprite::create(name);
	tuchka->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	tuchka->setTag(2);
	layer->addChild(tuchka);
}

void dicoration::setPosition(float x, float y)
{
	tuchka->setPosition(Vec2(origin.x + x, origin.y + y));
}