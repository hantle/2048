//
//  GameScene.cpp
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#include "GameScene.h"
#include "Define.h"
#include "Board.h"
#include "EasyPadGen.h"
#include "EdgePadMover.h"

USING_NS_CC;

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
    
    board = new Board(Board::_4BY4);
    EasyPadGen *eGen = new EasyPadGen();
    EdgePadMover *eMover = new EdgePadMover();
    board->setGen(eGen);
    board->setMover(eMover);
    board->reset();

    // create UndoManager & save initial state
    if(undoManager)
    {
        delete undoManager;
    }

    undoManager = new UndoManager();
    undoManager->putState(board->getState());

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
    
    backgroundLayer = LayerColor::create(kColorBackground);
    backgroundLayer->setContentSize(Size(visibleSize.width - 40, visibleSize.width - 40));
    backgroundLayer->setPosition(visibleSize.width/2 - backgroundLayer->getContentSize().width/2, visibleSize.height/2 - 50 - backgroundLayer->getContentSize().height/2);
    this->addChild(backgroundLayer);

    initPad();
    
    auto menu = Menu::create(menuMenu, menuLeaderboard, NULL);
    menu->setContentSize(Size(visibleSize.width*2/3, 100));
    menu->setPosition(visibleSize.width/3, visibleSize.height - 100);
    this->addChild(menu, 100);
    
    // Touch Events (Single)
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    // keyboard listener for testring in linux
    auto key_listener = EventListenerKeyboard::create();
    key_listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(key_listener, this);

    return true;
}

void GameScene::initPad()
{
    int size = board->getSize();
    for (int i = 0; i < size * size; i++) {
        int x = 44+(512/size + 2)*(i%size);
        int y = 44+(512/size + 2)*(i/size);

        NumPad *pad = board->getNumPad(i/size, i%size);
        auto grid = pad->getSprite();

        grid->setAnchorPoint(Point(0, 0));
        grid->setContentSize(Size(512 / size, 512 / size));
        grid->setPosition(x, y);
        backgroundLayer->addChild(grid);

        int num = pad->getNum();
        auto label = pad->getLabel();
        if(num != 0) {
            label->setString(String::createWithFormat("%d", num)->getCString());
        }
        label->setPosition(x+512/size/2, y+512/size/2);
        backgroundLayer->addChild(label);
    }
}

void GameScene::onMenu(Ref* pSender)
{
    Director::getInstance()->replaceScene(MenuScene::createScene());
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
	return true;
}

void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    bool isGameOver = false;
    if(keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        printf("Left Arrow Key released.\n");
        bool gen = board->moveLeft();
        isGameOver = !(board->doNext(gen));
    }
    else if(keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        printf("Right Arrow Key released.\n");
        bool gen = board->moveRight();
        isGameOver = !(board->doNext(gen));
    }
    else if(keyCode == cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW)
    {
        printf("Up Arrow Key released.\n");
        bool gen = board->moveUp();
        isGameOver = !(board->doNext(gen));
    }
    else if(keyCode == cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW)
    {
        printf("Down Arrow Key released.\n");
        bool gen = board->moveDown();
        isGameOver = !(board->doNext(gen));
    }

    int point = board->getPoint();
    // update point;

    if(isGameOver) {
        printf("Game Over!!!\n");
        // do something
    } else {
        // save state
        undoManager->putState(board->getState());
    }
}

