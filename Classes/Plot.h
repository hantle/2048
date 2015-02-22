//
//  Plot.h
//  2048
//
//  Created by Macbook on 2015. 2. 11..
//
//

#ifndef ___048__Plot__
#define ___048__Plot__

#include <stdio.h>


class Plot
{
public:
    static Plot* createPlot(int fromNo);
    
    int fromX, fromY;
    int toX, toY;
    int fromNo, toNo;
    bool isMerge;
    
    void setTarget(int x, int y);
    void setFrom(int x, int y);
    void setMerge(bool merge);
    void setFromTo(int from, int to);
private:
};


#endif /* defined(___048__Plot__) */
