#ifndef __PADGEN_H__
#define __PADGEN_H__

#include "Board.h"

class PadGen {
	public:
		virtual void gen(Board *board) = 0;
};

#endif // __PADGEN_H__
