#ifndef GAMESWITCHER_H
#define GAMESWITCHER_H

#include "CommonIncludes.h"
#include "Utils.h"

class GameState;
class WidgetLabel;

/**
 * class GameSwitcher
 *
 * State machine handler between main game modes that take up the entire view/control
 *
 * Examples:
 * - the main gameplay (GameStatePlay)
 * - title screen (GameStateTitle)
 * - new game screen (GameStateNew)
 * - load game screen (GameStateLoad)
 * - cutscenes (GameStateCutscene)
 */

class GameSwitcher {
private:
    void loadBackgroundList();
    void refreshBackground();
    void freeBackground();

    GameState *currentState;

    WidgetLabel *label_fps;
    Rect fps_position;
    Color fps_color;
    int fps_corner;

    Sprite *background;
    Image *background_image;
    std::string background_filename;
    std::vector<std::string> background_list;

    Timer fps_update;
    float last_fps;

public:
    GameSwitcher();
    GameSwitcher(const GameSwitcher &copy); // not implemented.
    ~GameSwitcher();

    void loadMusic();
    void loadBackgroundImage();
    void loadFPS();
    bool isLoadingFrame();
    bool isPaused();
    void logic();
    void render();
    void showFPS(float fps);
    void saveUserSettings();
    bool done;
};

#endif // GAMESWITCHER_H
