#ifndef WIDGETTOOLTIP_H
#define WIDGETTOOLTIP_H

#include "CommonIncludes.h"
#include "TooltipData.h"
#include "Utils.h"


class WidgetTooltip
{
public:
    WidgetTooltip();
    ~WidgetTooltip();
    Point calcPosition(uint8_t style, const Point& pos, const Point& size);
    void prerender(TooltipData&tip, const Point& pos, uint8_t style);
    void render(TooltipData &tip, const Point& pos, uint8_t style);
    bool createBuffer(TooltipData &tip);

    Rect bounds;

private:
    Image *background;
    TooltipData data_buf;
    Sprite* sprite_buf;
};

#endif // WIDGETTOOLTIP_H
