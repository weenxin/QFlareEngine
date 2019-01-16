#ifndef TILESET_H
#define TILESET_H

#include "CommonIncludes.h"
#include "Utils.h"

/**
 * Describes a tile by its location \a src in the tileset sprite and
 * by the \a offset to be applied when rendering it on screen.
 * The offset is measured from upper left corner to the logical midpoint
 * of the tile at groundlevel.
 */
class Tile_Def {
public:
    Point offset;
    Sprite *tile;// inside graphics not used
    Tile_Def()
        : tile(NULL) {
    }
};

class TileSet
{
private:
    class Tile_Anim {
    public:
        // Number of frames in this animation. if 0 no animation.
        // 1 makes no sense as it would produce astatic animation.
        unsigned short frames;
        unsigned short current_frame; // is in range 0..(frames-1)
        unsigned short duration; // how long the current frame is already displayed in ticks.
        std::vector<Point> pos; // position of each image.
        std::vector<unsigned short> frame_duration; // duration of each image in ticks. 0 will be treated the same as 1.
        Tile_Anim() {
            frames = 0;
            current_frame = 0;
            duration = 0;
        }
    };

    void loadGraphics(const std::string& filename, Sprite** sprite);
    void reset();

    std::string current_filename;

    std::vector<Sprite*> sprites;
    std::vector<Tile_Anim> anim;

public:
    // functions
    TileSet();
    ~TileSet();
    void load(const std::string& filename);
    void logic();

    std::vector<Tile_Def> tiles;

    // oversize of the largest tile available, in number of tiles.
    int max_size_x;
    int max_size_y;
};

#endif // TILESET_H
