#ifndef MENU_H
#define MENU_H


#include "CommonIncludes.h"
#include "Utils.h"
#include "Widget.h"

class Menu {
public:
    Menu();
    virtual ~Menu();

    void setBackground(const std::string& background_image);
    void setBackgroundDest(Rect &dest);
    void setBackgroundClip(Rect &clip);
    virtual void align();
    virtual void render();
    virtual void setWindowPos(int x, int y);

    bool visible;
    Rect window_area;
    int alignment;

    virtual bool parseMenuKey(const std::string &key, const std::string &val);

    SoundID sfx_open;
    SoundID sfx_close;

    TabList tablist;
    virtual TabList* getCurrentTabList();
    virtual void defocusTabLists();

private:
    Sprite *background;
    Point window_area_base;
};

#endif // MENU_H
