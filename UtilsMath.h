#ifndef UTILSMATH_H
#define UTILSMATH_H



#include <cstdlib>
#include <algorithm> // for std::min()/std::max()
#include "math.h"

#ifndef M_PI
#define M_PI 3.1415926535898f
#endif

namespace Math {
    /**
     * Returns sign of value.
     */
    inline int signum(const int value) {
        return (0 < value) - (value < 0);
    }

    /**
     * Returns random number between minVal and maxVal.
     */
    inline int randBetween(int minVal, int maxVal) {
        if (minVal == maxVal) return minVal;
        int d = maxVal - minVal;
        return minVal + (rand() % (d + signum(d)));
    }

    /**
     * Returns true with random percent chance.
     */
    inline bool percentChance(int percent) {
        return rand() % 100 < percent;
    }
}

#endif // UTILSMATH_H
