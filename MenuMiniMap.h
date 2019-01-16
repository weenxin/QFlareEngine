#ifndef MENUMINIMAP_H
#define MENUMINIMAP_H

#include "CommonIncludes.h"
#include "Utils.h"
#include"Menu.h"

class MapCollision;
class Sprite;
class WidgetLabel;

class MenuMiniMap : public Menu {
private:
    Color color_wall;
    Color color_obst;
    Color color_hero;

    Sprite *map_surface;
    Sprite *map_surface_2x;
    Point map_size;

    Rect pos;
    WidgetLabel *label;
    Sprite *compass;

    int current_zoom;

    void createMapSurface(Sprite** target_surface, int w, int h);
    // void renderIso(const FPoint& hero_pos);
    // void renderOrtho(const FPoint& hero_pos);
    void renderMapSurface(const FPoint& hero_pos);
    void prerenderOrtho(MapCollision *collider, Sprite** target_surface, int zoom);
    void prerenderIso(MapCollision *collider, Sprite** target_surface, int zoom);

public:
    MenuMiniMap();
    ~MenuMiniMap();
    void align();

    void render();
    void render(const FPoint& hero_pos);
    void prerender(MapCollision *collider, int map_w, int map_h);
    void setMapTitle(const std::string& map_title);
};

#endif // MENUMINIMAP_H
