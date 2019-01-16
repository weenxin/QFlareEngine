#ifndef MENULOG_H
#define MENULOG_H

#include "CommonIncludes.h"
#include "Utils.h"
#include "WidgetLabel.h"
#include "WidgetLog.h"
#include"Menu.h"

class WidgetButton;
class WidgetTabControl;


class MenuLog : public Menu {
public:
    enum {
        TYPE_QUESTS = 0,
        TYPE_MESSAGES = 1
    };
    static const int TYPE_COUNT = 2;

    MenuLog();
    ~MenuLog();
    void align();

    void logic();
    void render();
    void add(const std::string& s, int log_type, int msg_type);
    void setNextColor(const Color& color, int log_type);
    void setNextStyle(int style, int log_type);
    void remove(int msg_index, int log_type);
    void clear(int log_type);
    void clearAll();
    void addSeparator(int log_type);
    void setNextTabList(TabList *tl);

    std::vector<TabList> tablist_log;

    TabList* getCurrentTabList();
    void defocusTabLists();

private:
    WidgetLabel label_log;
    WidgetButton *closeButton;
    WidgetTabControl *tabControl;

    void loadGraphics();

    WidgetLog *log[TYPE_COUNT];
    std::string tab_labels[TYPE_COUNT];
    Rect tab_rect[TYPE_COUNT];

    Rect tab_area;
    Color tab_bg;
};


#endif // MENULOG_H
