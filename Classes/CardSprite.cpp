//
//  CardSprite.cpp
//  2048
//
//  Created by Macbook on 2015. 1. 22..
//
//

#include "CardSprite.h"
#include "Define.h"

USING_NS_CC;

CardSprite *CardSprite::createCardSprite(int number, int width, int height, float x, float y)
{
    CardSprite *card = new CardSprite();
    if (card && card->init()) {
        card->autorelease();
        card->cardInit(number, width, height, x, y);
        return card;
    }
    CC_SAFE_DELETE(card);
    return NULL;
}

bool CardSprite::init()
{
    if (!Sprite::init()) {
        return false;
    }
    return true;
}

int CardSprite::getNumber()
{
    return number;
}

void CardSprite::setNumber(int num)
{
    number = num;
    
    if (num > 0) {
        labelCardNumber->setString(__String::createWithFormat("%i", number)->getCString());
        
        if (num < 16) {
            labelCardNumber->setSystemFontSize(100);
        } else if (num < 128) {
            labelCardNumber->setSystemFontSize(90);
        } else if (num < 1024) {
            labelCardNumber->setSystemFontSize(60);
        } else {
            labelCardNumber->setSystemFontSize(40);
        }
    } else {
        labelCardNumber->setString("");
    }
    
    if (number == 0) {
        colorBackground->setColor(Color3B(200, 190, 180));
    } else if (number == 2) {
        colorBackground->setColor(Color3B(240, 230, 220));
    } else if (number == 4) {
        colorBackground->setColor(Color3B(240, 220, 200));
    } else if (number == 8) {
        colorBackground->setColor(Color3B(240, 180, 120));
    } else if (number == 16) {
        colorBackground->setColor(Color3B(240, 140, 90));
    } else if (number == 32) {
        colorBackground->setColor(Color3B(240, 120, 90));
    } else if (number == 64) {
        colorBackground->setColor(Color3B(240, 90, 60));
    } else if (number == 128) {
        colorBackground->setColor(Color3B(240, 90, 60));
    } else if (number == 256) {
        colorBackground->setColor(Color3B(240, 200, 70));
    } else if (number == 512) {
        colorBackground->setColor(Color3B(240, 200, 70));
    } else if (number == 1024) {
        colorBackground->setColor(Color3B(0, 130, 0));
    } else if (number == 2048) {
        colorBackground->setColor(Color3B(0, 130, 0));
    }
}

void CardSprite::cardInit(int number, int width, int height, float x, float y)
{
    this->number = number;
    colorBackground = LayerColor::create(Color4B(200, 190, 180, 255), width-15, height-15);
    colorBackground->setPosition(Point(x, y));
    
    if (number > 0) {
        labelCardNumber = Label::createWithTTF(__String::createWithFormat("%i", number)->getCString(), kMarkerFelt, 100);
        labelCardNumber->setPosition(Point(colorBackground->getContentSize().width/2, colorBackground->getContentSize().height/2));
        labelCardNumber->setTag(8);
        colorBackground->addChild(labelCardNumber);
    } else {
        labelCardNumber = Label::createWithTTF("", kMarkerFelt, 100);
        labelCardNumber->setPosition(colorBackground->getContentSize().width/2, colorBackground->getContentSize().height/2);
        labelCardNumber->setTag(8);
        colorBackground->addChild(labelCardNumber);
    }
    
    this->addChild(colorBackground);
}