#ifndef MENUDEVCONSOLE_H
#define MENUDEVCONSOLE_H


#include "CommonIncludes.h"
#include "Menu.h"
#include "Utils.h"
#include "WidgetLabel.h"

class WidgetButton;
class WidgetInput;
class WidgetLog;


class MenuDevConsole : public Menu {
protected:
    void loadGraphics();
    void execute();
    void getPlayerInfo();
    void getTileInfo();
    void getEnemyInfo();
    void reset();

    WidgetButton *button_close;
    WidgetButton *button_confirm;
    WidgetInput *input_box;
    WidgetLog *log_history;

    WidgetLabel label;

    Rect history_area;

    bool first_open;

    size_t input_scrollback_pos;
    std::vector<std::string> input_scrollback;

public:
    MenuDevConsole();
    ~MenuDevConsole();
    void align();
    void closeWindow();

    void logic();
    virtual void render();

    bool inputFocus();

    FPoint target;
    Timer distance_timer;
};


#endif // MENUDEVCONSOLE_H
