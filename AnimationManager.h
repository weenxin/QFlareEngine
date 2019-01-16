#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include "CommonIncludes.h"

class AnimationSet;

class AnimationManager
{

private:
    std::vector<AnimationSet*> sets;
    std::vector<std::string> names;
    std::vector<int> counts;


public:
    AnimationManager();
    ~AnimationManager();

    /**
     * @param name: the filename of what to load starting below the animations folder.
     */
    AnimationSet *getAnimationSet(const std::string &name);

    void decreaseCount(const std::string &name);
    void increaseCount(const std::string &name);
    void cleanUp();


};

#endif // ANIMATIONMANAGER_H
