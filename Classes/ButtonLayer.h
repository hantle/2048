//
//  ButtonLayer.h
//  2048
//
//  Created by Macbook on 2015. 1. 20..
//
//

#ifndef ___048__ButtonLayer__
#define ___048__ButtonLayer__

#include "cocos2d.h"

class ButtonLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // Auto Move
        // [Corner, Swing, Swirl, Random, Stop]
    // Undo
    
    
    
    
    void onMenu(Ref* pSender);
    
    CREATE_FUNC(ButtonLayer);
};

#endif // __HELLOWORLD_SCENE_H__
