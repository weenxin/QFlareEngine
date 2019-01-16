#ifndef MENUTOUCHCONTROLS_H
#define MENUTOUCHCONTROLS_H

#include "CommonIncludes.h"
#include "Menu.h"
#include "Utils.h"
#include"Menu.h"

class MenuTouchControls : public Menu {
private:
    void alignInput(Point& center, const Point& center_base, const int radius, const int _align);
    void renderInput(const Point& center, const int radius, const Color& color);

    int move_radius;
    Point move_center;
    Point move_center_base;
    int move_align;
    int move_deadzone;

    int main1_radius;
    Point main1_center;
    Point main1_center_base;
    int main1_align;

    int main2_radius;
    Point main2_center;
    Point main2_center_base;
    int main2_align;

    int radius_padding;
public:
    MenuTouchControls();
    ~MenuTouchControls();

    void logic();
    void align();
    void render();

    bool checkAllowMain1();
};

#endif // MENUTOUCHCONTROLS_H
