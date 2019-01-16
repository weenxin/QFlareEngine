#ifndef UTILSDEBUG_H
#define UTILSDEBUG_H

#include"CommonIncludes.h"
class Rect;
class Point;
extern std::ostream & operator<< (std::ostream &, const SDL_Event &);
extern std::ostream & operator<< (std::ostream &, const SDL_WindowEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_KeyboardEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_Keysym &);
extern std::ostream & operator<< (std::ostream &, const SDL_MouseMotionEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_MouseButtonEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_JoyAxisEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_JoyBallEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_JoyHatEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_JoyButtonEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_QuitEvent &);
extern std::ostream & operator<< (std::ostream &, const SDL_SysWMEvent &);
extern std::ostream & operator<< (std::ostream &, const Rect &);
extern std::ostream & operator<< (std::ostream &, const Point &);

#endif // UTILSDEBUG_H
