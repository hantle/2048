//
//  AdLayer.h
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#ifndef ___048__AdLayer__
#define ___048__AdLayer__

#include "cocos2d.h"

class AdLayer : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
    
    
    void onMenu(Ref* pSender);
    
    CREATE_FUNC(AdLayer);
};

#endif // __HELLOWORLD_SCENE_H__
