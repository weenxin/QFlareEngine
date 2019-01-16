#ifndef WIDGETLABEL_H
#define WIDGETLABEL_H


#include "CommonIncludes.h"
#include "Utils.h"
#include "Widget.h"

class LabelInfo {
public:
    enum {
        VALIGN_CENTER = 0,
        VALIGN_TOP = 1,
        VALIGN_BOTTOM = 2
    };

    int x,y;
    int justify,valign;
    bool hidden;
    std::string font_style;

    LabelInfo();
};


class WidgetLabel
{
private:
    enum {
        UPDATE_NONE = 0,
        UPDATE_POS = 1,
        UPDATE_RECACHE = 2
    };

    void recacheTextSprite();
    void applyOffsets();
    void setUpdateFlag(int _update_flag);
    void update();

    int justify;
    int valign;
    int max_width;
    int update_flag;
    bool hidden;
    bool window_resize_flag;
    Sprite *label;

    std::string text;
    std::string font_style;
    Color color;

    Rect bounds;
public:
    static const std::string DEFAULT_FONT;

    WidgetLabel();
    ~WidgetLabel();
    void render();
    void setMaxWidth(int width);
    void setHidden(bool _hidden);
    void setPos(int offset_x, int offset_y);
    void setJustify(int _justify);
    void setVAlign(int _valign);
    void setText(const std::string& _text);
    void setColor(const Color& _color);
    void setFont(const std::string& _font);
    void setFromLabelInfo(const LabelInfo& label_info);

    std::string getText();
    Rect* getBounds();
    bool isHidden();
};

#endif // WIDGETLABEL_H
