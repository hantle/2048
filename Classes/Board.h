#ifndef __BOARD_H__
#define __BOARD_H__

#include "NumPad.h"
#include "PadMover.h"
#include "PadGen.h"

typedef NumPad* pNumPad;

class Board {
    private:
        pNumPad **mBoard;
        int mSize;
        PadMover *mMover;
        PadGen *mGen;

        bool tryMerge(NumPad *m, NumPad *d);
        void genPad();
    public:
        static const int _4BY4 = 4;
        static const int _6BY6 = 6;
        static const int _8BY8 = 8;

        static int BASE;

        Board(int size);
        void reset();
        int getSize() { return mSize; };
        NumPad *getNumPad(int row, int col) { return mBoard[row][col]; }
        //void setNum(int row, int col, int val) { mBoard[row][col]->mNum = val; }
        void setMover(PadMover *mover);
        /* merge two NumPad into one by adding d into m. 
           And then d will be removed */
        int merge(NumPad *m, NumPad *d);
        int moveLeft();
        int moveRight();
        int moveUp();
        int moveDown();
        void setGen(PadGen *gen);

        // should be called after move
        // it return false when game was finished
        bool doNext(bool gen);
        bool isFinish();
        bool isFull();

    protected:
        ~Board();
};

#endif // __BOARD_H__
