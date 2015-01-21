#include "Board.h"
#include "PadMover.h"
#include "NumPad.h"

Board::Board(int size) 
{
	mSize = size;
	mMover = NULL; 

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
	if(mMover == NULL) return;
	mMover->moveLeft(this);
}

void Board::moveRight()
{
	if(mMover == NULL) return;
	mMover->moveRight(this);
}

void Board::moveUp()
{
	if(mMover == NULL) return;
	mMover->moveUp(this);
}

void Board::moveDown()
{
	if(mMover == NULL) return;
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
