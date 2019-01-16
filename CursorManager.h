#ifndef CURSORMANAGER_H
#define CURSORMANAGER_H

#include "CommonIncludes.h"
#include "Utils.h"

class CursorManager
{
public:
    CursorManager ();
    ~CursorManager ();
    void logic();
    void render();
    void setCursor(int type);

    bool show_cursor;

    enum {
        CURSOR_NORMAL,
        CURSOR_INTERACT,
        CURSOR_TALK,
        CURSOR_ATTACK
    };

private:
    Sprite *cursor_normal;
    Sprite *cursor_interact;
    Sprite *cursor_talk;
    Sprite *cursor_attack;

    Point offset_normal;
    Point offset_interact;
    Point offset_talk;
    Point offset_attack;

    Sprite *cursor_current;
    Point* offset_current;
};

#endif // CURSORMANAGER_H
