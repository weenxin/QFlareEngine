#ifndef MESSAGEENGINE_H
#define MESSAGEENGINE_H


#include "CommonIncludes.h"

class MessageEngine {

private:
    std::map<std::string,std::string> messages;
    std::string str(int i);
    std::string str(unsigned long i);
    std::string unescape(const std::string& _val);
public:
    MessageEngine();
    std::string get(const std::string& key);
    std::string get(const std::string& key, int i);
    std::string get(const std::string& key, const std::string& s);
    std::string get(const std::string& key, int i, const std::string& s);
    std::string get(const std::string& key, const std::string& s, int i);
    std::string get(const std::string& key, int i, int j);
    std::string get(const std::string& key, unsigned long i);
    std::string get(const std::string& key, unsigned long i, unsigned long j);
};

#endif // MESSAGEENGINE_H
