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
#include "Board.h"

class GameScene : public cocos2d::Layer
{
    private:
        Board *board;
        Layer *backgroundLayer;
    public:
        static cocos2d::Scene* createScene();
        
        virtual bool init();
        void initPad();
        // Background
        // Blocks
        
        void onMenu(Ref* pSender);
        bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
        void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
        CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
