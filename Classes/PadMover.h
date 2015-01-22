#ifndef __PADMOVER_H__
#define __PADMOVER_H__

#include "Board.h"

/* Abstract class for moving pad */
class Board;
class PadMover {
	public:
		virtual int moveLeft(Board *board) = 0;
		virtual int moveRight(Board *board) = 0;
		virtual int moveUp(Board *board) = 0;
		virtual int moveDown(Board *board) = 0;
};

#endif // __PADMOVER_H__
