//
//  GameScene.cpp
//  2048
//
//  Created by Macbook on 2015. 1. 19..
//
//

#include "GameScene.h"
#include "Define.h"

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
//    glClearColor(81.0/255.0, 192.0/255.0, 201.0/255.0, 1.0);
//
//
//    MenuItemFont *menuMenu = MenuItemFont::create("MENU", CC_CALLBACK_1(GameScene::onMenu, this));
//    MenuItemFont *menuLeaderboard = MenuItemFont::create("LEADERBOARD", CC_CALLBACK_1(GameScene::onMenu, this));
//    menuMenu->setPosition(visibleSize.width/6, 0);
//    menuLeaderboard->setPosition(visibleSize.width/2, 0);
//    
//    
//    auto button1 = ui::Scale9Sprite::create(Rect(10,10,12,12), "button64.png");
//    button1->setAnchorPoint(Point(0, 0));
//    button1->setPosition(visibleSize.width/3, visibleSize.height-150);
//    button1->setContentSize(Size(visibleSize.width/3, 100));
//    button1->setColor(Color3B(255, 0, 255));
//    this->addChild(button1);
//    
//    auto button2 = ui::Scale9Sprite::create(Rect(10,10,12,12), "button64.png");
//    button2->setAnchorPoint(Point(0, 0));
//    button2->setPosition(visibleSize.width*2/3, visibleSize.height-150);
//    button2->setContentSize(Size(visibleSize.width/3, 100));
//    this->addChild(button2);
//    
//    
////    auto background = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
////    background->setAnchorPoint(Point(0, 0));
////    background->setContentSize(Size(130 * 4 + 10, 130 * 4 + 10));
////    background->setPosition(<#const cocos2d::Vec2 &position#>)
//    
//    backgroundLayer = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "background64.png");
//    backgroundLayer->setAnchorPoint(Point(0, 0));
//    backgroundLayer->setContentSize(Size(visibleSize.width - 40, visibleSize.width - 40));
//    backgroundLayer->setPosition(visibleSize.width/2 - backgroundLayer->getContentSize().width/2, visibleSize.height/2 - 50 - backgroundLayer->getContentSize().height/2);
//    backgroundLayer->setColor(kColorBackground);
//    this->addChild(backgroundLayer);
//
//    for (int i = 0; i < 16; i++) {
//        int x = 44+130*(i%4);
//        int y = 44+130*(i/4);
//        auto backgroundGrid = ui::Scale9Sprite::create(Rect(10, 10, 12, 12), "button64.png");
//        backgroundGrid->setAnchorPoint(Point(0, 0));
//        backgroundGrid->setContentSize(Size(128, 128));
//        backgroundGrid->setPosition(x, y);
//        backgroundGrid->setColor(kColorBackgroundGrid);
//        backgroundGrid->setTag(i%4 * 10 +  i/4);
//        log("%d", i%4 * 10 +  i/4);
//        backgroundLayer->addChild(backgroundGrid);
//    }
//
//    
//    auto menu = Menu::create(menuMenu, menuLeaderboard, NULL);
//    menu->setContentSize(Size(visibleSize.width*2/3, 100));
//    menu->setPosition(visibleSize.width/3, visibleSize.height - 100);
//    this->addChild(menu, 100);
//    
    
    
    // Touch Events (Single)
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    
    
    
    
    //// implemented
    auto layerColorBG = LayerColor::create(Color4B(180, 170, 160, 255));
    this->addChild(layerColorBG);
    
    auto cardNumberTitle = Label::createWithTTF("SCORE", kMarkerFelt, 40);
    cardNumberTitle->setPosition(Point(visibleSize.width/2 + 340, visibleSize.height/2 + 130));
    this->addChild(cardNumberTitle);
    
    score = 0;
    labelCardNumber = Label::createWithTTF("0", kMarkerFelt, 70);
    labelCardNumber->setPosition(Point(visibleSize.width/2 + 340, visibleSize.height/2 - 100));
    this->addChild(labelCardNumber);
    
    createCardSprite(visibleSize);
    
    createCardNumber();
    createCardNumber();
    
    return true;
}

void GameScene::onMenu(Ref* pSender)
{
    Director::getInstance()->replaceScene(MenuScene::createScene());
}

void GameScene::createRandomNumber() {
    int number = 2;
    int randx = rand()%4;
    int randy = rand()%4;
    log("%d, %d", randx, randy);
    
    array[0][1] = {12};
    while (array[randx][randy] != 0) {
        randx = rand()%4;
        randy = rand()%4;
        log("in while");
    }
    log("out while %d", randx*10 + randy);
    
    auto sprite = (ui::Scale9Sprite *)backgroundLayer->getChildByTag(randx*10+randy);
    auto label = Label::createWithTTF("2", kMarkerFelt, 60);
    label->setContentSize(sprite->getContentSize());
    label->setPosition(sprite->getContentSize()/2);
    label->setTag(1);
    sprite->addChild(label);
}

void GameScene::swipeAnimation() {
    
}

bool GameScene::onTouchBegan(Touch *touch, Event *unused_event)
{
//    createRandomNumber();
    Point beginTouch = touch->getLocation();
    beginX = beginTouch.x;
    beginY = beginTouch.y;
    
	return true;
}


