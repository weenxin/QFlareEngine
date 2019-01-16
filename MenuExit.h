#ifndef MENUEXIT_H
#define MENUEXIT_H


#include "CommonIncludes.h"
#include "Menu.h"

class MenuConfig;

class MenuExit : public Menu {
protected:
    MenuConfig* menu_config;
    bool exitClicked;

public:
    MenuExit();
    ~MenuExit();
    void align();
    void logic();
    virtual void render();

    bool isExitRequested() {
        return exitClicked;
    }

    void disableSave();
    void handleCancel();

    bool reload_music;
};

#endif // MENUEXIT_H
