#ifndef ENGINESETTINGS_H
#define ENGINESETTINGS_H


#include "CommonIncludes.h"
#include "Utils.h"
#include "WidgetLabel.h"


class EngineSettings
{
public:
    void load();

    class Misc {
    public:
        void load();

        bool save_hpmp;
        int corpse_timeout;
        bool sell_without_vendor;
        int aim_assist;
        std::string window_title;
        std::string save_prefix;
        int sound_falloff;
        int party_exp_percentage;
        bool enable_ally_collision;
        bool enable_ally_collision_ai;
        int currency_id;
        float interact_range;
        bool menus_pause;
        bool save_onload;
        bool save_onexit;
        bool save_pos_onexit;
        float camera_speed;
        bool save_buyback;
        bool keep_buyback_on_map_change;
        std::string sfx_unable_to_cast;
    };

    class Resolutions {
        public:
            void load();

            unsigned short frame_w;
            unsigned short frame_h;
            unsigned short icon_size;
            unsigned short min_screen_w;
            unsigned short min_screen_h;
            std::vector<unsigned short> virtual_heights;
            float virtual_dpi;
            bool ignore_texture_filter;
        };

    class Gameplay {
        public:
            void load();

            bool enable_playgame;
        };

    class Combat {
        public:
            void load();

            int min_absorb;
            int max_absorb;
            int min_resist;
            int max_resist;
            int min_block;
            int max_block;
            int min_avoidance;
            int max_avoidance;
            int min_miss_damage;
            int max_miss_damage;
            int min_crit_damage;
            int max_crit_damage;
            int min_overhit_damage;
            int max_overhit_damage;
        };

    class Elements {
        public:
            class Element {
            public:
                std::string id;
                std::string name;
            };

            void load();

            std::vector<Element> list;
        };

    class EquipFlags {
        public:
            class EquipFlag {
            public:
                std::string id;
                std::string name;
            };

            void load();

            std::vector<EquipFlag> list;
        };

    class PrimaryStats {
        public:
            class PrimaryStat {
            public:
                std::string id;
                std::string name;
            };

            void load();
            size_t getIndexByID(const std::string& id);

            std::vector<PrimaryStat> list;
        };

    class HeroClasses {
        public:
            class HeroClass {
            public:
                HeroClass();

                std::string name;
                std::string description;
                int currency;
                std::string equipment;
                std::string carried;
                std::vector<int> primary;
                std::vector<int> hotkeys;
                std::vector<int> powers;
                std::vector<std::string> statuses;
                std::string power_tree;
                int default_power_tab;
                std::vector<int> options;
            };

            void load();
            HeroClass* getByName(const std::string& name);

            std::vector<HeroClass> list;
        };
    class DamageTypes {
        public:
            class DamageType {
            public:
                std::string id;
                std::string name;
                std::string name_min;
                std::string name_max;
                std::string description;
                std::string min;
                std::string max;
            };

            void load();

            std::vector<DamageType> list;
            size_t count; // damage_types.size() * 2, to account for min & max
        };

        class DeathPenalty {
        public:
            void load();

            bool enabled;
            bool permadeath;
            int currency;
            int xp;
            int xp_current;
            bool item;
        };

        class Tooltips {
        public:
            void load();

            int offset;
            int width;
            int margin;
            int margin_npc;
            int background_border;
        };

        class Loot {
        public:
            void load();

            int tooltip_margin;
            bool autopickup_currency;
            float autopickup_range;
            std::string currency;
            float vendor_ratio;
            float vendor_ratio_buyback;
            std::string sfx_loot;
            int drop_max;
            int drop_radius;
            float hide_radius;
        };

        class Tileset {
        public:
            void load();

            enum {
                TILESET_ISOMETRIC = 0,
                TILESET_ORTHOGONAL = 1
            };

            float units_per_pixel_x;
            float units_per_pixel_y;
            unsigned short tile_w;
            unsigned short tile_h;
            unsigned short tile_w_half;
            unsigned short tile_h_half;
            unsigned short orientation;
        };

        class Widgets {
        public:
            void load();

            Color selection_rect_color;
            Point colorblind_highlight_offset;
            Point tab_padding;
            LabelInfo slot_quantity_label;
            Color slot_quantity_bg_color;
            Point listbox_text_margin;
        };

        class XPTable {
        public:
            void load();

            unsigned long getLevelXP(int level);
            int getMaxLevel();
            int getLevelFromXP(unsigned long level_xp);

        private:
            std::vector<unsigned long> xp_table;
        };

        Misc misc;
        Resolutions resolutions;
        Gameplay gameplay;
        Combat combat;
        Elements elements;
        EquipFlags equip_flags;
        PrimaryStats primary_stats;
        HeroClasses hero_classes;
        DamageTypes damage_types;
        DeathPenalty death_penalty;
        Tooltips tooltips;
        Loot loot;
        Tileset tileset;
        Widgets widgets;
        XPTable xp;
};

#endif // ENGINESETTINGS_H
