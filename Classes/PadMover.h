#ifndef __PADMOVER_H__
#define __PADMOVER_H__

#include "Board.h"

/* Abstract class for moving pad */
class PadMover {
	public:
		virtual void moveLeft(Board *board) = 0;
		virtual void moveRight(Board *board) = 0;
		virtual void moveUp(Board *board) = 0;
		virtual void moveDown(Board *board) = 0;
};

#endif // __PADMOVER_H__
