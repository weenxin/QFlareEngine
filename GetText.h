#ifndef GETTEXT_H
#define GETTEXT_H

#include "CommonIncludes.h"

class GetText {
private:
    std::ifstream infile;
    std::string line;
    std::string sanitize(const std::string& input);

public:
    GetText();
    ~GetText();

    bool open(const std::string& filename);
    void close();
    bool next();

    std::string key;
    std::string val;
    bool fuzzy;
};
#endif // GETTEXT_H
