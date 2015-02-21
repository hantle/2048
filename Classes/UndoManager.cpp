#include "UndoManager.h"

UndoManager::~UndoManager()
{
}

Board::State *UndoManager::popState()
{
    Board::State *ret;
    mMax--;

    ret = mState.back();
    mState.pop_back();
    return ret;
}

void UndoManager::putState(Board::State *state)
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

void UndoManager::clear()
{
    mState.clear();
}
