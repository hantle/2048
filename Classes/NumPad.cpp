#include "NumPad.h"

NumPad::NumPad() 
{
    padSprite = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
    numSprite = LabelTTF::create("", kArial, 50);

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
    if(padSprite != 0) delete padSprite;
    if(numSprite != 0) delete numSprite;
}
