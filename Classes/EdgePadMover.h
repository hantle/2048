#ifndef __EDGEPADMOVER_H__
#define __EDGEPADMOVER_H__

#include "Board.h"
#include "NumPad.h"
#include "PadMover.h"

class Board;

// Egde means this PadMover move all pad to end to end
// but, now only move one for testing
class EdgePadMover : public PadMover {
    private:
        int checkMove(Board *board, int r1, int c1, int r2, int c2);
        int calcPoint(int point, bool move);

	public:
        EdgePadMover() {};

		int moveLeft(Board *board);
		int moveRight(Board *board);
        int moveUp(Board *board);
        int moveDown(Board *board);

    protected:
        ~EdgePadMover() {};
};

#endif // __EDGEPADMOVER_H__
