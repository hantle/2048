#ifndef __EASYPADGEN_H__
#define __EASYPADGEN_H__

#include "PadGen.h"
#include "Board.h"

class Board;
class EasyPadGen : PadGen {
	void gen(Board *board) {
		// EasyPadGen always create minimum number at random pos.
	};
};

#endif // __EASYPADGEN_H__
