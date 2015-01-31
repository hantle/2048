#ifndef __EASYPADGEN_H__
#define __EASYPADGEN_H__

#include "PadGen.h"
#include "Board.h"

class Board;
class EasyPadGen : public PadGen {
    public:
        EasyPadGen() {};
        void gen(Board *board) {
            // EasyPadGen always create minimum number at random pos.
            int size = board->getSize();
            int r, c;

            while(true) 
            {
                r = random() % size;
                c = random() % size;

                NumPad pad = board->getNumPad(r, c);

                if(pad.mNum == 0)
                    break;
            }
            printf("genPad at (%d, %d)\n", r, c);
            board->setNum(r, c, 2);
        };
};

#endif // __EASYPADGEN_H__
