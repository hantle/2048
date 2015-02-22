//
//  CardSprite.h
//  2048
//
//  Created by Macbook on 2015. 1. 22..
//
//

#ifndef ___048__CardSprite__
#define ___048__CardSprite__

#include "cocos2d.h"


class CardSprite : public cocos2d::Sprite
{
public:
    static CardSprite* createCardSprite(int number, int width, int height, float x, float y);
    
    virtual bool init();
    CREATE_FUNC(CardSprite);
    
    int getNumber();
    void setNumber(int num);
    void setNumber(int num, bool animated);
    void ChangeLabel(int number) ;
private:
    int number;
    void cardInit(int number, int width, int height, float x, float y);
    cocos2d::Label *labelCardNumber;
    cocos2d::LayerColor *colorBackground;
};

#endif // __CARDSPRITE_H_