void GameScene::onTouchEnded(Touch* touch, Event* event)
{
    Point endTouch = touch->getLocation();
    
    endX = beginX - endTouch.x;
    endY = beginY - endTouch.y;
    // Left Right
    if (abs(endX) > abs(endY)){
        if (endX + 5 > 0) {
            log("left");
            if (doLeft()) {
                createCardNumber();
            }
            doCheck();
            setScore(score);
        } else {
            log("right");
            if (doRight()) {
                createCardNumber();
            }
            doCheck();
            setScore(score);
        }
    // Up Down
    } else {
        if (endY + 5 > 0) {
            log("down");
            if (doDown()) {
                createCardNumber();
            }
            doCheck();
            setScore(score);
        } else {
            log("Up");
            if (doUp()) {
                createCardNumber();
            }
            doCheck();
            setScore(score);
        }
    }
}

void GameScene::createCardSprite(Size size) {
    int cardSize = (size.width - 36) / 4;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            auto layerCardBg = LayerColor::create(Color4B(140, 130, 120, 255));
            layerCardBg->setContentSize(Size(cardSize, cardSize));
            layerCardBg->setPosition(Point(cardSize*i+80, cardSize*j+20));
            this->addChild(layerCardBg);
            CardSprite *card = CardSprite::createCardSprite(0, cardSize, cardSize, cardSize*i+80, cardSize*j+20);
            cardArr[i][j] = card;
            this->addChild(card);
        }
    }
}
void GameScene::createCardNumber()
{
    int i = CCRANDOM_0_1() * 4;
    int j = CCRANDOM_0_1() * 4;
    
    if (cardArr[i][j]->getNumber() > 0) {
        // 이 위치에 넘버가 있는지 확인
        createCardNumber();
    } else {
        // 9:1 의 확률로 2, 4 생성
        cardArr[i][j]->setNumber(CCRANDOM_0_1() * 10 < 1 ? 4 : 2);
    }
}
void GameScene::doCheck() {
    bool isGameOver = true;
    
    // 4방면으로 움직일 수 있는지 확인
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (cardArr[x][y]->getNumber() == 0 ||
                (x < 3 && cardArr[x][y]->getNumber() == cardArr[x+1][y]->getNumber()) ||
                (x > 0 && cardArr[x][y]->getNumber() == cardArr[x-1][y]->getNumber()) ||
                (y < 3 && cardArr[x][y]->getNumber() == cardArr[x][y+1]->getNumber()) ||
                (y > 0 && cardArr[x][y]->getNumber() == cardArr[x][y-1]->getNumber())) {
                isGameOver = false;
            }
        }
    }
    if (isGameOver) {
        // 게임 오버일때 현재 신 재시작
        Director::getInstance()->replaceScene(TransitionFade::create(1, GameScene::createScene()));
    }
}
bool GameScene::doLeft() {
    bool isMove = false;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            for (int x1 = x+1; x1 < 4; x1++) {
                if (cardArr[x1][y]->getNumber() > 0) {
//                    cardArr[x1][y]->runAction(MoveBy::create(0.3, Point(-80+, 0)));
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                        x--;
                        isMove = true;
                    } else if (cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()) {
                        // 카드 두개가 같으면 합침
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        // 다른 카드는 0으로 만듬
                        cardArr[x1][y]->setNumber(0);
                        
                        score += cardArr[x][y]->getNumber();
                        isMove = true;
                    }
                    break;
                }
            }
        }
    }
    return isMove;
}
bool GameScene::doRight() {
    bool isMove = false;
    for (int y = 0; y < 4; y++) {
        for (int x = 3; x > 0; x--) {
            for (int x1 = x-1; x1 >= 0; x1--) {
                if (cardArr[x1][y]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                        x++;
                        isMove = true;
                    } else if (cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber()) {
                        // 카드 두개가 같으면 합침
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        // 다른 카드는 0으로 만듬
                        cardArr[x1][y]->setNumber(0);
                        
                        score += cardArr[x][y]->getNumber();
                        isMove = true;
                    }
                    break;
                }
            }
        }
    }
    return isMove;
}
bool GameScene::doUp() {
    bool isMove = false;
    /*
     0000
     0000
     0000
     0000
    */
    for (int x = 0; x < 4; x++) {
        for (int y = 3; y > 0; y--) {
            for (int y1 = y - 1; y1 >= 0; y1--) {
                if (cardArr[x][y1]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                        y++;
                        isMove = true;
                    } else if (cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()) {
                        // 카드 두개가 같으면 합침
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        // 다른 카드는 0으로 만듬
                        cardArr[x][y1]->setNumber(0);
                        
                        score += cardArr[x][y]->getNumber();
                        isMove = true;
                    }
                    break;
                }
            }
        }
    }
    return isMove;
}

bool GameScene::doDown() {
    bool isMove = false;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            for (int y1 = y + 1; y1 < 4; y1++) {
                if (cardArr[x][y1]->getNumber() > 0) {
                    if (cardArr[x][y]->getNumber() <= 0) {
                        cardArr[x][y]->setNumber(cardArr[x][y1]->getNumber());
                        cardArr[x][y1]->setNumber(0);
                        y--;
                        isMove = true;
                    } else if (cardArr[x][y]->getNumber() == cardArr[x][y1]->getNumber()) {
                        // 카드 두개가 같으면 합침
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber()*2);
                        // 다른 카드는 0으로 만듬
                        cardArr[x][y1]->setNumber(0);
                        
                        score += cardArr[x][y]->getNumber();
                        isMove = true;
                    }
                    break;
                }
            }
        }
    }
    return isMove;
}

void GameScene::setScore(int score)
{
    labelCardNumber->setString(__String::createWithFormat("%i", score)->getCString());
}