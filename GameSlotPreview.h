#ifndef GAMESLOTPREVIEW_H
#define GAMESLOTPREVIEW_H


#include "CommonIncludes.h"
#include "Utils.h"

class Animation;
class AnimationSet;
class StatBlock;


class GameSlotPreview
{
private:
    void loadLayerDefinitions();

    StatBlock *stats;
    Point pos;

    std::vector<AnimationSet*> animsets; // hold the animations for all equipped items in the right order of drawing.
    std::vector<Animation*> anims; // hold the animations for all equipped items in the right order of drawing.

public:
    GameSlotPreview();
    ~GameSlotPreview();

    void setAnimation(std::string name);
    void setStatBlock(StatBlock *_stats);
    void setPos(Point _pos);
    void loadGraphics(std::vector<std::string> _img_gfx);
    void logic();
    void addRenders(std::vector<Renderable> &r);
    void render();

    Animation *activeAnimation;
    AnimationSet *animationSet;

    std::vector<std::string> layer_reference_order;
    std::vector<std::vector<unsigned> > layer_def;

};

#endif // GAMESLOTPREVIEW_H
