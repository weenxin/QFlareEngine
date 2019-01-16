#ifndef MENUITEMSTORAGE_H
#define MENUITEMSTORAGE_H

#include "CommonIncludes.h"
#include "ItemManager.h"
#include "ItemStorage.h"

class StatBlock;
class TooltipData;
class WidgetSlot;


class MenuItemStorage : public ItemStorage {
protected:
    void loadGraphics();
    Rect grid_area;
    Point grid_pos;
    int nb_cols;

public:
    MenuItemStorage();
    void initGrid(int _slot_number, const Rect& _area, int nb_cols);
    void initFromList(int _slot_number, const std::vector<Rect>& _area, const std::vector<std::string>& _slot_type);
    ~MenuItemStorage();

    // rendering
    void render();
    int slotOver(const Point& position);
    TooltipData checkTooltip(const Point& position, StatBlock *stats, int context);
    ItemStack click(const Point& position);
    void itemReturn(ItemStack stack);
    void highlightMatching(const std::string& type);
    void highlightClear();
    void setPos(int x, int y);
    std::vector<std::string> slot_type;

    int drag_prev_slot;
    std::vector<WidgetSlot*> theSlots;
    WidgetSlot *current_slot;

    bool * highlight;
    Sprite *highlight_image;
    Sprite *overlay_disabled;
};

#endif // MENUITEMSTORAGE_H
