#include "raylib-cpp.hpp"

class InputSupport {
private: 
    std::vector<int> listOfkeys = {
        KEY_NULL,
        KEY_ENTER,
        KEY_SPACE,
        KEY_ESCAPE,
        KEY_TAB,
        KEY_UP,
        KEY_DOWN,
        KEY_RIGHT,
        KEY_LEFT,
        KEY_Q,
        KEY_W,
        KEY_E,
        KEY_R,
        KEY_T,
        KEY_Y,
        KEY_U,
        KEY_I,
        KEY_O,
        KEY_P,
        KEY_A,
        KEY_S,
        KEY_D,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_Z,
        KEY_X,
        KEY_C,
        KEY_V,
        KEY_B,
        KEY_N,
    };
public:
    enum Key {
        NULL_KEY,
        ENTER,
        SPACE,
        ESCAPE,
        TAB,
        UP_ARROW,
        DOWN_ARROW,
        RIGHT_ARROW,
        LEFT_ARROW,
        Q,
        W,
        E,
        R,
        T,
        Y,
        U,
        I,
        O,
        P,
        A,
        S,
        D,
        F,
        G,
        H,
        J,
        K,
        L,
        M,
        Z,
        X,
        C,
        V,
        B,
        N,
        MOUSE_LEFT,
    };
    enum InputType {
        PRESSED,
        DOWN,
        RELEASED,
        DEFAULT,
    };
    InputSupport();
    ~InputSupport();
    std::vector<int> getKeysPressed();
    std::vector<int> getKeysDown();
    std::vector<int> getKeysReleased();
    bool isMouseDown();
    bool isMouseReleased();
    bool isMousePressed();
};