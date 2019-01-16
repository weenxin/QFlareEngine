#ifndef MODMANAGER_H
#define MODMANAGER_H

#include "CommonIncludes.h"

class Version;

class Mod {
public:
    Mod();
    ~Mod();
    Mod(const Mod &mod);
    Mod& operator=(const Mod &mod);
    bool operator== (const Mod &mod) const;
    bool operator!= (const Mod &mod) const;

    std::string getLocaleDescription(const std::string& lang);

    std::string name;
    std::string description;
    std::map<std::string, std::string> description_locale;
    std::string game;
    Version* version;
    Version* engine_min_version;
    Version* engine_max_version;
    std::vector<std::string> depends;
    std::vector<Version*> depends_min;
    std::vector<Version*> depends_max;
};



class ModManager {
private:
    void loadModList();
    void setPaths();

    std::map<std::string,std::string> loc_cache;
    std::vector<std::string> mod_paths;

    const std::vector<std::string> *cmd_line_mods;

public:
    static const bool LIST_FULL_PATHS = true;

    static const std::string FALLBACK_MOD;
    static const std::string FALLBACK_GAME;

    explicit ModManager(const std::vector<std::string> *_cmd_line_mods);
    ~ModManager();
    Mod loadMod(const std::string& name);
    void applyDepends();
    bool haveFallbackMod();
    void saveMods();
    void resetModConfig();

    // Returns the filename within the latest mod, in which the provided generic
    // filename was found.
    std::string locate(const std::string& filename);

    // Returns a list of filenames, going through all mods, in which the provided
    // generic filename is found.
    // The list is ordered the same way as locate() is searching for files, so
    // files being at later positions in the list should overwrite previous files
    //
    // Setting full_paths to false will populate the list with relative filenames,
    // that can be passed to locate() later
    std::vector<std::string> list(const std::string& path, bool full_paths);

    std::vector<std::string> mod_dirs;
    std::vector<Mod> mod_list;
};


#endif // MODMANAGER_H
