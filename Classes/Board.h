#ifndef __BOARD_H__
#define __BOARD_H__

#include "NumPad.h"
#include "PadGen.h"
#include "PadMover.h"
#include "PadGen.h"
using namespace std;

class Board {
	private:
		NumPad **mBoard;
		int mSize;
		PadMover *mMover;
		PadGen *mGen;

		/* merge two NumPad into one by adding d into m. 
		   And then d will be removed */
		void merge(NumPad *m, NumPad *d);
		void genPad();
	public:
    static int _4BY4;// = 4;
    static int _6BY6;// = 6;

		Board(int size);
		void setMover(PadMover *mover);
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
    void setGen(PadGen *gen);
	protected:
		~Board() {};
};
#endif // __BOARD_H__
