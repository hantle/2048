#include "NumPad.h"

NumPad::NumPad() 
{
    padSprite = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
    numSprite = Label::createWithTTF("", kMarkerFelt, 50);

    mNum = 0;
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
