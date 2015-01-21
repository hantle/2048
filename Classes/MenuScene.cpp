//
//  MenuScene.cpp
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#include "MenuScene.h"
#include "Define.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto labelMenu = Label::createWithTTF("MENU", kMarkerFelt, kMenuFontSize+10);
    labelMenu->setPosition(visibleSize.width/2, visibleSize.height - 200);
    this->addChild(labelMenu);
    auto menu1 = MenuItemFont::create("KEEP GOING", CC_CALLBACK_1(MenuScene::onMenu1, this));
    auto menu2 = MenuItemFont::create("NEW GAME", CC_CALLBACK_1(MenuScene::onMenu2, this));
    auto menu3 = MenuItemFont::create("HOW TO PLAY", CC_CALLBACK_1(MenuScene::onMenu3, this));
    auto menu4 = MenuItemFont::create("REMOVE ADS", CC_CALLBACK_1(MenuScene::onMenu4, this));
    menu1->setFontSizeObj(kMenuFontSize);
    menu2->setFontSizeObj(kMenuFontSize);
    menu3->setFontSizeObj(kMenuFontSize);
    menu4->setFontSizeObj(kMenuFontSize);
    menu1->setContentSize(Size(menu1->getContentSize().width, 100));
    menu2->setContentSize(Size(menu2->getContentSize().width, 100));
    menu3->setContentSize(Size(menu3->getContentSize().width, 100));
    menu4->setContentSize(Size(menu4->getContentSize().width, 100));
    
    auto menu = Menu::create(menu1, menu2, menu3, menu4, NULL);
    menu->setPosition(visibleSize.width/2, visibleSize.height/2 + 20);
    menu->alignItemsVertically();
    this->addChild(menu, 100);
    
    return true;
}

void MenuScene::onMenu1(Ref* pSender)
{
    // Continue Game
    Director::getInstance()->replaceScene(GameScene::createScene());
}

void MenuScene::onMenu2(Ref* pSender)
{
    // New Game
    Director::getInstance()->replaceScene(GameScene::createScene());
}

void MenuScene::onMenu3(Ref* pSender)
{
    // How To Play
}

void MenuScene::onMenu4(Ref* pSender)
{
    // Remove Ads
}
