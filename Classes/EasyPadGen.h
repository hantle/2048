#ifndef __EASYPADGEN_H__
#define __EASYPADGEN_H__

#include <time.h>
#include <stdlib.h>

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
            NumPad *pad = 0;

            srand(time(NULL));
            while(true) 
            {
                r = rand() % size;
                c = rand() % size;

                pad = board->getNumPad(r, c);

                if(pad->getNum() == 0)
                    break;
            }
            printf("genPad at (%d, %d)\n", r, c);
            if(pad != 0)
            {
                pad->setAniType(AniType::GEN);
                pad->setNum(Board::BASE);
            }
        };
};

#endif // __EASYPADGEN_H__
