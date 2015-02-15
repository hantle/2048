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

int EdgePadMover::moveLeft(Board *board)
{
    int size = board->getSize();
    bool move = false;
    int point = -1;

    for(int r = 0 ; r < size ; r++) {
        for(int c = 0 ; c < size ; c++) {
            const NumPad *pad1 = board->getNumPad(r, c);
            if(pad1->mNum != 0) {
                if(c == 0) continue;

                const NumPad *pad2 = board->getNumPad(r, c - 1);
                // check collision
                if(pad2->mNum != 0 && pad2->mNum == pad1->mNum) 
                {
                    board->setNum(r, c - 1, pad1->mNum + pad2->mNum);
                    board->setNum(r, c, 0);
                    point += pad2->mNum;

                    continue;
                }

                // no move
                if(pad2->mNum != 0 && pad2->mNum != pad1->mNum) continue;

                // move
                board->setNum(r, c - 1, pad1->mNum);
                board->setNum(r, c, 0);
                move = true;
            }
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
            const NumPad *pad1 = board->getNumPad(r, c);
            if(pad1->mNum != 0) {
                if(c == size - 1) continue;

                // check collision
                const NumPad *pad2 = board->getNumPad(r, c + 1);
                if(pad2->mNum != 0 && pad2->mNum == pad1->mNum) 
                {
                    board->setNum(r, c + 1, pad1->mNum + pad2->mNum);
                    board->setNum(r, c, 0);
                    point += pad2->mNum;

                    continue;
                }

                if(pad2->mNum != 0 && pad2->mNum != pad1->mNum) continue;

                board->setNum(r, c + 1, pad1->mNum);
                board->setNum(r, c, 0);
                move = true;
            }
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
            const NumPad *pad1 = board->getNumPad(r, c);
            if(pad1->mNum != 0) {
                if(r == size - 1) continue;

                // check collision
                const NumPad *pad2 = board->getNumPad(r + 1, c);
                if(pad2->mNum != 0 && pad2->mNum == pad1->mNum) 
                {
                    board->setNum(r + 1, c, pad1->mNum + pad2->mNum);
                    board->setNum(r, c, 0);
                    point += pad2->mNum;

                    continue;
                }

                if(pad2->mNum != 0 && pad2->mNum != pad1->mNum) continue;

                board->setNum(r + 1, c, pad1->mNum);
                board->setNum(r, c, 0);
                move = true;
            }
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
            const NumPad *pad1 = board->getNumPad(r, c);
            if(pad1->mNum != 0) {
                if(r == 0) continue;

                // check collision
                const NumPad *pad2 = board->getNumPad(r - 1, c);
                if(pad2->mNum != 0 && pad2->mNum == pad1->mNum) 
                {
                    board->setNum(r - 1, c, pad1->mNum + pad2->mNum);
                    board->setNum(r, c, 0);
                    point += pad2->mNum;

                    continue;
                }

                if(pad2->mNum != 0 && pad2->mNum != pad1->mNum) continue;

                board->setNum(r - 1, c, pad1->mNum);
                board->setNum(r, c, 0);
                move = true;
            }
        }
    }

    return calcPoint(point, move);
}
