//
//  Info.h
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#ifndef ___048__Info__
#define ___048__Info__


#include "cocos2d.h"

class Info
{
    // Score
    // HighScore
public:
    Info(cocos2d::Layer *layer);
    void setScore(int score);
private:
    int score;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Label *labelScore;
};

#endif /* defined(__auto__Menus__) */
