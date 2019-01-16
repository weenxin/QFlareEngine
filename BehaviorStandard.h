#ifndef BEHAVIORSTANDARD_H
#define BEHAVIORSTANDARD_H

#include "EnemyBehavior.h"
#include "Utils.h"

class Enemy;
class Point;

class BehaviorStandard: public EnemyBehavior
{
private:
    // logic steps
    void doUpkeep();
    virtual void findTarget();
    void checkPower();
    void checkMove();
    virtual void checkMoveStateStance();
    virtual void checkMoveStateMove();
    void updateState();
    FPoint getWanderPoint();
public:
    BehaviorStandard();

protected:
    //variables for patfinding
    std::vector<FPoint> path;
    FPoint prev_target;
    bool collided;
    bool path_found;
    int chance_calc_path;

    float hero_dist;
    float target_dist;
    FPoint pursue_pos;
    // targeting vars
    bool los;
    //when fleeing, the enemy moves away from the pursue_pos
    bool fleeing;
    bool move_to_safe_dist;
    Timer turn_timer;

public:
    explicit BehaviorStandard(Enemy *_e);
    void logic();
};

#endif // BEHAVIORSTANDARD_H
