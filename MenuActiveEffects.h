#ifndef MENUACTIVEEFFECTS_H
#define MENUACTIVEEFFECTS_H


#include "CommonIncludes.h"
#include "Menu.h"
#include "Utils.h"

class StatBlock;
class TooltipData;
class WidgetLabel;

class EffectIcon {
public:
    int icon;
    int type;
    int current;
    int max;
    int stacks;
    Rect pos;
    Rect overlay;
    std::string name;
    WidgetLabel* stacksLabel;

    EffectIcon()
        : icon(-1)
        , type(0)
        , current(0)
        , max(0)
        , stacks(0)
        , stacksLabel(NULL)
    {}
};

class MenuActiveEffects : public Menu {

private:
    Sprite *timer;
    bool is_vertical;
    std::vector<EffectIcon> effect_icons;

public:
    explicit MenuActiveEffects();
    ~MenuActiveEffects();
    void loadGraphics();
    void logic();
    void render();
    void renderTooltips(const Point& position);
};

#endif // MENUACTIVEEFFECTS_H
