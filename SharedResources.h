#ifndef SHAREDRESOURCES_H
#define SHAREDRESOURCES_H

#include "CommonIncludes.h"

class AnimationManager;
class CombatText;
class CursorManager;
class EngineSettings;
class FontEngine;
class IconManager;
class InputState;
class MessageEngine;
class ModManager;
class RenderDevice;
class SaveLoad;
class Settings;
class SoundManager;
class TooltipManager;

extern AnimationManager *anim;
extern CombatText *comb;
extern CursorManager *curs;
extern EngineSettings *eset;
extern FontEngine *font;
extern IconManager *icons;
extern InputState *inpt;
extern MessageEngine *msg;
extern ModManager *mods;
extern RenderDevice *render_device;
extern SaveLoad *save_load;
extern Settings *settings;
extern SoundManager *snd;
extern TooltipManager *tooltipm;

#endif // SHAREDRESOURCES_H
