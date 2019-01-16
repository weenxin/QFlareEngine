#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "CommonIncludes.h"
#include "WidgetTooltip.h"
class GameState
{
public:
    GameState();
    GameState(const GameState& other);
    GameState& operator=(const GameState& other);
    virtual ~GameState();

    virtual void logic();
    virtual void render();
    virtual void refreshWidgets();

    GameState* getRequestedGameState();
    void setRequestedGameState(GameState *new_state);
    bool isExitRequested() {
        return exitRequested;
    }
    void setLoadingFrame();
    virtual bool isPaused();
    void showLoading();

    bool hasMusic;
    bool has_background;
    bool reload_music;
    bool reload_backgrounds;
    bool force_refresh_background;
    bool save_settings_on_exit;

    int load_counter;

protected:
    GameState* requestedGameState;
    bool exitRequested;
    WidgetTooltip *loading_tip;
    TooltipData loading_tip_buf;
};

#endif // GAMESTATE_H
