#ifndef NPCMANAGER_H
#define NPCMANAGER_H


#include "CommonIncludes.h"
#include "TooltipData.h"

class StatBlock;
class NPC;
class WidgetTooltip;

class NPCManager {
private:
    WidgetTooltip *tip;
    TooltipData tip_buf;

public:
    explicit NPCManager();
    NPCManager(const NPCManager &copy); // not implemented
    ~NPCManager();

    std::vector<NPC*> npcs;
    void handleNewMap();
    void logic();
    void addRenders(std::vector<Renderable> &r);
    int getID(const std::string& npcName);
};

#endif // NPCMANAGER_H
