#ifndef AVATAR_H
#define AVATAR_H
#include "CommonIncludes.h"
#include "Entity.h"
#include "Utils.h"

class Enemy;
class Entity;
class StatBlock;

class ActionData {
public:
    int power;
    unsigned hotkey;
    bool instant_item;
    FPoint target;

    ActionData()
        : power(0)
        , hotkey(0)
        , instant_item(false)
        , target(FPoint()) {
    }
};

class Avatar : public Entity {
private:
    class Step_sfx {
    public:
        std::string id;
        std::vector<std::string> steps;
    };

    void loadLayerDefinitions();
    bool pressing_move();
    void set_direction();
    void transform();
    void untransform();
    void setAnimation(std::string name);


    std::vector<Step_sfx> step_def;

    std::vector<SoundID> sound_steps;

    std::vector<AnimationSet*> animsets; // hold the animations for all equipped items in the right order of drawing.
    std::vector<Animation*> anims; // hold the animations for all equipped items in the right order of drawing.

    short body;

    bool transform_triggered;
    std::string last_transform;

    bool attack_cursor;

    int mm_key; // mouse movement key


protected:
    virtual void resetActiveAnimation();


public:
    class Layer_gfx {
    public:
        std::string gfx;
        std::string type;
    };

    enum {
        MSG_NORMAL = 0,
        MSG_UNIQUE = 1
    };

    Avatar();
    ~Avatar();


    void init();
    void handleNewMap();
    void loadGraphics(std::vector<Layer_gfx> _img_gfx);
    void loadStepFX(const std::string& stepname);

    void logic(std::vector<ActionData> &action_queue, bool restrict_power_use);

    // transformation handling
    bool isTransforming() {
        return transform_triggered;
    }
    void checkTransform();

    void addRenders(std::vector<Renderable> &r);

    void logMsg(const std::string& str, int type);


    std::vector<std::string> layer_reference_order;
    std::vector<std::vector<unsigned> > layer_def;

    std::queue<std::pair<std::string, int> > log_msg;

    std::string attack_anim;
    bool setPowers;
    bool revertPowers;
    int untransform_power;
    StatBlock *hero_stats;
    StatBlock *charmed_stats;
    FPoint transform_pos;
    std::string transform_map;

    // vars
    int current_power;
    FPoint act_target;
    bool drag_walking;
    bool newLevelNotification;
    bool respawn;
    bool close_menus;
    bool allow_movement;
    std::vector<Timer> power_cooldown_timers;
    std::vector<Timer> power_cast_timers;
    Enemy* cursor_enemy; // enemy selected with the mouse cursor
    Enemy* lock_enemy;
    unsigned long time_played;
    bool questlog_dismissed;
    bool using_main1;
    bool using_main2;


};



#endif // AVATAR_H
