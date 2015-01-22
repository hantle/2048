#include "Board.h"
#include "PadMover.h"
#include "NumPad.h"

Board::Board(int size) 
{
	mSize = size;
	mMover = 0; 

	mBoard = new NumPad*[size];
	for(int i = 0 ; i < size ; i++) {
		mBoard[i] = new NumPad[size];
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

bool Board::tryMerge(NumPad *m, NumPad *d)
{
	if(m->mNum == d->mNum) return true;
	return false;
}

int Board::merge(NumPad *m, NumPad *d)
{
	if(tryMerge(m, d))
	{
		m->mNum += d->mNum;
		d->mNum = 0;
	}
}

void Board::genPad()
{
	mGen->gen(this);
}

bool Board::isFinish()
{
	// check all neighbor pad
	// if there is mergable pad, then return false
	// this method should be invoked after isFull check
	return false;
}

bool Board::isFull()
{
	// check board is full of numpad
	return false;
}

NumPad& Board::operator[](int row)
{
	return *mBoard[row];
}

bool Board::doNext()
{
	genPad();
	if(isFull()) {
		if(isFinish()) return false;
	}
	return true;
}

