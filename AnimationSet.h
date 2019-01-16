#ifndef ANIMATIONSET_H
#define ANIMATIONSET_H
#include"CommonIncludes.h"

class Animation;

class AnimationSet
{
public:
    AnimationSet();

    const std::string name; //i.e. animations/goblin_runner.txt, matches the animations filename.
        std::string imagefile;
        Animation *defaultAnimation; // has always a non-null animation, in case of successfull load it contains the first animation in the animation file.
        bool loaded;
        AnimationSet *parent;

        void load();
        unsigned getAnimationFrames(const std::string &_name);


public:

    std::vector<Animation*> animations;

    Image *sprite;

    explicit AnimationSet(const std::string &animationname);
    AnimationSet(const AnimationSet &a); // copy constructor not implemented.
    ~AnimationSet();

    /**
     * callee is responsible to free the returned animation.
     * Returns the animation specified by \a name. If that animation is not found
     * a default animation is returned.
     */
    Animation *getAnimation(const std::string &name);

    const std::string &getName() {
        return name;
    }

    void setParent(AnimationSet *other) {
        parent = other;
    }

};

#endif // ANIMATIONSET_H
