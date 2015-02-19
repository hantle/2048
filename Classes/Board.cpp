#include <stdio.h>

#include "Board.h"

int Board::BASE = 2;

Board::Board(int size) 
{
    mSize = size;
    mMover = 0; 
    mGen = 0;

    mBoard = new pNumPad*[size];
    for(int i = 0 ; i < size ; i++) {
        mBoard[i] = new pNumPad[size];
        for(int j = 0 ; j < size ; j++) {
            NumPad *pad = mBoard[i][j] = new NumPad();
        }
    }
}

Board::~Board()
{
    //
}

void Board::reset() 
{
    // initialize
    genPad();
    genPad();
}

void Board::setMover(PadMover *mover) 
{
    mMover = mover;
}

void Board::setGen(PadGen *gen)
{
    mGen = gen;
}

int Board::moveLeft()
{
    if(mMover == 0) return 0;
    return mMover->moveLeft(this);
}

int Board::moveRight()
{
    if(mMover == 0) return 0;
    return mMover->moveRight(this);
}

int Board::moveUp()
{
    if(mMover == 0) return 0;
    return mMover->moveUp(this);
}

int Board::moveDown()
{
    if(mMover == 0) return 0;
    return mMover->moveDown(this);
}

bool Board::tryMerge(NumPad *m, NumPad *d)
{
    int mnum = m->getNum();
    int dnum = d->getNum();
    if(mnum == dnum && mnum != 0) return true;
    return false;
}

int Board::merge(NumPad *m, NumPad *d)
{
    if(tryMerge(m, d))
    {
        int pt = m->getNum() + d->getNum();
        m->setNum(pt);
        d->setNum(0);

        d->setAniType(AniType::MERGING);
        return pt;
    }

    return 0;
}

void Board::genPad()
{
    if(mGen == 0) return;
    mGen->gen(this);
}

bool Board::isFinish()
{
    bool finish = true;
    // check all neighbor pad
    // if there is mergable pad, then return false
    // this method should be invoked after isFull check
    for(int r = 0 ; r < mSize ; r++) {
        for(int c = 1 ; c < mSize ; c++) {
            if(mBoard[r][c]->getNum() == mBoard[r][c-1]->getNum()) {
                finish = false;
                break;
            }
        }
    }

    for(int c = 0 ; c < mSize ; c++) {
        for(int r = 1 ; r < mSize ; r++) {
            if(mBoard[r][c]->getNum() == mBoard[r-1][c]->getNum()) {
                finish = false;
                break;
            }
        }
    }
    return finish;
}

bool Board::isFull()
{
    bool full = true;

    for(int i = 0 ; i < mSize ; i++) {
        for(int j = 0 ; j < mSize ; j++) {
            if(mBoard[i][j]->getNum() == 0) {
                full = false;
                break;
            }
        }
    }
    return full;
}

bool Board::doNext(bool gen)
{
    if(isFull()) {
        printf("isFull() return true\n");
        if(isFinish()) return false;
    } else {
        if(gen) {
            genPad();
            // check full again after genPad()
            if(isFull()) {
                printf("isFull() return true\n");
                if(isFinish()) return false;
            }
        }
    }
    return true;
}
