#ifndef LOOTMANAGER_H
#define LOOTMANAGER_H

#include "CommonIncludes.h"
#include "FileParser.h"
#include "ItemManager.h"
#include "Loot.h"
#include "Utils.h"
#include"EventManager.h"

class Animation;

class EnemyManager;
class WidgetTooltip;

class LootManager {
private:

    WidgetTooltip *tip;

    // functions
    void loadGraphics();
    void checkEnemiesForLoot();
    void checkMapForLoot();
    void loadLootTables();
    void getLootTable(const std::string &filename, std::vector<EventComponent> *ec_list);
    void checkLootComponent(EventComponent* ec, FPoint *pos, std::vector<ItemStack> *itemstack_vec);

    SoundID sfx_loot;

    // loot refers to ItemManager indices
    std::vector<Loot> loot;

    // enemies which should drop loot, but didnt yet.
    std::vector<class Enemy*> enemiesDroppingLoot;

    // loot tables defined in files under "loot/"
    std::map<std::string, std::vector<EventComponent> > loot_tables;

    // to prevent dropping multiple loot stacks on the same tile,
    // we block tiles that have loot dropped on them
    std::vector<Point> tiles_to_unblock;

    std::vector< std::vector<Animation*> > animations;

public:
    static const bool DROPPED_BY_HERO = true;

    LootManager();
    LootManager(const LootManager &copy); // not implemented
    ~LootManager();

    void handleNewMap();
    void logic();
    void renderTooltips(const FPoint& cam);

    // called by enemy, who definitly wants to drop loot.
    void addEnemyLoot(Enemy *e);
    void addLoot(ItemStack stack, const FPoint& pos, bool dropped_by_hero);
    void checkLoot(std::vector<EventComponent> &loot_table, FPoint *pos, std::vector<ItemStack> *itemstack_vec);
    ItemStack checkPickup(const Point& mouse, const FPoint& cam, const FPoint& hero_pos);
    ItemStack checkAutoPickup(const FPoint& hero_pos);
    ItemStack checkNearestPickup(const FPoint& hero_pos);

    void addRenders(std::vector<Renderable> &ren, std::vector<Renderable> &ren_dead);

    void parseLoot(std::string &val, EventComponent *e, std::vector<EventComponent> *ec_list);
};

#endif // LOOTMANAGER_H
