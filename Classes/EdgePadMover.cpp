#include "Board.h"
#include "EdgePadMover.h"

int EdgePadMover::moveLeft(Board *board)
{
    int size = board->getSize();
    int point = 0;

    for(int r = 0 ; r < size ; r++) {
        for(int c = 0 ; c < size ; c++) {
            NumPad pad1 = board->getNumPad(r, c);
            if(pad1.mNum != 0) {
                if(c == 0) continue;

                // check collision
                NumPad pad2 = board->getNumPad(r, c - 1);
                if(pad2.mNum != 0 && pad2.mNum == pad1.mNum) 
                {
                    board->setNum(r, c - 1, pad1.mNum + pad2.mNum);
                    board->setNum(r, c, 0);
                    point += pad2.mNum;

                    continue;
                }

                if(pad2.mNum != 0 && pad2.mNum != pad1.mNum) continue;

                board->setNum(r, c - 1, pad1.mNum);
                board->setNum(r, c, 0);
            }
        }
    }

    return 0;
};

int EdgePadMover::moveRight(Board *board) 
{
    int size = board->getSize();
    int point = 0;

    for(int r = 0 ; r < size ; r++) {
        for(int c = size - 1 ; c >= 0 ; c--) {
            NumPad pad1 = board->getNumPad(r, c);
            if(pad1.mNum != 0) {
                if(c == size - 1) continue;

                // check collision
                NumPad pad2 = board->getNumPad(r, c + 1);
                if(pad2.mNum != 0 && pad2.mNum == pad1.mNum) 
                {
                    board->setNum(r, c + 1, pad1.mNum + pad2.mNum);
                    board->setNum(r, c, 0);
                    point += pad2.mNum;

                    continue;
                }

                if(pad2.mNum != 0 && pad2.mNum != pad1.mNum) continue;

                board->setNum(r, c + 1, pad1.mNum);
                board->setNum(r, c, 0);
            }
        }
    }

    return point;
};

int EdgePadMover::moveUp(Board *board)
{
    int size = board->getSize();
    int point = 0;

    for(int c = 0 ; c < size ; c++) {
        for(int r = size - 1 ; r >= 0 ; r--) {
            NumPad pad1 = board->getNumPad(r, c);
            if(pad1.mNum != 0) {
                if(r == size - 1) continue;

                // check collision
                NumPad pad2 = board->getNumPad(r + 1, c);
                if(pad2.mNum != 0 && pad2.mNum == pad1.mNum) 
                {
                    board->setNum(r + 1, c, pad1.mNum + pad2.mNum);
                    board->setNum(r, c, 0);
                    point += pad2.mNum;

                    continue;
                }

                if(pad2.mNum != 0 && pad2.mNum != pad1.mNum) continue;

                board->setNum(r + 1, c, pad1.mNum);
                board->setNum(r, c, 0);
            }
        }
    }

    return point;
}

int EdgePadMover::moveDown(Board *board)
{
    int size = board->getSize();
    int point = 0;

    for(int c = 0 ; c < size ; c++) {
        for(int r = 0 ; r < size ; r++) {
            NumPad pad1 = board->getNumPad(r, c);
            if(pad1.mNum != 0) {
                if(r == 0) continue;

                // check collision
                NumPad pad2 = board->getNumPad(r - 1, c);
                if(pad2.mNum != 0 && pad2.mNum == pad1.mNum) 
                {
                    board->setNum(r - 1, c, pad1.mNum + pad2.mNum);
                    board->setNum(r, c, 0);
                    point += pad2.mNum;

                    continue;
                }

                if(pad2.mNum != 0 && pad2.mNum != pad1.mNum) continue;

                board->setNum(r - 1, c, pad1.mNum);
                board->setNum(r, c, 0);
            }
        }
    }

    return point;
}
