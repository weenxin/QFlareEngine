#ifndef ENEMY_H
#define ENEMY_H

#include "CommonIncludes.h"
#include "Entity.h"
#include "Utils.h"

class EnemyBehavior;

class Enemy: public Entity
{
public:
    Enemy();
    Enemy(const Enemy& e);
    Enemy& operator=(const Enemy& e);
    ~Enemy();
    void logic();
    unsigned char faceNextBest(float mapx, float mapy);
    virtual void doRewards(int source_type);

    std::string type;

    Renderable getRender();

    EnemyBehavior *eb;

    // other flags
    bool reward_xp;
    bool instant_power;
    int kill_source_type;
};

#endif // ENEMY_H
