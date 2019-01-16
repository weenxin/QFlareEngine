#ifndef SDLINPUTSTATE_H
#define SDLINPUTSTATE_H


#include "InputState.h"
#include "Utils.h"

/**
 * class SDLInputState
 *
 * Handles keyboard and mouse states using SDL API
 */
class SDLInputState : public InputState {
public:
    SDLInputState(void);
    ~SDLInputState();

    void initJoystick();
    void defaultQwertyKeyBindings();
    void handle();
    void hideCursor();
    void showCursor();
    std::string getJoystickName(int index);
    std::string getKeyName(int key);
    std::string getMouseButtonName(int button);
    std::string getJoystickButtonName(int button);
    std::string getBindingString(int key, int bindings_list = InputState::BINDING_DEFAULT);
    std::string getMovementString();
    std::string getAttackString();
    std::string getContinueString();
    int getNumJoysticks();
    bool usingMouse();
    void startTextInput();
    void stopTextInput();
    void setKeybind(int key, int binding_button, int bindings_list, std::string& keybind_msg);

private:
    int getKeyFromName(const std::string& key_name);

    SDL_Joystick* joy;
    int joy_num;
    int joy_axis_num;
    Timer resize_cooldown;
    bool joystick_init;
    bool text_input;

    std::vector<int> joy_axis_prev;
    std::vector<int> joy_axis_deltas;
};


#endif // SDLINPUTSTATE_H
