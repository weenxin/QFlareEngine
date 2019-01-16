#ifndef ICONMANAGER_H
#define ICONMANAGER_H

#include "Utils.h"

class Sprite;
class Image;

class IconSet {
public:
    IconSet();

    Sprite *gfx;
    int id_begin;
    int id_end;
    int columns;
};

class IconManager {
public:
    IconManager();
    ~IconManager();

    void setIcon(int icon_id, Point dest_pos);
    void render();
    void renderToImage(Image *img);

    Point text_offset;

private:
    bool loadIconSet(IconSet& icon_set, const std::string& filename, int first_id);

    std::vector<IconSet> icon_sets;
    IconSet *current_set;
    Rect current_src;
    Rect current_dest;
};

#endif // ICONMANAGER_H
