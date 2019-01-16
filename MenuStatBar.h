#ifndef MENUSTATBAR_H
#define MENUSTATBAR_H


#include "CommonIncludes.h"
#include "Utils.h"
#include "WidgetLabel.h"
#include"Menu.h"

class WidgetLabel;

class MenuStatBar : public Menu {
private:
    enum {
        HORIZONTAL = 0,
        VERTICAL = 1
    };

    Sprite *bar;
    WidgetLabel *label;
    unsigned long stat_min;
    unsigned long stat_cur;
    unsigned long stat_max;
    Rect bar_pos;
    LabelInfo text_pos;
    bool orientation;
    bool custom_text_pos;
    std::string custom_string;
    std::string bar_gfx;
    std::string bar_gfx_background;

public:
    explicit MenuStatBar(const std::string& type);
    ~MenuStatBar();
    void loadGraphics();
    void update(unsigned long _stat_min, unsigned long _stat_cur, unsigned long _stat_max);
    void setCustomString(const std::string& _custom_string);
    void render();
};

#endif // MENUSTATBAR_H
