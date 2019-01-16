#include "Utils.h"
#include <cmath>
#include <stdarg.h>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string.h>

int Utils::LOCK_INDEX = 0;

bool Utils::LOG_FILE_INIT = false;
bool Utils::LOG_FILE_CREATED = false;
std::string Utils::LOG_PATH;
std::queue<std::pair<Utils::LogLevel, std::string> > Utils::LOG_MSG;

/**
 * Point: A simple x/y coordinate structure
 */
Point::Point()
    : x(0)
    , y(0)
{}

Point::Point(int _x, int _y)
    : x(_x)
    , y(_y)
{}

Point::Point(const FPoint& _fp)
    : x(static_cast<int>(_fp.x))
    , y(static_cast<int>(_fp.y))
{}

/**
 * FPoint: A floating point version of Point
 */
FPoint::FPoint()
    : x(0)
    , y(0)
{}

FPoint::FPoint(float _x, float _y)
    : x(_x)
    , y(_y)
{}

FPoint::FPoint(Point _p)
    : x(static_cast<float>(_p.x))
    , y(static_cast<float>(_p.y))
{}

void FPoint::align() {
    // this rounds the float values to the nearest multiple of 1/(2^4)
    // 1/(2^4) was chosen because it's a "nice" floating point number, removing 99% of rounding errors
    x = floorf(x / 0.0625f) * 0.0625f;
    y = floorf(y / 0.0625f) * 0.0625f;
}

/**
 * Rect: A rectangle defined by the top-left x/y and the width/height
 */
Rect::Rect()
    : x(0)
    , y(0)
    , w(0)
    , h(0)
{}

Rect::Rect(int _x, int _y, int _w, int _h)
    : x(_x)
    , y(_y)
    , w(_w)
    , h(_h)
{}

Rect::Rect(const SDL_Rect& _r)
    : x(_r.x)
    , y(_r.y)
    , w(_r.w)
    , h(_r.h)
{}

Rect::operator SDL_Rect() const {
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = w;
    r.h = h;
    return r;
}

/**
 * Color: RGBA color; defaults to 100% opaque black
 */
Color::Color()
    : r(0)
    , g(0)
    , b(0)
    , a(255)
{}

Color::Color(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a)
    : r(_r)
    , g(_g)
    , b(_b)
    , a(_a)
{}

Color::operator SDL_Color() const {
    SDL_Color c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.a = a;
    return c;
}

