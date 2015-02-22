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
#include "CardSprite.h"
#include "Plot.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    CREATE_FUNC(GameScene);
private:
    // Background
    // Blocks
    int score;
    int beginX, beginY, endX, endY;
    cocos2d::Label *labelCardNumber;
    
    void setScore(int score);
    void onMenu(Ref* pSender);
    
//    void createRandomNumber();
    void swipeAnimation();
    
    
    cocos2d::ui::Scale9Sprite *backgroundLayer;
    int arrayNumber[4][4];
    bool isMoving;
    
    cocos2d::Size visibleSize;
    
    
    
    // copy of gamescene1.h
    void createCardSprite(cocos2d::Size size);
    void createKeyBoard();
    void onKey(Ref* pSender);
//    int beginX, beginY, endX, endY;
    bool doLeft();
    void doLeftCallback(int x, int y, int x1);
    bool doRight();
    bool doUp();
    bool doDown();
    CardSprite *cardArr[4][4];
    Plot *plotArr[4][4];
    
//    int score;
//    cocos2d::LabelTTF *lbCardNumber;
    void createCardNumber();
    void doCheck();
//    void setScore(int score);
    
    
    bool doAnimate(int x, int y, int direction);
};

#endif // __HELLOWORLD_SCENE_H__
