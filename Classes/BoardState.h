#ifndef __BOARDSTATE_H__
#define __BOARDSTATE_H__

#include "Board.h"

// Memento object
class BoardState {
    private:
        int mScore;
        int mSize;
        int **mPad;

        BoardState() {};

    public:
        BoardState(BoardState &bs);
        BoardState(Board *board);

        ~BoardState();
};

#endif // __BOARDSTATE_H__
