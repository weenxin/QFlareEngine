#ifndef FILEPARSER_H
#define FILEPARSER_H

#include "CommonIncludes.h"

class FileParser
{
private:
    void errorBuf(const char* buffer);

    std::vector<std::string> filenames;
    unsigned current_index;
    bool is_mod_file;
    int error_mode;

    std::ifstream infile;
    std::string line;

    unsigned line_number;

    FileParser* include_fp;

public:
    enum {
        ERROR_NONE = 0,
        ERROR_NORMAL = 1
    };
    static const bool MOD_FILE = true;

    FileParser();
    ~FileParser();

    /**
     * @brief open
     * @param filename
     * The generic filename to be opened. This generic filename will be located
     * by the ModManager.
     * If this is a directory, all files in this directory will be opened.
     *
     * @param flags
     * Optional parameter, has two bits which can be changed:
     * FULL_PATH - when enabled, filename won't be located by the ModManager
     * NO_ERROR - when enabled, suppresses the error message when a file can't
     * be opened
     *
     * @return true if file could be opened successfully for reading.
     */
    bool open(const std::string& filename, bool _is_mod_file, int _error_mode);

    void close();
    bool next();
    std::string getRawLine();
    void error(const char* format, ...);
    void incrementLineNum();

    /**
     * @brief new_section is set to true whenever a new [section] starts. If opening
     * multiple files it is also true whenever a new file is opened. Note: This
     * applies to only the second and any subsequent file. The first file doesn't
     * set new_section to true for the first line.
     */
    bool new_section;
    std::string section;
    std::string key;
    std::string val;


};

#endif // FILEPARSER_H
