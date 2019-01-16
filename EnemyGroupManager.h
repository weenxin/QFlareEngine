#ifndef ENEMYGROUPMANAGER_H
#define ENEMYGROUPMANAGER_H

#include "CommonIncludes.h"

class Enemy_Level {
public:
    std::string type;
    int level;
    std::string rarity;

    Enemy_Level() : level(0), rarity("common") {}

};

class EnemyGroupManager
{
public:
    EnemyGroupManager();
    ~EnemyGroupManager();

    /** To get a random enemy with the given characteristics
     *
     * @param category Enemy of the desired category
     * @param minlevel Enemy of the desired level (minimum)
     * @param maxlevel Enemy of the desired level (maximum)
     *
     * @return A random enemy level description if a suitable was found.
     *         Null if none was found.
     */
    Enemy_Level getRandomEnemy(const std::string& category, int minlevel, int maxlevel) const;

    /** To get enemies that fit in a category
     *
     * @param category Enemies of the desired category
     *
     * @return Level descriptions of enemies in the category.
     *         Empty buffer if none was found.
     */
    std::vector<Enemy_Level> getEnemiesInCategory(const std::string& category) const;


private:

    /** Container to store enemy data */
    std::map <std::string, std::vector<Enemy_Level> > _categories;


};

#endif // ENEMYGROUPMANAGER_H
