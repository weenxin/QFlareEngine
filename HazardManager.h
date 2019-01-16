#ifndef HAZARDMANAGER_H
#define HAZARDMANAGER_H
/**
 * class HazardManager
 *
 * Holds the collection of hazards (active attacks, spells, etc) and handles group operations
 */

#include "CommonIncludes.h"
#include "Utils.h"

class Avatar;
class Enemy;
class Hazard;
class HazardManager {
private:
    void hitEntity(size_t index, const bool hit);

public:
    HazardManager();
    ~HazardManager();
    void logic();
    void checkNewHazards();
    void handleNewMap();
    void addRenders(std::vector<Renderable> &r, std::vector<Renderable> &r_dead);

    std::vector<Hazard*> h;
    Enemy* last_enemy;
};

#endif // HAZARDMANAGER_H
