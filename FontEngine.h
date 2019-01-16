#ifndef FONTENGINE_H
#define FONTENGINE_H
#include "CommonIncludes.h"
#include "Utils.h"

class FontStyle {
public:
    std::string name;
    std::string path;
    int ptsize;
    bool blend;
    int line_height;
    int font_height;

    FontStyle();
    virtual ~FontStyle() {}
};

class FontEngine
{
public:
    enum {
        JUSTIFY_LEFT = 0,
        JUSTIFY_RIGHT = 1,
        JUSTIFY_CENTER = 2
    };


    enum {
        COLOR_WHITE = 0,
        COLOR_BLACK = 1,
        COLOR_MENU_NORMAL = 2,
        COLOR_MENU_BONUS = 3,
        COLOR_MENU_PENALTY = 4,
        COLOR_WIDGET_NORMAL = 5,
        COLOR_WIDGET_DISABLED = 6,
        COLOR_COMBAT_GIVEDMG = 7,
        COLOR_COMBAT_TAKEDMG = 8,
        COLOR_COMBAT_CRIT = 9,
        COLOR_COMBAT_BUFF = 10,
        COLOR_COMBAT_MISS = 11,
        COLOR_REQUIREMENTS_NOT_MET = 12,
        COLOR_ITEM_BONUS = 13,
        COLOR_ITEM_PENALTY = 14,
        COLOR_ITEM_FLAVOR = 15,
        COLOR_HARDCORE_NAME = 16
    };
    static const size_t COLOR_COUNT = 17;

    static const bool USE_ELLIPSIS = true;
    FontEngine();
    virtual ~FontEngine() {}

    Color getColor(size_t _color);

    Point calc_size(const std::string& text_with_newlines, int width);

    void render(const std::string& text, int x, int y, int justify, Image *target, int width, const Color& color);
    void renderShadowed(const std::string& text, int x, int y, int justify, Image *target, int width, const Color& color);

    virtual int getLineHeight() = 0;
    virtual int getFontHeight() = 0;

    virtual void setFont(const std::string& _font) = 0;
    virtual int calc_width(const std::string& text) = 0;
    virtual std::string trimTextToWidth(const std::string& text, const int width, const bool use_ellipsis, size_t left_pos) = 0;

    int cursor_y;

protected:
    size_t stringToFontColor(const std::string& val);
    Rect position(const std::string& text, int x, int y, int justify);
    virtual void renderInternal(const std::string& text, int x, int y, int justify, Image *target, const Color& color) = 0;
    std::string popTokenByWidth(std::string& text, int width);
    std::string getNextToken(const std::string& s, size_t& cursor, char separator);

    std::vector<Color> font_colors;
};

#endif // FONTENGINE_H
