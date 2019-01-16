#ifndef STATS_H
#define STATS_H

#include "CommonIncludes.h"

namespace Stats {
    static const int COUNT = 20;

    enum STAT {
        HP_MAX = 0,
        HP_REGEN = 1,
        MP_MAX = 2,
        MP_REGEN = 3,
        ACCURACY = 4,
        AVOIDANCE = 5,
        ABS_MIN = 6,
        ABS_MAX = 7,
        CRIT = 8,
        XP_GAIN = 9,
        CURRENCY_FIND = 10,
        ITEM_FIND = 11,
        STEALTH = 12,
        POISE = 13,
        REFLECT = 14,
        RETURN_DAMAGE = 15,
        HP_STEAL = 16,
        MP_STEAL = 17,
        // HP_PERCENT & MP_PERCENT aren't displayed in MenuCharacter; new stats should be added above this comment.
        HP_PERCENT = 18,
        MP_PERCENT = 19
    };

    extern std::string KEY[COUNT];
    extern std::string NAME[COUNT];
    extern std::string DESC[COUNT];
    extern bool PERCENT[COUNT];
    void init();
}

#endif // STATS_H
