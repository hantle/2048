#ifndef __BOARD_H__
#define __BOARD_H__

#include "NumPad.h"
#include "PadMover.h"
#include "PadGen.h"

typedef NumPad* pNumPad;

class Board {
    public:
        class State {
            private:
                int mPoint;
                int mSize;
                int **mPad;

                State() {};
            public:
                State(Board *b);
                State(State &s);
        };
    private:
        pNumPad **mBoard;
        int mSize;
        int mPoint;
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
        Board(Board &board);

        void reset();
        int getSize() { return mSize; };
        int getPoint() { return mPoint; };

        Board::State *getState();
        void setState(Board::State *bs);

        NumPad *getNumPad(int row, int col) { return mBoard[row][col]; }
        //void setNum(int row, int col, int val) { mBoard[row][col]->mNum = val; }
        void setMover(PadMover *mover);
        /* merge two NumPad into one by adding d into m. 
           And then d will be removed */
        int merge(NumPad *m, NumPad *d);
        bool moveLeft();
        bool moveRight();
        bool moveUp();
        bool moveDown();
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
