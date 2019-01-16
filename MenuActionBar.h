#ifndef MENUACTIONBAR_H
#define MENUACTIONBAR_H

#include "CommonIncludes.h"
#include "Menu.h"
#include "Utils.h"

class ActionData;
class Power;
class StatBlock;
class WidgetLabel;
class WidgetSlot;

class MenuActionBar : public Menu {

private:
    static const bool IS_EQUIPPED = true;

    FPoint setTarget(bool have_aim, const Power& pow);
    void addSlot(unsigned index, int x, int y, bool is_locked);
    void setItemCount(unsigned index, int count, bool is_equipped);

    Sprite *sprite_emptyslot;
    Sprite *sprite_disabled;
    Sprite *sprite_attention;

    Rect src;

    std::vector<std::string> labels;
    std::vector<std::string> menu_labels;

    Point last_mouse;

    std::vector<int> slot_fail_cooldown;

    SoundID sfx_unable_to_cast;


public:
    enum {
        MENU_CHARACTER = 0,
        MENU_INVENTORY = 1,
        MENU_POWERS = 2,
        MENU_LOG = 3,
    };
    static const unsigned MENU_COUNT = 4;

    static const int SLOT_MAIN1 = 10;
    static const int SLOT_MAIN2 = 11;
    static const int SLOT_MAX = 12; // maximum number of slots in MenuActionBar

    static const int USE_EMPTY_SLOT = 0;

    static const bool REORDER = true;

    MenuActionBar();
    ~MenuActionBar();
    void align();
    void loadGraphics();
    void logic();
    void render();
    void checkAction(std::vector<ActionData> &action_queue);
    int checkDrag(const Point& mouse);
    void checkMenu(bool &menu_c, bool &menu_i, bool &menu_p, bool &menu_l);
    void drop(const Point& mouse, int power_index, bool rearranging);
    void actionReturn(int power_index);
    void remove(const Point& mouse);
    void set(std::vector<int> power_id);
    void clear();
    void resetSlots();
    Point getSlotPos(int slot);
    int getSlotPower(int slot);

    void renderTooltips(const Point& position);
    bool isWithinSlots(const Point& mouse);
    bool isWithinMenus(const Point& mouse);
    void addPower(const int id, const int target_id);

    unsigned slots_count;
    std::vector<int> hotkeys; // refer to power_index in PowerManager
    std::vector<int> hotkeys_temp; // temp for shapeshifting
    std::vector<int> hotkeys_mod; // hotkeys can be changed by items
    std::vector<bool> locked; // if slot is locked, you cannot drop it
    std::vector<bool> prevent_changing;
    std::vector<WidgetSlot *> theSlots; // hotkey slots
    WidgetSlot *menus[MENU_COUNT]; // menu buttons
    std::string menu_titles[MENU_COUNT];
    std::vector<int> slot_item_count; // -1 means this power isn't item based.  0 means out of items.  1+ means sufficient items.
    std::vector<bool> slot_enabled;
    bool requires_attention[MENU_COUNT];
    std::vector<bool> slot_activated;
    std::vector<int> slot_cooldown_size;

    int drag_prev_slot;
    bool updated;
    int twostep_slot;


};

#endif // MENUACTIONBAR_H
