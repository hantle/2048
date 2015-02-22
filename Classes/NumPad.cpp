#include <math.h>

#include "NumPad.h"

NumPad::NumPad() 
{
    padSprite = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
    padSprite->setVisible(false);
    padSprite->setCascadeOpacityEnabled(true);
    numSprite = Label::createWithTTF("", kMarkerFelt, 50);

    mNum = 0;
    aniType = AniType::NONE;
}

NumPad::NumPad(const NumPad&  np)
{
    mNum = np.mNum;
    padSprite = np.padSprite;
    numSprite = np.numSprite;
}

NumPad::~NumPad()
{
    if(padSprite != 0) padSprite->release();
    if(numSprite != 0) numSprite->release();
}

void NumPad::setNum(int num)
{
    mNum = num;

    if(num != 0) {
        numSprite->setString(String::createWithFormat("%d", num)->getCString());
    } else {
        numSprite->setString("");
    }

    padSprite->setVisible(true);
    // change pad color
    if(num == 0) {
        padSprite->setVisible(false);
    }
    else if(num == (int)pow(2, 1))
        padSprite->setColor(kColorGrid1);
    else if(num == (int)pow(2, 2))
        padSprite->setColor(kColorGrid2);
    else if(num == (int)pow(2, 3))
        padSprite->setColor(kColorGrid3);
    else if(num == (int)pow(2, 4))
        padSprite->setColor(kColorGrid4);
    else if(num == (int)pow(2, 5))
        padSprite->setColor(kColorGrid5);
    else if(num == (int)pow(2, 6))
        padSprite->setColor(kColorGrid6);
    else if(num == (int)pow(2, 7))
        padSprite->setColor(kColorGrid7);
    else if(num == (int)pow(2, 8))
        padSprite->setColor(kColorGrid8);
    else if(num >= (int)pow(2, 9))
        padSprite->setColor(kColorGrid9);
}

void NumPad::setAni(AniType::Type type, NumPad *from)
{
    if(type == AniType::NONE) {
    } else if(type == AniType::GEN) {
        padSprite->setOpacity(0);
        padSprite->runAction(FadeIn::create(0.5));
    } else if(type == AniType::MOVE) {
        auto pad = from->getSprite();
        auto num = from->getLabel();

        int n = from->getNum();
        Vec2 padVec = pad->getPosition();
        Vec2 numVec = num->getPosition();

        Vec2 oriPadVec = padSprite->getPosition();
        Vec2 oriNumVec = numSprite->getPosition();

        from->setNum(0);

        this->setNum(n);
        numSprite->setPosition(numVec);
        numSprite->runAction(MoveTo::create(0.3, *new Vec2(oriNumVec)));

        padSprite->setPosition(padVec);
        padSprite->runAction(MoveTo::create(0.3, *new Vec2(oriPadVec)));

    } else if(type == AniType::BLOCKED) {
    } else if(type == AniType::MERGED) {
        //
    } else if(type == AniType::MERGING) {
        //padSprite->runAction(TintTo::create(1,
                    //kColorBackgroundGrid.r,
                    //kColorBackgroundGrid.g,
                    //kColorBackgroundGrid.b));
    }
}
