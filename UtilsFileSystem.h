#ifndef UTILSFILESYSTEM_H
#define UTILSFILESYSTEM_H


#include <string>
#include"CommonIncludes.h"
namespace Filesystem {
    bool pathExists(const std::string &path);
    void createDir(const std::string &path);
    bool fileExists(const std::string &filename);
    int getFileList(const std::string &dir, const std::string &ext, std::vector<std::string> &files);
    int getDirList(const std::string &dir, std::vector<std::string> &dirs);

    bool isDirectory(const std::string &path, bool show_error = true);

    bool removeFile(const std::string &file);
    bool removeDir(const std::string &dir);
    bool removeDirRecursive(const std::string &dir);

    std::string path(const std::stringstream* ss);

    bool renameFile(const std::string &oldfile, const std::string &newfile);
}

#endif // UTILSFILESYSTEM_H
