#include "BgLayer.h"

Layer* BgLayer::createLayer(PhysicsWorld* sceneWorld)
{
	auto sloy = BgLayer::create();
	sloy->SetPhysicsWorld(sceneWorld);
	return sloy;
}

bool BgLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    pol = new enemy(this, "ground.png");
    ptera = new enemy(this, "ptera.png");
    drakon = new T_rex(this);
    cactus = new enemy(this, "cacti-small1.png");
    cactus->setDynamic(false);
    cactus->setPosition(200, -56);
    ptera->setPosition(300, 200);
    drakon->setPosition(100, 100);
    drakon->setHitbox(250, 250);
    drakon->setScale(0.4);
    pol->setHitbox();

    
    /*polBody = PhysicsBody::createBox(pol->getContentSize(), PhysicsMaterial(0.0, 0.0, 0.0));*/
    pol->setPosition(0, -100);
    pol->setDynamic(false);
    /*polBody->setDynamic(false);*/
    /*pol->setPhysicsBody(polBody);*/
    /*this->addChild(pol);*/

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(BgLayer::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    auto taxi = EventListenerKeyboard::create();
    taxi->onKeyPressed = CC_CALLBACK_2(BgLayer::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(taxi, this);

    this->scheduleUpdate(); 
    /*SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/SPRITE/HD/bla.plist");

    auto frames = getAnimation("bird_%d.jpg", 2);
    auto sprite = Sprite::createWithSpriteFrame(frames.front());
    this->addChild(sprite);
    sprite->setPosition(300, 300);

    auto animation = Animation::createWithSpriteFrames(frames, 1.0f / 2);
    sprite->runAction(RepeatForever::create(Animate::create(animation)));*/


    return true;
}

void BgLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
    {
        drakon->Jump();
    }
    else if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
    {
        auto current = Director::getInstance()->getRunningScene();
        Director::getInstance()->pushScene(current);
        auto next = TheEnd::createScene();
        Director::getInstance()->replaceScene(TransitionFade::create(0.5f, next));
    }
}

Vector<SpriteFrame*> BgLayer::getAnimation(const char* format, int count) {
    auto spritecache = SpriteFrameCache::getInstance();

    Vector<SpriteFrame*> animFrames;
    char str[100];
    for (int i = 1; i <= count; i++)
    {
        sprintf(str, format, i);
        //std::string name = StringUtils::format("bird_%d.jpg",i);
        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
    }
    return animFrames;
}


bool BgLayer::onContactBegin(PhysicsContact& contact)
{
    auto BodyA = contact.getShapeA()->getBody();
    auto BodyB = contact.getShapeB()->getBody();
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    int categoryA = BodyA->getCategoryBitmask();
    int collisionA = BodyA->getCollisionBitmask();
    int contactTestA = BodyA->getContactTestBitmask();

    int categoryB = BodyB->getCategoryBitmask();
    int collisionB = BodyB->getCollisionBitmask();
    int contactTestB = BodyB->getContactTestBitmask();

    if (nodeA && nodeB)
    {

        if ((categoryA & collisionB) || (categoryB & collisionA))
        {
            auto next = TheEnd::createScene();
            Director::getInstance()->replaceScene(TransitionFade::create(0.5f, next));
        }
    }


    return true;
}

void BgLayer::update(float dt)
{
    if (cactus->getPosx() <= 0)
    {
        cactus->setPosition(visibleSize.width/2, -56);
    }
    if (ptera->getPosx() <= 0)
    {
        ptera->setPosition(visibleSize.width / 2, 200);
    }
    /*ptera->setPositionx(7);
    cactus->setPositionx(4);*/
}