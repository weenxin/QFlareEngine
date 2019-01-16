#ifndef GAMESTATELOAD_H
#define GAMESTATELOAD_H

#include "CommonIncludes.h"
#include "GameSlotPreview.h"
#include "GameState.h"
#include "StatBlock.h"
#include "Utils.h"
#include "WidgetLabel.h"



class ItemManager;
class MenuConfirm;
class WidgetButton;
class WidgetLabel;
class WidgetScrollBar;

class GameSlot {
public:
    unsigned id;

    StatBlock stats;
    std::string current_map;
    unsigned long time_played;

    std::vector<int> equipped;
    GameSlotPreview preview;
    Timer preview_turn_timer;

    WidgetLabel label_name;
    WidgetLabel label_level;
    WidgetLabel label_class;
    WidgetLabel label_map;
    WidgetLabel label_slot_number;

    GameSlot();
    ~GameSlot();
};

/**
 * GameStateLoad
 *
 * Display the current save-game slots
 * Allow the player to continue a previous game
 * Allow the player to start a new game
 * Allow the player to abandon a previous game
 */

class GameStateLoad : public GameState {
private:

    void loadGraphics();
    void loadPortrait(int slot);
    std::string getMapName(const std::string& map_filename);
    void updateButtons();
    void refreshWidgets();
    void logicLoading();
    void readGameSlots();
    void loadPreview(GameSlot *slot);

    void scrollUp();
    void scrollDown();
    void scrollToSelected();
    void refreshScrollBar();
    void setSelectedSlot(int slot);

    void refreshSavePaths();

    TabList tablist;

    WidgetButton *button_exit;
    WidgetButton *button_new;
    WidgetButton *button_load;
    WidgetButton *button_delete;
    WidgetLabel *label_loading;
    WidgetScrollBar *scrollbar;

    MenuConfirm *confirm;

    Sprite *background;
    Sprite *selection;
    Sprite *portrait_border;
    Sprite *portrait;
    std::vector<Rect> slot_pos;

    std::vector<GameSlot *> game_slots;

    bool loading_requested;
    bool loading;
    bool loaded;
    bool delete_items;

    LabelInfo name_pos;
    LabelInfo level_pos;
    LabelInfo class_pos;
    LabelInfo map_pos;
    LabelInfo slot_number_pos;
    Point sprites_pos;

    Rect portrait_dest;

    Rect gameslot_pos;

    int selected_slot;
    int visible_slots;
    int scroll_offset;
    bool has_scroll_bar;
    int game_slot_max;
    int text_trim_boundary;

public:
    GameStateLoad();
    ~GameStateLoad();

    void logic();
    void render();
};

#endif // GAMESTATELOAD_H
