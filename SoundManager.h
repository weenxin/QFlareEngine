#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H


#include "CommonIncludes.h"
#include "Utils.h"

/**
 * class SoundManager
 *
 * SoundManager takes care of loading and playing of sound effects,
 * each sound is referenced with a hash SoundID for playing. If a
 * sound is already loaded, the SoundID for currently loaded sound
 * will be returned by SoundManager::load().
 */


class SoundManager {
public:
    static const std::string DEFAULT_CHANNEL;
    static const FPoint NO_POS;
    static const bool LOOP = true;

    virtual ~SoundManager() {}

    virtual SoundID load(const std::string& filename, const std::string& errormessage) = 0;
    virtual void unload(SoundID) = 0;
    virtual void play(SoundID, const std::string& channel, const FPoint& pos, bool loop) = 0;
    virtual void pauseAll() = 0;
    virtual void resumeAll() = 0;
    virtual void setVolumeSFX(int value) = 0;

    virtual void loadMusic(const std::string& filename) = 0;
    virtual void unloadMusic() = 0;
    virtual void playMusic() = 0;
    virtual void stopMusic() = 0;
    virtual void setVolumeMusic(int value) = 0;
    virtual bool isPlayingMusic() = 0;

    virtual void logic(const FPoint& center) = 0;
    virtual void reset() = 0;

    virtual SoundID getLastPlayedSID() = 0;
};

/**
 * class Playback
 *
 * Playback class is used for creating playback objects,
 * it includes API independent sound id returned by SoundManager::load(), sound location,
 * sound duration properties and virtual channel name, on which sound should be played
**/
class Playback {
public:
    Playback()
        : sid(-1)
        , location(FPoint())
        , loop(false)
        , paused(false)
        , finished(false) {
    }

    SoundID sid;
    std::string virtual_channel;
    FPoint location;
    bool loop;
    bool paused;
    bool finished;
};



#endif // SOUNDMANAGER_H
