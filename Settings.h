#ifndef SETTINGS_H
#define SETTINGS_H


#include "CommonIncludes.h"

#include <typeinfo>

class Settings {
public:
    enum {
        LOOT_TIPS_DEFAULT = 0,
        LOOT_TIPS_SHOW_ALL = 1,
        LOOT_TIPS_HIDE_ALL = 2
    };

    enum {
        MINIMAP_NORMAL = 0,
        MINIMAP_2X = 1,
        MINIMAP_HIDDEN = 2
    };

    Settings();
    void loadSettings();
    void saveSettings();
    void loadDefaults();
    void updateScreenVars();

    // Video Settings
    bool fullscreen;
    unsigned short screen_w;
    unsigned short screen_h;
    bool hwsurface;
    bool vsync;
    bool texture_filter;
    bool dpi_scaling;
    unsigned short max_frames_per_sec;
    std::string render_device_name;
    bool change_gamma;
    float gamma;
    bool parallax_layers;

    // Audio Settings
    unsigned short music_volume;
    unsigned short sound_volume;

    // Input Settings
    bool mouse_move;
    bool mouse_move_swap;
    bool mouse_move_attack;
    bool enable_joystick;
    int joystick_device;
    bool mouse_aim;
    bool no_mouse;
    int joy_deadzone;

    // Interface Settings
    bool combat_text;
    bool show_fps;
    bool colorblind;
    bool hardware_cursor;
    bool dev_mode;
    bool dev_hud;
    int loot_tooltips;
    bool statbar_labels;
    bool auto_equip;
    bool subtitles;
    int minimap_mode;
    bool entity_markers;

    // Language Settings
    std::string language;

    // Misc
    int prev_save_slot;

    /**
     * NOTE Everything below is not part of the user's settings.txt, but somehow ended up here
     * TODO Move these to more appropriate locations?
     */

    // Path info
    std::string path_conf; // user-configurable settings files
    std::string path_user; // important per-user data (saves)
    std::string path_data; // common game data
    std::string custom_path_data; // user-defined replacement for PATH_DATA

    // Command-line settings
    std::string load_slot;
    std::string load_script;

    // Misc
    unsigned short view_w;
    unsigned short view_h;
    unsigned short view_w_half;
    unsigned short view_h_half;
    float view_scaling;

    bool audio;

    bool touchscreen;
    bool mouse_scaled; // mouse position is automatically scaled to view_w * view_h resolution

    bool show_hud;

    float encounter_dist;

    bool soft_reset;

private:
    class ConfigEntry {
    public:
        std::string name;
        const std::type_info *type;
        std::string default_val;
        void *storage;
        std::string comment;
    };
    std::vector<ConfigEntry> config;

    void setConfigDefault(size_t index, const std::string& name, const std::type_info *type, const std::string& default_val, void *storage, const std::string& comment);
    size_t getConfigEntry(const std::string& name);
    void loadMobileDefaults();
};

#endif // SETTINGS_H
