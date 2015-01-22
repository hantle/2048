//
//  GameScene.h
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#ifndef ___048__GameScene__
#define ___048__GameScene__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "MenuScene.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // Background
    // Blocks
    
    
    void onMenu(Ref* pSender);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
