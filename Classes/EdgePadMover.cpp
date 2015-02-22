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
int EdgePadMover::checkMove(Board *board, int r1, int c1, Dir dir)
{
    NumPad *pad1 = board->getNumPad(r1, c1);
    //NumPad *pad2 = board->getNumPad(r2, c2);

    if(pad1->getNum() == 0) return -1;

    // move
    // from pad1 to pad2
    NumPad *pad2 = 0;
    if(dir == Dir::LEFT) {
        for(int i = 0 ; i < c1 ; i++) {
            //left pad
            NumPad *pad  = board->getNumPad(r1, i);
            if(pad->getNum() == 0) {
                pad2 = pad;
                break;
            } else {
                int p = board->merge(pad, pad1);
                if(p > 0) {
                    pad2 = pad;
                    return p;
                }
            }
        }
        // no move
        if(pad2 == 0) return -1;
        
        // move
        pad2->setAni(AniType::MOVE, pad1);
        return 0;
    } else if(dir == Dir::RIGHT) {
        int size = board->getSize();
        for(int i = size - 1 ; i > c1 ; i--) {
            //left pad
            NumPad *pad  = board->getNumPad(r1, i);
            if(pad->getNum() == 0) {
                pad2 = pad;
                break;
            } else {
                int p = board->merge(pad, pad1);
                if(p > 0) {
                    pad2 = pad;
                    return p;
                }
            }
        }
        // no move
        if(pad2 == 0) return -1;
        
        // move
        pad2->setAni(AniType::MOVE, pad1);
        return 0;
    } else if(dir == Dir::UP) {
        int size = board->getSize();
        for(int i = size - 1 ; i > r1 ; i--) {
            //left pad
            NumPad *pad  = board->getNumPad(i, c1);
            if(pad->getNum() == 0) {
                pad2 = pad;
                break;
            } else {
                int p = board->merge(pad, pad1);
                if(p > 0) {
                    pad2 = pad;
                    return p;
                }
            }
        }
        // no move
        if(pad2 == 0) return -1;
        
        // move
        pad2->setAni(AniType::MOVE, pad1);
        return 0;
    } else if(dir == Dir::DOWN) {
        for(int i = 0 ; i < r1 ; i++) {
            //left pad
            NumPad *pad  = board->getNumPad(i, c1);
            if(pad->getNum() == 0) {
                pad2 = pad;
                break;
            } else {
                int p = board->merge(pad, pad1);
                if(p > 0) {
                    pad2 = pad;
                    return p;
                }
            }
        }
        // no move
        if(pad2 == 0) return -1;
        
        // move
        pad2->setAni(AniType::MOVE, pad1);
        return 0;
    }
}

int EdgePadMover::moveLeft(Board *board)
{
    int size = board->getSize();
    bool move = false;
    int point = -1;

    for(int r = 0 ; r < size ; r++) {
        for(int c = 0 ; c < size ; c++) {
            // edge
            if(c == 0) continue;

            int ret = checkMove(board, r, c, Dir::LEFT);

            // nothing to move
            if(ret == -1) continue;

            // move
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

            int ret = checkMove(board, r, c, Dir::RIGHT);

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

            int ret = checkMove(board, r, c, Dir::UP);

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

            int ret = checkMove(board, r, c, Dir::DOWN);

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
