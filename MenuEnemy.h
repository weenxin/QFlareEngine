#ifndef MENUENEMY_H
#define MENUENEMY_H


#include "CommonIncludes.h"
#include "Utils.h"
#include "WidgetLabel.h"
#include"Menu.h"

class Enemy;

class MenuEnemy : public Menu {
private:
    Sprite *bar_hp;
    Rect bar_pos;
    LabelInfo text_pos;
    bool custom_text_pos;
    WidgetLabel label_text;
    WidgetLabel label_stats;
public:
    MenuEnemy();
    ~MenuEnemy();
    Enemy *enemy;
    void loadGraphics();
    void handleNewMap();
    void logic();
    void render();
    Timer timeout;
};

#endif // MENUENEMY_H
