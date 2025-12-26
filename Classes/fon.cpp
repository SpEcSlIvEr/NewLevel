#include "fon.h"

Layer* fon::createLayer()
{
	auto pfon = fon::create();
	return pfon;
}

bool fon::init()
{
	if (!Layer::init())
	{
		return false;
	}
	some = new dicoration(this, "cloud.png");
	some->setPosition(origin.x + visibleSize.width / 2 + 100, origin.y + visibleSize.height / 4 + 300);

	std::string tempScore = StringUtils::format("%i", score);
	scoreLabel = Label::createWithTTF(tempScore.c_str(), "fonts/Marker Felt.ttf", 33);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(Point(visibleSize.width / 2 + 520, visibleSize.height / 2 +290));
	this->addChild(scoreLabel);

	/*this->schedule([this](float dt) {
		score++;
	    scoreLabel->setString(StringUtils::format("%i", score));
		}, 0.05f , "update_score");*/
	this->scheduleUpdate();
	


	std::string tempScore2 = StringUtils::format("%i", score2);
	scoreLabel2 = Label::createWithTTF(tempScore2.c_str(), "fonts/Marker Felt.ttf", 33);
	scoreLabel2->setColor(Color3B::WHITE);
	scoreLabel2->setPosition(Point(visibleSize.width / 2 + 420, visibleSize.height / 2 + 290));
	this->addChild(scoreLabel2);

	

	return true;
}

void fon::update(float dt)
{
	score++;
	scoreLabel->setString(StringUtils::format("%i", score));
}