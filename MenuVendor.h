#ifndef MENUVENDOR_H
#define MENUVENDOR_H

#include "CommonIncludes.h"
#include "MenuItemStorage.h"
#include "WidgetLabel.h"
#include"Menu.h"

class ItemStorage;
class NPC;
class StatBlock;
class WidgetButton;
class WidgetTabControl;
class WidgetTooltip;

class MenuVendor : public Menu {
private:
    WidgetButton *closeButton;
    WidgetTabControl *tabControl;
    WidgetLabel label_vendor;

    unsigned VENDOR_SLOTS;

    // label and widget positions
    int slots_cols;
    int slots_rows;
    int activetab;

    WidgetTooltip* tip;

public:
    explicit MenuVendor();
    ~MenuVendor();
    void align();

    NPC *npc;
    std::map<std::string, ItemStorage> buyback_stock;
    MenuItemStorage stock[2]; // items the vendor currently has in stock

    void logic();
    void setTab(int tab);
    int getTab() {
        return activetab;
    }
    void render();
    ItemStack click(const Point& position);
    void itemReturn(ItemStack stack);
    void add(ItemStack stack);
    void renderTooltips(const Point& position);
    void saveInventory();
    void sort(int type);
    void setNPC(NPC* _npc);
    void removeFromPrevSlot(int quantity);
    void lockTabControl();
    void unlockTabControl();

    Rect slots_area;

    TabList tablist_buy;
    TabList tablist_sell;

    TabList* getCurrentTabList();
    void defocusTabLists();
};

#endif // MENUVENDOR_H
