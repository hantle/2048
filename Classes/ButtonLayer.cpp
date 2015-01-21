//
//  ButtonLayer.cpp
//  2048
//
//  Created by Macbook on 2015. 1. 20..
//
//

#include "ButtonLayer.h"
#include "Define.h"

USING_NS_CC;

Scene* ButtonLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ButtonLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ButtonLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    MenuItemFont *menuMenu = MenuItemFont::create("MENU", CC_CALLBACK_1(ButtonLayer::onMenu, this));
    MenuItemFont *menuLeaderboard = MenuItemFont::create("LEADERBOARD", CC_CALLBACK_1(ButtonLayer::onMenu, this));
    menuMenu->setPosition(visibleSize.width/6, 0);
    menuLeaderboard->setPosition(visibleSize.width/2, 0);
    
    LayerColor *layer = LayerColor::create(Color4B(0, 255, 255, 255));
    layer->setContentSize(Size(visibleSize.width/3, 100));
    layer->setPosition(visibleSize.width*2/3, visibleSize.height-150);
    this->addChild(layer);
    
    LayerColor *layer1 = LayerColor::create(Color4B(255, 0, 255, 255));
    layer1->setContentSize(Size(visibleSize.width/3, 100));
    layer1->setPosition(visibleSize.width/3, visibleSize.height-150);
    this->addChild(layer1);
    
    
    
    auto menu = Menu::create(menuMenu, menuLeaderboard, NULL);
    menu->setContentSize(Size(visibleSize.width*2/3, 100));
    menu->setPosition(visibleSize.width/3, visibleSize.height - 100);
    this->addChild(menu, 100);
    
    
    LayerColor *backgroundLayer = LayerColor::create(Color4B(180, 180, 22, 255));
    backgroundLayer->setContentSize(Size(visibleSize.width - 40, visibleSize.width - 40));
    backgroundLayer->setPosition(visibleSize.width/2 - backgroundLayer->getContentSize().width/2, visibleSize.height/2 - 50 - backgroundLayer->getContentSize().height/2);
    this->addChild(backgroundLayer);
    
    return true;
}

void ButtonLayer::onMenu(Ref* pSender)
{
}
