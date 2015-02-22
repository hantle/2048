#include "Board.h"
#include "EdgePadMover.h"

// -1 == no move at all
// > 0 == move
int EdgePadMover::calcPoint(int point, bool move)
{
    if(point == -1 && move) point = 0;
    else if(point > 0) point += 1;

    return point;
}

// return
// -1 no move
// 0 move
// > 0 merged
int EdgePadMover::checkMove(Board *board, int r1, int c1, int r2, int c2)
{
    NumPad *pad1 = board->getNumPad(r1, c1);
    NumPad *pad2 = board->getNumPad(r2, c2);

    if(pad1->getNum() == 0) return -1;

    // move
    // from pad1 to pad2
    if(pad2->getNum() == 0) {
        pad2->setAni(AniType::MOVE, pad1);
        //pad2->setNum(pad1->getNum());
        //pad1->setNum(0);
        return 0;
    }

    int p = board->merge(pad2, pad1);
    if(p > 0) return p;
    else return -1;
}

int EdgePadMover::moveLeft(Board *board)
{
    int size = board->getSize();
    bool move = false;
    int point = -1;

    for(int r = 0 ; r < size ; r++) {
        for(int c = 0 ; c < size ; c++) {
            if(c == 0) continue;

            int ret = checkMove(board, r, c, r, c-1);

            if(ret == -1) continue;
            if(ret == 0) {
                move = true;
                continue;
            }
            if(ret > 0) point += ret;
        }
    }

    return calcPoint(point, move);
};

int EdgePadMover::moveRight(Board *board) 
{
    int size = board->getSize();
    bool move = false;
    int point = -1;

    for(int r = 0 ; r < size ; r++) {
        for(int c = size - 1 ; c >= 0 ; c--) {
            if(c == size - 1) continue;

            int ret = checkMove(board, r, c, r, c+1);

            if(ret == -1) continue;
            if(ret == 0) {
                move = true;
                continue;
            }
            if(ret > 0) point += ret;
        }
    }

    return calcPoint(point, move);
};

int EdgePadMover::moveUp(Board *board)
{
    int size = board->getSize();
    bool move = false;
    int point = -1;

    for(int c = 0 ; c < size ; c++) {
        for(int r = size - 1 ; r >= 0 ; r--) {
            if(r == size - 1) continue;

            int ret = checkMove(board, r, c, r+1, c);

            if(ret == -1) continue;
            if(ret == 0) {
                move = true;
                continue;
            }
            if(ret > 0) point += ret;
        }
    }

    return calcPoint(point, move);
}

int EdgePadMover::moveDown(Board *board)
{
    int size = board->getSize();
    bool move = false;
    int point = -1;

    for(int c = 0 ; c < size ; c++) {
        for(int r = 0 ; r < size ; r++) {
            if(r == 0) continue;

            int ret = checkMove(board, r, c, r-1, c);

            if(ret == -1) continue;
            if(ret == 0) {
                move = true;
                continue;
            }
            if(ret > 0) point += ret;
        }
    }

    return calcPoint(point, move);
}
