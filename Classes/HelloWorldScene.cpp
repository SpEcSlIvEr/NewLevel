#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
    scene->getPhysicsWorld()->setGravity(Vect(0, -500.0));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = HelloWorld::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer, 2);

    auto bgLayer = LayerColor::create(Color4B(100, 149, 237, 255));
    scene->addChild(bgLayer, -2);
    
    auto player_layer = BgLayer::createLayer(scene->getPhysicsWorld());
    scene->addChild(player_layer, -1);

    return scene;

}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    


   
    pol = Sprite::create("ground.png");
    polBody = PhysicsBody::createBox(pol->getContentSize(), PhysicsMaterial(0.0, 0.0, 0.0));
    pol->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height /4 - 100);
    polBody->setDynamic(false);
    pol->setPhysicsBody(polBody);
    this->addChild(pol);

    /*cactus = Sprite::create("cacti-small1.png");
    cactusBody = PhysicsBody::createBox(cactus->getContentSize(), PhysicsMaterial(50.0, 1.0, 0.0));
    cactus->setPosition(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 4 - 56);
    cactusBody->setDynamic(false);
    cactusBody->setCollisionBitmask(1);
    cactusBody->setCategoryBitmask(2);
    cactusBody->setContactTestBitmask(1);
    cactus->setTag(2);
    cactus->setPhysicsBody(cactusBody);
    this->addChild(cactus);*/

    /*petra = Sprite::create("ptera.png");
    petraBody = PhysicsBody::createBox(Size(75, 75), PhysicsMaterial(0.0, 0.0, 0.0));
    petra->setPosition(origin.x + visibleSize.width / 2 + 200, origin.y + visibleSize.height / 4 + 200);
    petraBody->setDynamic(false);
    petraBody->setCollisionBitmask(1);
    petraBody->setCategoryBitmask(4);
    petraBody->setContactTestBitmask(1);
    petra->setTag(2);
    petra->setPhysicsBody(petraBody);
    this->addChild(petra);*/

    cloud = Sprite::create("cloud.png");
    cloudBody = PhysicsBody::createBox(cloud->getContentSize(), PhysicsMaterial(0.0, 0.0, 0.0));
    cloud->setPosition(origin.x + visibleSize.width / 2 + 100, origin.y + visibleSize.height / 4 + 300);
    cloudBody->setDynamic(false);
    cloud->setPhysicsBody(cloudBody);
    this->addChild(cloud);

    

    score = 0;
    std::string tempScore = StringUtils::format("%i", score);
    scoreLabel = Label::createWithTTF(tempScore.c_str(), "fonts/Marker Felt.ttf", 33);
    scoreLabel->setColor(Color3B::WHITE);
    scoreLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(scoreLabel);
    
    auto taxi = EventListenerKeyboard::create();
    taxi->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(taxi, this);

    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    return true;
}

void HelloWorld::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
{
    if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
    {
        
        /*move = MoveBy::create(2, Vec2(50, 0));
        dino->runAction(move);*/
        drakon->Jump();
    }
}
bool HelloWorld::onContactBegin(PhysicsContact& contact)
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
            ++score; 
            std::string tempScore = StringUtils::format("%i", score);
            scoreLabel->setString(tempScore.c_str());
        }
    }


    return true;
}
