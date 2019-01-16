#ifndef MENUTALKER_H
#define MENUTALKER_H

#include "CommonIncludes.h"
#include "Utils.h"
#include "Widget.h"
#include"Menu.h"

class CampaignManager;
class NPC;
class StatBlock;
class WidgetButton;
class WidgetLabel;
class WidgetScrollBox;

class MenuTalker : public Menu {
private:
    class Action {
    public:
        static const int NO_NODE = -1;
        static const bool IS_VENDOR = true;

        Action();
        ~Action();

        WidgetButton* btn;
        int node_id;
        bool is_vendor;
    };

    void createActionButtons(int node_id);
    void clearActionButtons();
    void createActionBuffer();
    void executeAction(size_t index);
    void nextDialog();
    void setupTabList();
    void addAction(const std::string& label, int node_id, bool is_vendor);

    Sprite *portrait;
    std::string hero_name;
    std::string hero_class;

    int dialog_node;
    unsigned int event_cursor;
    bool first_interaction;

    Rect dialog_pos;
    Rect text_pos;
    Point text_offset;
    Rect portrait_he;
    Rect portrait_you;

    std::string font_who;
    std::string font_dialog;

    WidgetLabel *label_name;
    WidgetScrollBox *textbox;

    std::vector<Action> actions;

    Color topic_color_normal;
    Color topic_color_hover;
    Color topic_color_pressed;

    Color trade_color_normal;
    Color trade_color_hover;
    Color trade_color_pressed;

public:
    explicit MenuTalker();
    ~MenuTalker();
    void align();

    NPC *npc;

    void chooseDialogNode(int requested_node);
    void logic();
    void render();
    void setHero(StatBlock &stats);
    void createBuffer();
    void setNPC(NPC* _npc);

    WidgetButton *advanceButton;
    WidgetButton *closeButton;

    bool npc_from_map;
};

#endif // MENUTALKER_H
