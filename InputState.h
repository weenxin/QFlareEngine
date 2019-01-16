#ifndef INPUTSTATE_H
#define INPUTSTATE_H

#include "CommonIncludes.h"
#include "Utils.h"

class Version;

namespace Input {
    // Input action enum
    enum {
        CANCEL = 0,
        ACCEPT = 1,
        UP = 2,
        DOWN = 3,
        LEFT = 4,
        RIGHT = 5,
        BAR_1 = 6,
        BAR_2 = 7,
        BAR_3 = 8,
        BAR_4 = 9,
        BAR_5 = 10,
        BAR_6 = 11,
        BAR_7 = 12,
        BAR_8 = 13,
        BAR_9 = 14,
        BAR_0 = 15,
        CHARACTER = 16,
        INVENTORY = 17,
        POWERS = 18,
        LOG = 19,
        MAIN1 = 20,
        MAIN2 = 21,
        CTRL = 22,
        SHIFT = 23,
        ALT = 24,
        DEL = 25,
        ACTIONBAR = 26,
        ACTIONBAR_BACK = 27,
        ACTIONBAR_FORWARD = 28,
        ACTIONBAR_USE = 29,
        DEVELOPER_MENU = 30
    };
}

/**
 * class InputState
 *
 * Handles keyboard and mouse states
 */

class InputState {
protected:
    // we store mouse bindings and keyboard bindings together
    // keyboard keycodes are all positive integers, so we use negative integers for mouse buttons
    // -1 is reserved for unbound keys, so we start mouse bindings at -2
    // adding MOUSE_BIND_OFFSET to a mouse bind gives us the appropriate mouse button (mouse buttons start at 1)
    static const int MOUSE_BIND_OFFSET = 2;
    static const int JOY_AXIS_OFFSET = 2;

    // some mouse buttons are named (e.g. "Left Mouse")
    static const int MOUSE_BUTTON_NAME_COUNT = 7;

public:
    enum {
        BINDING_DEFAULT = 0,
        BINDING_ALT = 1,
        BINDING_JOYSTICK = 2
    };

    static const int KEY_COUNT = 31;
    int binding[KEY_COUNT];
    int binding_alt[KEY_COUNT];
    int binding_joy[KEY_COUNT];

    std::string binding_name[31];
    std::string mouse_button[MOUSE_BUTTON_NAME_COUNT];

    InputState(void);
    virtual ~InputState();

    virtual void initJoystick() = 0;
    void defaultJoystickBindings();
    void loadKeyBindings();
    void saveKeyBindings();
    void resetScroll();
    void lockActionBar();
    void unlockActionBar();
    void setKeybindNames();

    virtual void handle();
    virtual void defaultQwertyKeyBindings() = 0;
    virtual void hideCursor() = 0;
    virtual void showCursor() = 0;
    virtual std::string getJoystickName(int index) = 0;
    virtual std::string getKeyName(int key) = 0;
    virtual std::string getMouseButtonName(int button) = 0;
    virtual std::string getJoystickButtonName(int button) = 0;
    virtual std::string getBindingString(int key, int bindings_list = BINDING_DEFAULT) = 0;
    virtual std::string getMovementString() = 0;
    virtual std::string getAttackString() = 0;
    virtual std::string getContinueString() = 0;
    virtual int getNumJoysticks() = 0;
    virtual bool usingMouse() = 0;
    virtual void startTextInput() = 0;
    virtual void stopTextInput() = 0;
    virtual void setKeybind(int key, int binding_button, int bindings_list, std::string& keybind_msg) = 0;

    void enableEventLog();

    bool pressing[KEY_COUNT];
    bool lock[KEY_COUNT];

    // handle repeating keys, such as when holding Backspace to delete text in WidgetInput
    bool slow_repeat[KEY_COUNT];
    Timer repeat_cooldown[KEY_COUNT];

    bool done;
    Point mouse;
    std::string inkeys;
    int last_key;
    int last_button;
    int last_joybutton;
    int last_joyaxis;
    bool last_is_joystick;
    bool scroll_up;
    bool scroll_down;
    bool lock_scroll;
    bool touch_locked;
    bool lock_all;
    bool window_minimized;
    bool window_restored;
    bool window_resized;
    bool pressing_up;
    bool pressing_down;
    bool joysticks_changed;

protected:
    Point scaleMouse(unsigned int x, unsigned int y);
    virtual int getKeyFromName(const std::string& key_name) = 0;

    bool un_press[KEY_COUNT];
    Point current_touch;
    bool dump_event;

    class FingerData {
    public:
        long int id;
        Point pos;
    };
    std::vector<FingerData> touch_fingers;

    Version* file_version;
    Version* file_version_min;
};

#endif // INPUTSTATE_H
