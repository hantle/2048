#include "BoardState.h"

BoardState::BoardState(BoardState &bs)
{
}

BoardState::BoardState(Board *board)
{
    mScore = board->getPoint();
    mSize = board->getSize();

    mPad = new int *[mSize];

    for(int r = 0 ; r < mSize ; r++) {
        mPad[r] = new int[mSize];
        for(int c = 0 ; c < mSize ; c++) {
            mPad[r][c] = board->getNumPad(r, c)->getNum();
        }
    }
}

BoardState::~BoardState()
{
    //
    delete mPad;
}
