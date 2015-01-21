//
//  GameScene.cpp
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#include "cocos2d.h"
#include "cocos-ext.h"
#include "GameScene.h"
#include "Define.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    glClearColor(81.0/255.0, 192.0/255.0, 201.0/255.0, 1.0);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    MenuItemFont *menuMenu = MenuItemFont::create("MENU", CC_CALLBACK_1(GameScene::onMenu, this));
    MenuItemFont *menuLeaderboard = MenuItemFont::create("LEADERBOARD", CC_CALLBACK_1(GameScene::onMenu, this));
    menuMenu->setPosition(visibleSize.width/6, 0);
    menuLeaderboard->setPosition(visibleSize.width/2, 0);
    
    
    auto button1 = ui::Scale9Sprite::create(Rect(10,10,12,12), "button64.png");
    button1->setAnchorPoint(Point(0, 0));
    button1->setPosition(visibleSize.width/3, visibleSize.height-150);
    button1->setContentSize(Size(visibleSize.width/3, 100));
    button1->setColor(Color3B(255, 0, 255));
    this->addChild(button1);
    
    auto button2 = ui::Scale9Sprite::create(Rect(10,10,12,12), "button64.png");
    button2->setAnchorPoint(Point(0, 0));
    button2->setPosition(visibleSize.width*2/3, visibleSize.height-150);
    button2->setContentSize(Size(visibleSize.width/3, 100));
    this->addChild(button2);
    
    
//    auto background = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
//    background->setAnchorPoint(Point(0, 0));
//    background->setContentSize(Size(130 * 4 + 10, 130 * 4 + 10));
//    background->setPosition(<#const cocos2d::Vec2 &position#>)
    
    LayerColor *backgroundLayer = LayerColor::create(kColorBackground);
    backgroundLayer->setContentSize(Size(visibleSize.width - 40, visibleSize.width - 40));
    backgroundLayer->setPosition(visibleSize.width/2 - backgroundLayer->getContentSize().width/2, visibleSize.height/2 - 50 - backgroundLayer->getContentSize().height/2);
    this->addChild(backgroundLayer);

    for (int i = 0; i < 16; i++) {
        int x = 44+130*(i%4);
        int y = 44+130*(i/4);
        auto backgroundGrid = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
        backgroundGrid->setAnchorPoint(Point(0, 0));
        backgroundGrid->setContentSize(Size(128, 128));
        backgroundGrid->setPosition(x, y);
        backgroundGrid->setColor(kColorBackgroundGrid);
        backgroundLayer->addChild(backgroundGrid);
    }

    
    auto menu = Menu::create(menuMenu, menuLeaderboard, NULL);
    menu->setContentSize(Size(visibleSize.width*2/3, 100));
    menu->setPosition(visibleSize.width/3, visibleSize.height - 100);
    this->addChild(menu, 100);
    
    
<<<<<<< Updated upstream
    
    // Touch Events (Single)
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(FlappyBird::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
=======
    LayerColor *backgroundLayer = LayerColor::create(Color4B(180, 180, 22, 255));
    backgroundLayer->setContentSize(Size(visibleSize.width - 40, visibleSize.width - 40));
    backgroundLayer->setPosition(visibleSize.width/2 - backgroundLayer->getContentSize().width/2, visibleSize.height/2 - 50 - backgroundLayer->getContentSize().height/2);
    this->addChild(backgroundLayer);

    
    
    // draw blocks
    auto block = Scale9Sprite::create("res/green_edit.png", Rect(0,0,28,28), Rect(5,5,18,18));
    block->setPosition(Vec2(250, 250));
    block->setContentSize(Size(28*2, 28*2));
    this->addChild(block);
    
    
>>>>>>> Stashed changes
    
    
    return true;
}

void GameScene::onMenu(Ref* pSender)
{
    Director::getInstance()->replaceScene(MenuScene::createScene());
}
