#ifndef WIDGETLOG_H
#define WIDGETLOG_H

#include "CommonIncludes.h"
#include"Utils.h"

class Widget;
class WidgetScrollBox;


class WidgetLog
{
private:
    void refresh();
    void setFont(int style);

    WidgetScrollBox *scroll_box;
    int line_height;
    int paragraph_spacing;
    int padding;
    unsigned max_messages;

    std::vector<std::string> messages;
    std::vector<Color> colors;
    std::vector<int> styles;
    std::vector<bool> separators;

    bool updated;

    Color next_color;
    int next_style;

public:
    enum {
        FONT_REGULAR = 0,
        FONT_BOLD = 1
    };

    enum {
        MSG_NORMAL = 0,
        MSG_UNIQUE = 1
    };

    static const unsigned MAX_MESSAGES = 50;

    WidgetLog (int width, int height);
    ~WidgetLog ();
    void setBasePos(int x, int y, int a);
    void setPos(int offset_x, int offset_y);

    void logic();
    void render();

    Widget* getWidget() {
        return reinterpret_cast<Widget*>(scroll_box);    // for adding to tablist
    }

    void add(const std::string &s, int type);
    void setNextColor(const Color& color);
    void setNextStyle(int style);
    void remove(unsigned msg_index);
    void clear();
    void setMaxMessages(unsigned count);
    void addSeparator();
    bool isEmpty();
};

#endif // WIDGETLOG_H
