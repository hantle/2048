#include <math.h>

#include "NumPad.h"

NumPad::NumPad() 
{
    padSprite = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
    padSprite->setColor(kColorBackgroundGrid);
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

    // change pad color
    if(num == 0)
        padSprite->setColor(kColorBackgroundGrid);
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
