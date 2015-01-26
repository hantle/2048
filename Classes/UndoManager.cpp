#include "UndoManager.h"
#include "BoardState.h"

BoardState UndoManager::popState()
{
    BoardState ret;
    mMax--;

    ret = mState.back();
    mState.pop_back();
    return ret;
}

void UndoManager::putState(BoardState state)
{
    if(mMax == 0) return;

    if(mState.empty()) 
    {
        mState.push_back(state);
        return;
    }

    mState.erase(mState.begin());
    mState.push_back(state);
}

