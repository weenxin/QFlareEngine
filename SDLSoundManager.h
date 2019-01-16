#ifndef SDLSOUNDMANAGER_H
#define SDLSOUNDMANAGER_H

#ifdef __EMSCRIPTEN__
#include <SDL/SDL_mixer.h>
#else
#include "SDL2/SDL_mixer.h"
#endif


#include "SoundManager.h"


class SDLSoundManager : public SoundManager {
public:
    SDLSoundManager();
    ~SDLSoundManager();

    SoundID load(const std::string& filename, const std::string& errormessage);
    void unload(SoundID);
    void play(SoundID, const std::string& channel, const FPoint& pos, bool loop);
    void pauseAll();
    void resumeAll();
    void setVolumeSFX(int value);

    void loadMusic(const std::string& filename);
    void unloadMusic();
    void playMusic();
    void stopMusic();
    void setVolumeMusic(int value);
    bool isPlayingMusic();

    void logic(const FPoint& center);
    void reset();

    SoundID getLastPlayedSID();

private:
    typedef std::map<std::string, int> VirtualChannelMap;
    typedef VirtualChannelMap::iterator VirtualChannelMapIterator;

    typedef std::map<SoundID, class Sound *> SoundMap;
    typedef SoundMap::iterator SoundMapIterator;

    typedef std::map<int, class Playback> PlaybackMap;
    typedef PlaybackMap::iterator PlaybackMapIterator;

    static void channel_finished(int channel);
    void on_channel_finished(int channel);

    int SetChannelPosition(int channel, Sint16 angle, Uint8 distance);

    SoundMap sounds;
    VirtualChannelMap channels;
    PlaybackMap playback;
    FPoint lastPos;

    Mix_Music* music;
    std::string music_filename;

    SoundID last_played_sid;
};


#endif // SDLSOUNDMANAGER_H
