#ifndef ASTARNODE_H
#define ASTARNODE_H

#include <list>
#include "Utils.h"

const int node_stride = 1; // minimal stride between nodes

class AStarNode
{
protected:
    // position
    int x;
    int y;

    // exact cost from first Node
    float g;
    // cost to last node
    float h;
    // Parent is where this Node come from.
    Point parent;

public:
    AStarNode();
    explicit AStarNode(const Point &p);

    int getX() const;
    int getY() const;
    float getH() const;

    Point getParent() const;
    void setParent(const Point& p);

    // return a list of coordinates of all neighbours
    std::list<Point> getNeighbours(int limitX=0, int limitY=0) const;

    float getActualCost() const;
    void setActualCost(const float G);

    void setEstimatedCost(const float H);

    float getFinalCost() const;

    bool operator<(const AStarNode& n) const;
    bool operator==(const AStarNode& n) const;
    bool operator==(const Point& p) const;
    bool operator!=(const Point& p) const;
};

#endif // ASTARNODE_H
