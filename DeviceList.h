#ifndef DEVICELIST_H
#define DEVICELIST_H


#include "CommonIncludes.h"

class FontEngine;
class InputState;
class MessageEngine;
class SoundManager;
class RenderDevice;

RenderDevice* getRenderDevice(const std::string& name);
void createRenderDeviceList(MessageEngine* msg, std::vector<std::string> &rd_name, std::vector<std::string> &rd_desc);

FontEngine* getFontEngine();
SoundManager* getSoundManager();
InputState* getInputManager();

#endif // DEVICELIST_H