bool Color::operator ==(const Color &other) {
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

bool Color::operator !=(const Color &other) {
    return !((*this) == other);
}

Timer::Timer(unsigned _duration)
    : current(0)
    , duration(_duration)
{
}

unsigned Timer::getCurrent() {
    return current;
}

unsigned Timer::getDuration() {
    return duration;
}

void Timer::setCurrent(unsigned val) {
    current = val;
    if (current > duration)
        current = duration;
}

void Timer::setDuration(unsigned val) {
    current = duration = val;
}

bool Timer::tick() {
    if (current > 0)
        current--;

    if (current == 0)
        return true;

    return false;
}

bool Timer::isEnd() {
    return current == 0;
}

bool Timer::isBegin() {
    return current == duration;
}

void Timer::reset(int type) {
    if (type == Timer::END)
        current = 0;
    else if (type == Timer::BEGIN)
        current = duration;
}

//FPoint Utils::screenToMap(int x, int y, float camx, float camy) {
//    FPoint r;
//    if (eset->tileset.orientation == eset->tileset.TILESET_ISOMETRIC) {
//        float scrx = float(x - settings->view_w_half) * 0.5f;
//        float scry = float(y - settings->view_h_half) * 0.5f;

//        r.x = (eset->tileset.units_per_pixel_x * scrx) + (eset->tileset.units_per_pixel_y * scry) + camx;
//        r.y = (eset->tileset.units_per_pixel_y * scry) - (eset->tileset.units_per_pixel_x * scrx) + camy;
//    }
//    else {
//        r.x = static_cast<float>(x - settings->view_w_half) * (eset->tileset.units_per_pixel_x) + camx;
//        r.y = static_cast<float>(y - settings->view_h_half) * (eset->tileset.units_per_pixel_y) + camy;
//    }
//    return r;
//}



///**
// * Returns a point (in map units) of a given (x,y) tupel on the screen
// * when the camera is at a given position.
// */
//Point Utils::mapToScreen(float x, float y, float camx, float camy) {
//    Point r;

//    // adjust to the center of the viewport
//    // we do this calculation first to avoid negative integer division
//    float adjust_x = (settings->view_w_half + 0.5f) * eset->tileset.units_per_pixel_x;
//    float adjust_y = (settings->view_h_half + 0.5f) * eset->tileset.units_per_pixel_y;

//    if (eset->tileset.orientation == eset->tileset.TILESET_ISOMETRIC) {
//        r.x = int(floorf(((x - camx - y + camy + adjust_x)/eset->tileset.units_per_pixel_x)+0.5f));
//        r.y = int(floorf(((x - camx + y - camy + adjust_y)/eset->tileset.units_per_pixel_y)+0.5f));
//    }
//    else if (eset->tileset.orientation == eset->tileset.TILESET_ORTHOGONAL) {
//        r.x = int((x - camx + adjust_x)/eset->tileset.units_per_pixel_x);
//        r.y = int((y - camy + adjust_y)/eset->tileset.units_per_pixel_y);
//    }
//    return r;
//}



///**
// * Apply parameter distance to position and direction
// */
//FPoint Utils::calcVector(const FPoint& pos, int direction, float dist) {
//    FPoint p;
//    p.x = pos.x;
//    p.y = pos.y;

//    float dist_straight = dist;
//    float dist_diag = dist * 0.7071f; //  1/sqrt(2)

//    switch (direction) {
//        case 0:
//            p.x -= dist_diag;
//            p.y += dist_diag;
//            break;
//        case 1:
//            p.x -= dist_straight;
//            break;
//        case 2:
//            p.x -= dist_diag;
//            p.y -= dist_diag;
//            break;
//        case 3:
//            p.y -= dist_straight;
//            break;
//        case 4:
//            p.x += dist_diag;
//            p.y -= dist_diag;
//            break;
//        case 5:
//            p.x += dist_straight;
//            break;
//        case 6:
//            p.x += dist_diag;
//            p.y += dist_diag;
//            break;
//        case 7:
//            p.y += dist_straight;
//            break;
//    }
//    return p;
//}

//float Utils::calcDist(const FPoint& p1, const FPoint& p2) {
//    return sqrtf((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
//}

///**
// * is target within the area defined by center and radius?
// */
//bool Utils::isWithinRadius(const FPoint& center, float radius, const FPoint& target) {
//    return (calcDist(center, target) < radius);
//}

///**
// * is target within the area defined by rectangle r?
// */
//bool Utils::isWithinRect(const Rect& r, const Point& target) {
//    return target.x >= r.x && target.y >= r.y && target.x < r.x+r.w && target.y < r.y+r.h;
//}

//unsigned char Utils::calcDirection(float x0, float y0, float x1, float y1) {
//    float theta = calcTheta(x0, y0, x1, y1);
//    float val = theta / (static_cast<float>(M_PI)/4);
//    int dir = static_cast<int>(((val < 0) ? ceilf(val-0.5f) : floorf(val+0.5f)) + 4);
//    dir = (dir + 1) % 8;
//    if (dir >= 0 && dir < 8)
//        return static_cast<unsigned char>(dir);
//    else
//        return 0;
//}

//// convert cartesian to polar theta where (x1,x2) is the origin
//float Utils::calcTheta(float x1, float y1, float x2, float y2) {
//    // calculate base angle
//    float dx = x2 - x1;
//    float dy = y2 - y1;
//    float exact_dx = x2 - x1;
//    float theta;

//    // convert cartesian to polar coordinates
//    if (exact_dx == 0) {
//        if (dy > 0.0) theta = static_cast<float>(M_PI)/2.0f;
//        else theta = static_cast<float>(-M_PI)/2.0f;
//    }
//    else {
//        theta = atanf(dy/dx);
//        if (dx < 0.0 && dy >= 0.0) theta += static_cast<float>(M_PI);
//        if (dx < 0.0 && dy < 0.0) theta -= static_cast<float>(M_PI);
//    }
//    return theta;
//}

//std::string Utils::abbreviateKilo(int amount) {
//    std::stringstream ss;
//    if (amount < 1000)
//        ss << amount;
//    else
//        ss << (amount/1000) << msg->get("k");

//    return ss.str();
//}


//void Utils::alignToScreenEdge(int alignment, Rect *r) {
//    if (!r) return;

//    if (alignment == ALIGN_TOPLEFT) {
//        // do nothing
//    }
//    else if (alignment == ALIGN_TOP) {
//        r->x = (settings->view_w_half - r->w/2) + r->x;
//    }
//    else if (alignment == ALIGN_TOPRIGHT) {
//        r->x = (settings->view_w - r->w) + r->x;
//    }
//    else if (alignment == ALIGN_LEFT) {
//        r->y = (settings->view_h_half - r->h/2) + r->y;
//    }
//    else if (alignment == ALIGN_CENTER) {
//        r->x = (settings->view_w_half - r->w/2) + r->x;
//        r->y = (settings->view_h_half - r->h/2) + r->y;
//    }
//    else if (alignment == ALIGN_RIGHT) {
//        r->x = (settings->view_w - r->w) + r->x;
//        r->y = (settings->view_h_half - r->h/2) + r->y;
//    }
//    else if (alignment == ALIGN_BOTTOMLEFT) {
//        r->y = (settings->view_h - r->h) + r->y;
//    }
//    else if (alignment == ALIGN_BOTTOM) {
//        r->x = (settings->view_w_half - r->w/2) + r->x;
//        r->y = (settings->view_h - r->h) + r->y;
//    }
//    else if (alignment == ALIGN_BOTTOMRIGHT) {
//        r->x = (settings->view_w - r->w) + r->x;
//        r->y = (settings->view_h - r->h) + r->y;
//    }
//    else {
//        // do nothing
//    }
//}


///**
// * These functions provide a unified way to log messages, printf-style
// */
//void Utils::logInfo(const char* format, ...) {
//    va_list args;


//    char file_buf[BUFSIZ];
//    va_start(args, format);
//    vsnprintf(file_buf, BUFSIZ, format, args);
//    va_end(args);

//    if (!LOG_FILE_INIT) {
//        LOG_MSG.push(std::pair<LogLevel, std::string>(Log_Info, std::string(file_buf)));
//    }
//    else if (LOG_FILE_CREATED) {
//        FILE *log_file = fopen(LOG_PATH.c_str(), "a");
//        if (log_file) {
//            fprintf(log_file, "INFO: ");
//            fprintf(log_file, "%s", file_buf);
//            fprintf(log_file, "\n");
//            fclose(log_file);
//        }
//    }

//}

//void Utils::logError(const char* format, ...) {
//    va_list args;

//    char file_buf[BUFSIZ];
//    va_start(args, format);
//    vsnprintf(file_buf, BUFSIZ, format, args);
//    va_end(args);

//    if (!LOG_FILE_INIT) {
//        LOG_MSG.push(std::pair<LogLevel, std::string>(Log_Crital, std::string(file_buf)));
//    }
//    else if (LOG_FILE_CREATED) {
//        FILE *log_file = fopen(LOG_PATH.c_str(), "a");
//        if (log_file) {
//            fprintf(log_file, "ERROR: ");
//            fprintf(log_file, "%s", file_buf);
//            fprintf(log_file, "\n");
//            fclose(log_file);
//        }
//    }
//}

//void Utils::logErrorDialog(const char* dialog_text, ...) {
//    char pre_buf[BUFSIZ];
//    char buf[BUFSIZ];
//    snprintf(pre_buf, BUFSIZ, "%s%s", "FLARE Error\n", dialog_text);

//    va_list args;
//    va_start(args, dialog_text);
//    vsnprintf(buf, BUFSIZ, pre_buf, args);
//    QMessageBox::critical(nullptr,"FLARE Error",buf);
//    va_end(args);
//}


//void Utils::createLogFile() {
//    LOG_PATH = settings->path_conf + "/flare_log.txt";

//    // always create a new log file on each launch
//    if (Filesystem::fileExists(LOG_PATH)) {
//        Filesystem::removeFile(LOG_PATH);
//    }

//    FILE *log_file = fopen(LOG_PATH.c_str(), "w+");
//    if (log_file) {
//        LOG_FILE_CREATED = true;
//        fprintf(log_file, "### Flare log file\n\n");

//        while (!LOG_MSG.empty()) {
//            if (LOG_MSG.front().first == SDL_LOG_PRIORITY_INFO)
//                fprintf(log_file, "INFO: ");
//            else if (LOG_MSG.front().first == SDL_LOG_PRIORITY_ERROR)
//                fprintf(log_file, "ERROR: ");

//            fprintf(log_file, "%s", LOG_MSG.front().second.c_str());
//            fprintf(log_file, "\n");

//            LOG_MSG.pop();
//        }
//        fclose(log_file);
//    }
//    else {
//        while (!LOG_MSG.empty())
//            LOG_MSG.pop();

//        logError("Utils: Could not create log file.");
//    }

//    LOG_FILE_INIT = true;
//}


//void Utils::Exit(int code) {
//    lockFileWrite(-1);
//    exit(code);
//}


//void Utils::createSaveDir(int slot) {
//    // game slots are currently 1-4
//    if (slot == 0) return;

//    std::stringstream ss;
//    ss << settings->path_user << "saves/" << eset->misc.save_prefix << "/";

//    Filesystem::createDir(Filesystem::path(&ss));

//    ss << slot;
//    Filesystem::createDir(Filesystem::path(&ss));
//}


//void Utils::removeSaveDir(int slot) {
//    // game slots are currently 1-4
//    if (slot == 0) return;

//    std::stringstream ss;
//    ss << settings->path_user << "saves/" << eset->misc.save_prefix << "/" << slot;

//    if (Filesystem::isDirectory(Filesystem::path(&ss))) {
//        Filesystem::removeDirRecursive(Filesystem::path(&ss));
//    }
//}





