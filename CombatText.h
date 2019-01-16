#ifndef COMBATTEXT_H
#define COMBATTEXT_H

#include "CommonIncludes.h"
#include "Utils.h"

class WidgetLabel;

class Combat_Text_Item {
public:
    Combat_Text_Item();
    ~Combat_Text_Item();

    WidgetLabel *label;
    int lifespan;
    FPoint pos;
    float floating_offset;
    std::string text;
    int displaytype;
};


class CombatText
{
public:
    CombatText();
    ~CombatText();

    void logic(const FPoint& _cam);
    void render();
    void addString(const std::string& message, const FPoint& location, int displaytype);
    void addInt(int num, const FPoint& location, int displaytype);
    void clear();

    enum {
        MSG_GIVEDMG = 0,
        MSG_TAKEDMG = 1,
        MSG_CRIT = 2,
        MSG_MISS = 3,
        MSG_BUFF = 4
    };
private:
    FPoint cam;
    std::vector<Combat_Text_Item> combat_text;

    Color msg_color[5];
    int duration;
    float speed;
    int offset;
};

#endif // COMBATTEXT_H
