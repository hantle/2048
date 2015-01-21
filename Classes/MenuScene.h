//
//  MenuScene.h
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#ifndef ___048__MenuScene__
#define ___048__MenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameScene.h"

class MenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // Grid (4x4, 8x8)
    // Ranking
    // Achievement
    // Settings
    
    
    
    
    
    void onMenu1(Ref* pSender);
    void onMenu2(Ref* pSender);
    void onMenu3(Ref* pSender);
    void onMenu4(Ref* pSender);
    
    CREATE_FUNC(MenuScene);
};

#endif // __HELLOWORLD_SCENE_H__
