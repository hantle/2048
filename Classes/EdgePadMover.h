#ifndef __EDGEPADMOVER_H__
#define __EDGEPADMOVER_H__

#include "Board.h"
#include "NumPad.h"
#include "PadMover.h"

class Board;

// Egde means this PadMover move all pad to end to end
// but, now only move one for testing
class EdgePadMover : public PadMover {
	public:
		int moveLeft(Board *board) 
		{
            int size = board->getSize();

            for(int r = 0 ; r < size ; r++) {
                for(int c = 0 ; c < size ; c++) {
                    NumPad pad1 = board->getNumPad(r, c);
                    if(pad1.mNum != 0) {
                        // check collision
                        //

                        if(c == 0) continue;

                        board->setNum(r, c - 1, pad1.mNum);
                        board->setNum(r, c, 0);
                    }
                }
            }

            return 0;
		};

		int moveRight(Board *board) 
		{
            int size = board->getSize();

            for(int r = 0 ; r < size ; r++) {
                for(int c = size - 1 ; c >= 0 ; c--) {
                    NumPad pad1 = board->getNumPad(r, c);
                    if(pad1.mNum != 0) {
                        // check collision
                        //

                        if(c == size - 1) continue;

                        board->setNum(r, c + 1, pad1.mNum);
                        board->setNum(r, c, 0);
                    }
                }
            }

            return 0;
		};

        int moveUp(Board *board)
        {
            return 0;
        }

        int moveDown(Board *board)
        {
            return 0;
        }
};

#endif // __EDGEPADMOVER_H__
