#ifndef ENTITY_H
#define ENTITY_H

#include "CommonIncludes.h"
#include "StatBlock.h"
#include "Utils.h"

class Animation;
class AnimationSet;

class Entity
{
protected:
    Image *sprites;

    void move_from_offending_tile();
    virtual void resetActiveAnimation();
public:
    enum {
        SOUND_HIT = 0,
        SOUND_DIE = 1,
        SOUND_CRITDIE = 2,
        SOUND_BLOCK = 3
    };

    Entity();
    Entity(const Entity& e);
    Entity& operator=(const Entity& e);
    virtual ~Entity();

    void loadSounds();
    void loadSoundsFromStatBlock(StatBlock *src_stats);
    void unloadSounds();
    void playAttackSound(const std::string& attack_name);
    void playSound(int sound_type);
    bool move();
    bool takeHit(Hazard &h);
    virtual void doRewards(int) {}


    // sound effects
    std::vector<std::pair<std::string, std::vector<SoundID> > > sound_attack;
    std::vector<SoundID> sound_hit;
    std::vector<SoundID> sound_die;
    std::vector<SoundID> sound_critdie;
    std::vector<SoundID> sound_block;
    SoundID sound_levelup;

    bool setAnimation(const std::string& animation);
    Animation *activeAnimation;
    AnimationSet *animationSet;

    StatBlock stats;

};


extern const int directionDeltaX[];
extern const int directionDeltaY[];
extern const float speedMultiplyer[];


#endif // ENTITY_H
