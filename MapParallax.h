#ifndef MAPPARALLAX_H
#define MAPPARALLAX_H


#include "CommonIncludes.h"
#include "Utils.h"

class Sprite;

class MapParallaxLayer {
public:
    Sprite *sprite;
    float speed;
    FPoint fixed_speed;
    FPoint fixed_offset;
    std::string map_layer;

    MapParallaxLayer()
        : sprite(NULL)
        , speed(0)
        , map_layer("")
    {}
};


class MapParallax
{
public:
    MapParallax();
    ~MapParallax();
    void clear();
    void load(const std::string& filename);
    void setMapCenter(int x, int y);
    void render(const FPoint& cam, const std::string& map_layer);

private:
    std::vector<MapParallaxLayer> layers;
    FPoint map_center;
    size_t current_layer;
};

#endif // MAPPARALLAX_H
