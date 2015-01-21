#include "Board.h"
#include "PadMover.h"
#include "NumPad.h"

Board::Board(int size) 
{
	mSize = size;
	mMover = 0; 

	mBoard = new NumPad*[size];
	for(int i = 0 ; i < size ; i++) {
		mBoard[i] = *new NumPad*[size];
	}
}

void Board::setMover(PadMover *mover) 
{
	mMover = mover;
}

void Board::setGen(PadGen *gen)
{
	mGen = gen;
}

void Board::moveLeft()
{
	if(mMover == 0) return;
	mMover->moveLeft(this);
}

void Board::moveRight()
{
	if(mMover == 0) return;
	mMover->moveRight(this);
}

void Board::moveUp()
{
	if(mMover == 0) return;
	mMover->moveUp(this);
}

void Board::moveDown()
{
	if(mMover == 0) return;
	mMover->moveDown(this);
}

void Board::merge(NumPad *m, NumPad *d)
{
	m->mNum += d->mNum;

	d->mNum = 0;
}

void Board::genPad()
{
	mGen->gen(this);
}
