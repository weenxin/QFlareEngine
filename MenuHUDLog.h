#ifndef MENUHUDLOG_H
#define MENUHUDLOG_H


#include "CommonIncludes.h"
#include "Utils.h"
#include"Menu.h"

class MenuHUDLog : public Menu {
private:

    int calcDuration(const std::string& s);

    std::vector<std::string> log_msg;
    std::vector<int> msg_age;
    std::vector<Sprite *> msg_buffer;

    int paragraph_spacing;

    Sprite *overlay_bg;
    bool enable_overlay;
    bool click_to_dismiss;
    bool start_at_bottom;
    bool overlay_at_bottom;

public:
    enum {
        MSG_NORMAL = 0,
        MSG_UNIQUE = 1
    };

    MenuHUDLog();
    ~MenuHUDLog();
    void logic();
    void render();
    void add(const std::string& s, int type);
    void remove(int msg_index);
    void clear();
    void renderOverlay();

    bool hide_overlay;
};

#endif // MENUHUDLOG_H
