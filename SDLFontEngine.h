#ifndef SDLFONTENGINE_H
#define SDLFONTENGINE_H

#include "FontEngine.h"
#include "SDL2/SDL_ttf.h"

class SDLFontStyle : public FontStyle {
public:
    SDLFontStyle();
    ~SDLFontStyle() {}

    TTF_Font *ttfont;
};


/**
 *
 * class SDLFontEngine
 * Handles rendering a bitmap font using SDL TTF_Font.
 *
 */

class SDLFontEngine : public FontEngine {
private:
    std::vector<SDLFontStyle> font_styles;
    SDLFontStyle *active_font;

protected:
    void renderInternal(const std::string& text, int x, int y, int justify, Image *target, const Color& color);

public:
    SDLFontEngine();
    ~SDLFontEngine();

    int getLineHeight();
    int getFontHeight();

    void setFont(const std::string& _font);

    int calc_width(const std::string& text);
    std::string trimTextToWidth(const std::string& text, const int width, const bool use_ellipsis, size_t left_pos);
};

#endif // SDLFONTENGINE_H
