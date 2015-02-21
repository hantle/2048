#ifndef __UNDOMANAGER_H__
#define __UNDOMANAGER_H__

#include <vector>
#include "Board.h"

#define MAX_UNDO 5

class UndoManager {
    private:
        std::vector<Board::State *> mState;
        int mMax;

    public:
        UndoManager() { mMax = MAX_UNDO; };
        Board::State *popState();
        void putState(Board::State *state);
        void clear();
        int getUndoCount() { return mMax; }

        ~UndoManager();
};

#endif // __UNDOMANAGER_H__
