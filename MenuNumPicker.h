#ifndef MENUNUMPICKER_H
#define MENUNUMPICKER_H


#include "CommonIncludes.h"
#include "Menu.h"
#include "WidgetLabel.h"

class WidgetButton;
class WidgetInput;

class MenuNumPicker : public Menu {

protected:
    void loadGraphics();
    void updateInput();

    WidgetButton *button_ok;
    WidgetButton *button_up;
    WidgetButton *button_down;
    WidgetButton *button_close;
    WidgetInput *input_box;
    WidgetLabel label;

    int value;
    int value_min;
    int value_max;

    int spin_ticks;
    int spin_increment;
    int spin_delay;

public:
    MenuNumPicker();
    ~MenuNumPicker();
    void align();

    void logic();
    virtual void render();

    void setValueBounds(int low, int high);
    void setValue(int val);
    void increaseValue(int val);
    void decreaseValue(int val);
    int getValue();

    bool confirm_clicked;
    bool cancel_clicked;
};

#endif // MENUNUMPICKER_H
