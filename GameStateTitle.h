#ifndef GAMESTATETITLE_H
#define GAMESTATETITLE_H
#include "GameState.h"
#include "Widget.h"

class WidgetButton;
class WidgetLabel;

class GameStateTitle : public GameState {
private:
    void refreshWidgets();

    Sprite *logo;
    WidgetButton *button_play;
    WidgetButton *button_exit;
    WidgetButton *button_cfg;
    WidgetButton *button_credits;
    WidgetLabel *label_version;

    TabList tablist;

    Point pos_logo;
    int align_logo;

public:
    GameStateTitle();
    ~GameStateTitle();
    void logic();
    void render();

    // switch
    bool exit_game;
    bool load_game;

};
#endif // GAMESTATETITLE_H
