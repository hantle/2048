//
//  Info.cpp
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#include "Info.h"
#include "Define.h"

USING_NS_CC;

Info::Info(Layer *layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    labelScore = Label::createWithTTF("0", kMarkerFelt, 20);
    layer->addChild(labelScore);
}

void Info::setScore(int score)
{
    labelScore->setString(String::createWithFormat("%d", score)->getCString());
}