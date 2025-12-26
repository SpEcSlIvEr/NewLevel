#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "BgLayer.h"
#include "fon.h"

using namespace cocos2d;

class HelloWorld : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();
    void SetPhysicsWorld( PhysicsWorld* world) { sceneWorld = world; };
     PhysicsWorld* sceneWorld;

    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
