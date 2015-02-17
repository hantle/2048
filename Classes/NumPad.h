#ifndef __NUMPAD_H__
#define __NUMPAD_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "Define.h"
#include "AniType.h"

USING_NS_CC;

class NumPad {
    private:
        int mNum;

        ui::Scale9Sprite *padSprite;
        Label *numSprite;

        AniType::Type aniType;
    public:

        NumPad();
        NumPad(const NumPad& np);
        ui::Scale9Sprite *getSprite() { return padSprite; };
        Label *getLabel() { return numSprite; };

        int getNum() const { return mNum; }
        void setNum(int num);
        AniType::Type getAniType() const { return aniType; }
        void setAniType(AniType::Type type) { aniType = type; }
    public:
        ~NumPad();
};

#endif // __NUMPAD_H__
