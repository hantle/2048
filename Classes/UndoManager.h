#ifndef __UNDOMANAGER_H__
#define __UNDOMANAGER_H__

#include <vector>
#include "BoardState.h"

#define MAX_UNDO 5

class UndoManager {
    private:
        std::vector<BoardState> mState;
        int mMax;

    public:
        UndoManager() { mMax = MAX_UNDO; };
        BoardState popState();
        void putState(BoardState state);
        int getUndoCount() { return mMax; }
};

#endif // __UNDOMANAGER_H__
