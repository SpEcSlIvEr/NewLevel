#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "BgLayer.h"
using namespace cocos2d;

class HelloWorld : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();
    void SetPhysicsWorld( PhysicsWorld* world) { sceneWorld = world; };
     PhysicsWorld* sceneWorld;
    void onKeyPressed( EventKeyboard::KeyCode keyCode,  Event* event);
     MoveBy* move;
    bool onContactBegin( PhysicsContact& contact);
    //bool onContactBegin( PhysicsContact& contact);
    // PhysicsContact* contactPhics;
    
    unsigned int score;
    Label* scoreLabel;

    /* Sprite* ball;
     PhysicsBody* ballBody;*/

   /*  Sprite* ball2;
     PhysicsBody* ballBody2;

     Sprite* edgeSprite;
     PhysicsBody* edgeSpriteBody;*/
     Sprite *pol;
     PhysicsBody* polBody;

     /*Sprite* cactus;
     PhysicsBody* cactusBody;*/

     Sprite* cloud;
     PhysicsBody* cloudBody;
    // a selector callback
    //void menuCloseCallback( Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
