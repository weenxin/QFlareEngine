#ifndef TOOLTIPMANAGER_H
#define TOOLTIPMANAGER_H


#include "TooltipData.h"
#include "Utils.h"

class WidgetTooltip;

class TooltipManager {
private:
    WidgetTooltip *tip;
    TooltipData tip_data;
    Point pos;
    uint8_t style;

public:
    enum {
        CONTEXT_NONE = 0,
        CONTEXT_MENU = 1,
        CONTEXT_MAP = 2
    };

    TooltipManager();
    ~TooltipManager();
    TooltipManager(const TooltipManager& copy); // copy constructor not implemented

    void clear();
    bool isEmpty();
    void push(const TooltipData& _tip_data, const Point& _pos, uint8_t _style);
    void render();

    uint8_t context;
};
#endif // TOOLTIPMANAGER_H
