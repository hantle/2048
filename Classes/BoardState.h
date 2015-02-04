#ifndef __BOARDSTATE_H__
#define __BOARDSTATE_H__

#include "Board.h"

class BoardState {
    private:
        int mScore;

    public:
        BoardState() {};
        BoardState(Board &board);
};

#endif // __BOARDSTATE_H__
