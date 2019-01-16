#ifndef GAMESTATECONFIG_H
#define GAMESTATECONFIG_H

#include "CommonIncludes.h"
#include "GameState.h"

class MenuConfig;

class GameStateConfig
{
private:
    MenuConfig* menu_config;

public:
    explicit GameStateConfig();
    ~GameStateConfig();

    void logic();
    void logicAccept();
    void logicCancel();
    void refreshFont();

    void render();
};

#endif // GAMESTATECONFIG_H
