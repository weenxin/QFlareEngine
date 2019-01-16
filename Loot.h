#ifndef LOOT_H
#define LOOT_H

#include "CommonIncludes.h"
#include "ItemManager.h"
#include "TooltipData.h"


class Animation;

class Loot {
private:
    std::string gfx;

public:
    ItemStack stack;
    FPoint pos;
    Animation *animation;
    TooltipData tip;
    Rect tip_bounds;
    bool tip_visible;
    bool dropped_by_hero;
    bool on_ground;
    bool sound_played;

    Loot();
    Loot(const Loot &other);
    Loot& operator= (const Loot &other);
    ~Loot();

    void loadAnimation(const std::string& _gfx);

    /**
     * If an item is flying, it hasn't completed its "flying loot" animation.
     * Only allow loot to be picked up if it is grounded.
     */
    bool isFlying();
};

#endif // LOOT_H
