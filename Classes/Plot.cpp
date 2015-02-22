//
//  Plot.cpp
//  2048
//
//  Created by Macbook on 2015. 2. 11..
//
//

#include "Plot.h"


Plot* Plot::createPlot(int no) {
    
    Plot *plot = new Plot();
    plot->fromX = -1;
    plot->fromY = -1;
    plot->toX = -1;
    plot->toY = -1;
    plot->fromNo = no;
    plot->toNo = no;
    plot->isMerge = false;
    
    if (plot) {
        return plot;
    }
    do { delete (plot); (plot) = nullptr; } while(0);
    return NULL;
}

void Plot::setFrom(int x, int y) {
    fromX = x;
    fromY = y;
}

void Plot::setTarget(int x, int y) {
    toX = x;
    toY = y;
}

void Plot::setMerge(bool merge) {
    isMerge = merge;
}

void Plot::setFromTo(int from, int to) {
    fromNo = from;
    toNo = to;
}