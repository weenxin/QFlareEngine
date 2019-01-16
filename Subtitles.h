#ifndef SUBTITLES_H
#define SUBTITLES_H

#include "CommonIncludes.h"
#include "Utils.h"
#include "WidgetLabel.h"

class Subtitles {
public:
    Subtitles();
    ~Subtitles();
    void logic(unsigned long id);
    void render();

private:
    void setTextByID(unsigned long id);
    void updateLabelAndBackground();

    std::vector<unsigned long> filename;
    std::vector<std::string> text;

    WidgetLabel label;
    Point label_pos;
    int label_alignment;
    unsigned long current_id;
    std::string current_text;
    bool visible;
    Sprite *background;
    Rect background_rect;
    Color background_color;
    Timer visible_timer;
};
#endif // SUBTITLES_H
