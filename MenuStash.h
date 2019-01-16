#ifndef MENUSTASH_H
#define MENUSTASH_H


#include "CommonIncludes.h"
#include "MenuItemStorage.h"
#include "WidgetLabel.h"
#include"Menu.h"

class NPC;
class StatBlock;
class WidgetButton;

class MenuStash : public Menu {
private:
    WidgetButton *closeButton;
    WidgetLabel label_title;
    WidgetLabel label_currency;

public:
    static const int NO_SLOT = -1;
    static const bool ADD_PLAY_SOUND = true;

    explicit MenuStash();
    ~MenuStash();
    void align();

    void logic();
    void render();
    ItemStack click(const Point& position);
    void itemReturn(ItemStack stack);
    bool add(ItemStack stack, int slot, bool play_sound);
    void renderTooltips(const Point& position);
    bool drop(const Point& position, ItemStack stack);

    void removeFromPrevSlot(int quantity);

    Rect slots_area;
    MenuItemStorage stock;
    bool updated;

    std::queue<ItemStack> drop_stack;
};

#endif // MENUSTASH_H
