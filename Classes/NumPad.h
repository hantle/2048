#ifndef __NUMPAD_H__
#define __NUMPAD_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "Define.h"

USING_NS_CC;

class NumPad {
    private:
        ui::Scale9Sprite *padSprite;
        LabelTTF *numSprite;

    public:
        int mNum = 0;

        NumPad();
        NumPad(const NumPad& np);
        ui::Scale9Sprite *getSprite() { return padSprite; };
        LabelTTF *getLabel() { return numSprite; };

    public:
        ~NumPad();
};

#endif // __NUMPAD_H__
