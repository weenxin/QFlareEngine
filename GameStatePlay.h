#ifndef GAMESTATEPLAY_H
#define GAMESTATEPLAY_H

#include "CommonIncludes.h"
#include "GameState.h"
#include "Utils.h"

class Avatar;
class Enemy;
class MenuManager;
class NPCManager;
class QuestLog;
class WidgetLabel;

class ActionData;

class Title {
public:
    std::string title;
    int level;
    int power;
    std::vector<StatusID> requires_status;
    std::vector<StatusID> requires_not_status;
    std::string primary_stat_1;
    std::string primary_stat_2;

    Title()
        : title("")
        , level(0)
        , power(0)
        , requires_status()
        , requires_not_status()
        , primary_stat_1("")
        , primary_stat_2("") {
    }
};

class GameStatePlay
{
private:
    Enemy *enemy;

    NPCManager *npcs;
    QuestLog *quests;

    bool restrictPowerUse();
    void checkEnemyFocus();
    void checkLoot();
    void checkLootDrop();
    void checkTeleport();
    void checkCancel();
    void checkLog();
    void checkBook();
    void checkEquipmentChange();
    void checkTitle();
    void checkUsedItems();
    void checkNotifications();
    void checkNPCInteraction();
    void checkStash();
    void checkCutscene();
    void checkSaveEvent();
    void updateActionBar(unsigned index);
    void loadTitles();
    void resetNPC();
    bool checkPrimaryStat(const std::string& first, const std::string& second);

    int npc_id;

    std::vector<Title> titles;

    std::vector<ActionData> action_queue;

    Timer second_timer;

    bool is_first_map_load;

    static const unsigned UPDATE_ACTIONBAR_ALL = 0;

public:
    GameStatePlay();
    ~GameStatePlay();
    void refreshWidgets();

    bool isPaused();
    void logic();
    void render();
    void resetGame();
};

#endif // GAMESTATEPLAY_H
