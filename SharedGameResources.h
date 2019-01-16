#ifndef SHAREDGAMERESOURCES_H
#define SHAREDGAMERESOURCES_H

class Avatar;
class CampaignManager;
class EnemyGroupManager;
class EnemyManager;
class HazardManager;
class ItemManager;
class LootManager;
class MapRenderer;
class MenuActionBar;
class MenuManager;
class MenuPowers;
class PowerManager;

/* These objects are created in the GameStatePlay constructor and deleted in the GameStatePlay destructor
*  so can be accessed safely anywhere in between. The objects must not be changed by any other class.
*/
extern Avatar *pc;
extern CampaignManager *camp;
extern EnemyGroupManager *enemyg;
extern EnemyManager *enemym;
extern HazardManager *hazards;
extern ItemManager *items;
extern LootManager *loot;
extern MapRenderer *mapr;
extern MenuActionBar *menu_act;
extern MenuManager *menu;
extern MenuPowers *menu_powers;
extern PowerManager *powers;


#endif // SHAREDGAMERESOURCES_H
