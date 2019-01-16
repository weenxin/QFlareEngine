#ifndef UTILSPARSING_H
#define UTILSPARSING_H

#include "Utils.h"

#include <string>
#include <typeinfo>

class LabelInfo;

namespace Parse {
    std::string trim(const std::string& s, const std::string& delimiters = " \f\n\r\t\v");

    std::string getSectionTitle(const std::string& s);
    void getKeyPair(const std::string& s, std::string& key, std::string& val);
    std::string stripCarriageReturn(const std::string& line);
    std::string getLine(std::ifstream& infile);
    bool tryParseValue(const std::type_info & type, const std::string & value, void * output);

    std::string toString(const std::type_info & type, void * value);
    int toInt(const std::string& s, int default_value = 0);
    float toFloat(const std::string &s, float default_value = 0.0);
    unsigned long toUnsignedLong(const std::string& s, unsigned long default_value = 0);
    bool toBool(std::string value);

    Point toPoint(std::string value);
    Rect toRect(std::string value);
    Color toRGB(std::string value);
    Color toRGBA(std::string value);

    int toDuration(const std::string& s);
    int toDirection(const std::string& s);
    int toAlignment(const std::string& s);

    int popFirstInt(std::string& s, char separator = 0);
    std::string popFirstString(std::string& s, char separator = 0);
    LabelInfo popLabelInfo(std::string val);
}

#endif // UTILSPARSING_H
