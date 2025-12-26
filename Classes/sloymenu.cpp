#include "sloymenu.h"

Layer* sloy::createLayer()
{
	return sloy::create();
}

bool sloy::init()
{
	if (!Layer::init())
	{
		return false;
	}




	return true;
}
