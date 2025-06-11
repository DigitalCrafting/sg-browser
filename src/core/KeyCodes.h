#ifndef SG_BROWSER_KEYCODES_H
#define SG_BROWSER_KEYCODES_H

#include <stdint.h>
#include <ostream>

namespace SG{
    typedef enum class KeyCode : uint16_t
    {
        // From glfw3.h
        Space               = 32,
        Apostrophe          = 39, /* ' */
        Comma               = 44, /* , */
        Minus               = 45, /* - */
        Period              = 46, /* . */
        Slash               = 47, /* / */

        D0                  = 48, /* 0 */
        D1                  = 49, /* 1 */
        D2                  = 50, /* 2 */
        D3                  = 51, /* 3 */
        D4                  = 52, /* 4 */
        D5                  = 53, /* 5 */
        D6                  = 54, /* 6 */
        D7                  = 55, /* 7 */
        D8                  = 56, /* 8 */
        D9                  = 57, /* 9 */

        Semicolon           = 59, /* ; */
        Equal               = 61, /* = */

        A                   = 65,
        B                   = 66,
        C                   = 67,
        D                   = 68,
        E                   = 69,
        F                   = 70,
        G                   = 71,
        H                   = 72,
        I                   = 73,
        J                   = 74,
        K                   = 75,
        L                   = 76,
        M                   = 77,
        N                   = 78,
        O                   = 79,
        P                   = 80,
        Q                   = 81,
        R                   = 82,
        S                   = 83,
        T                   = 84,
        U                   = 85,
        V                   = 86,
        W                   = 87,
        X                   = 88,
        Y                   = 89,
        Z                   = 90,

        LeftBracket         = 91,  /* [ */
        Backslash           = 92,  /* \ */
        RightBracket        = 93,  /* ] */
        GraveAccent         = 96,  /* ` */

        World1              = 161, /* non-US #1 */
        World2              = 162, /* non-US #2 */

        /* Function keys */
        Escape              = 256,
        Enter               = 257,
        Tab                 = 258,
        Backspace           = 259,
        Insert              = 260,
        Delete              = 261,
        Right               = 262,
        Left                = 263,
        Down                = 264,
        Up                  = 265,
        PageUp              = 266,
        PageDown            = 267,
        Home                = 268,
        End                 = 269,
        CapsLock            = 280,
        ScrollLock          = 281,
        NumLock             = 282,
        PrintScreen         = 283,
        Pause               = 284,
        F1                  = 290,
        F2                  = 291,
        F3                  = 292,
        F4                  = 293,
        F5                  = 294,
        F6                  = 295,
        F7                  = 296,
        F8                  = 297,
        F9                  = 298,
        F10                 = 299,
        F11                 = 300,
        F12                 = 301,
        F13                 = 302,
        F14                 = 303,
        F15                 = 304,
        F16                 = 305,
        F17                 = 306,
        F18                 = 307,
        F19                 = 308,
        F20                 = 309,
        F21                 = 310,
        F22                 = 311,
        F23                 = 312,
        F24                 = 313,
        F25                 = 314,

        /* Keypad */
        KP0                 = 320,
        KP1                 = 321,
        KP2                 = 322,
        KP3                 = 323,
        KP4                 = 324,
        KP5                 = 325,
        KP6                 = 326,
        KP7                 = 327,
        KP8                 = 328,
        KP9                 = 329,
        KPDecimal           = 330,
        KPDivide            = 331,
        KPMultiply          = 332,
        KPSubtract          = 333,
        KPAdd               = 334,
        KPEnter             = 335,
        KPEqual             = 336,

        LeftShift           = 340,
        LeftControl         = 341,
        LeftAlt             = 342,
        LeftSuper           = 343,
        RightShift          = 344,
        RightControl        = 345,
        RightAlt            = 346,
        RightSuper          = 347,
        Menu                = 348
    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
    {
        os << static_cast<int32_t>(keyCode);
        return os;
    }
}

// From glfw3.h
#define SG_KEY_SPACE           ::SG::Key::Space
#define SG_KEY_APOSTROPHE      ::SG::Key::Apostrophe    /* ' */
#define SG_KEY_COMMA           ::SG::Key::Comma         /* , */
#define SG_KEY_MINUS           ::SG::Key::Minus         /* - */
#define SG_KEY_PERIOD          ::SG::Key::Period        /* . */
#define SG_KEY_SLASH           ::SG::Key::Slash         /* / */
#define SG_KEY_0               ::SG::Key::D0
#define SG_KEY_1               ::SG::Key::D1
#define SG_KEY_2               ::SG::Key::D2
#define SG_KEY_3               ::SG::Key::D3
#define SG_KEY_4               ::SG::Key::D4
#define SG_KEY_5               ::SG::Key::D5
#define SG_KEY_6               ::SG::Key::D6
#define SG_KEY_7               ::SG::Key::D7
#define SG_KEY_8               ::SG::Key::D8
#define SG_KEY_9               ::SG::Key::D9
#define SG_KEY_SEMICOLON       ::SG::Key::Semicolon     /* ; */
#define SG_KEY_EQUAL           ::SG::Key::Equal         /* = */
#define SG_KEY_A               ::SG::Key::A
#define SG_KEY_B               ::SG::Key::B
#define SG_KEY_C               ::SG::Key::C
#define SG_KEY_D               ::SG::Key::D
#define SG_KEY_E               ::SG::Key::E
#define SG_KEY_F               ::SG::Key::F
#define SG_KEY_G               ::SG::Key::G
#define SG_KEY_H               ::SG::Key::H
#define SG_KEY_I               ::SG::Key::I
#define SG_KEY_J               ::SG::Key::J
#define SG_KEY_K               ::SG::Key::K
#define SG_KEY_L               ::SG::Key::L
#define SG_KEY_M               ::SG::Key::M
#define SG_KEY_N               ::SG::Key::N
#define SG_KEY_O               ::SG::Key::O
#define SG_KEY_P               ::SG::Key::P
#define SG_KEY_Q               ::SG::Key::Q
#define SG_KEY_R               ::SG::Key::R
#define SG_KEY_S               ::SG::Key::S
#define SG_KEY_T               ::SG::Key::T
#define SG_KEY_U               ::SG::Key::U
#define SG_KEY_V               ::SG::Key::V
#define SG_KEY_W               ::SG::Key::W
#define SG_KEY_X               ::SG::Key::X
#define SG_KEY_Y               ::SG::Key::Y
#define SG_KEY_Z               ::SG::Key::Z
#define SG_KEY_LEFT_BRACKET    ::SG::Key::LeftBracket   /* [ */
#define SG_KEY_BACKSLASH       ::SG::Key::Backslash     /* \ */
#define SG_KEY_RIGHT_BRACKET   ::SG::Key::RightBracket  /* ] */
#define SG_KEY_GRAVE_ACCENT    ::SG::Key::GraveAccent   /* ` */
#define SG_KEY_WORLD_1         ::SG::Key::World1        /* non-US #1 */
#define SG_KEY_WORLD_2         ::SG::Key::World2        /* non-US #2 */

/* Function keys */
#define SG_KEY_ESCAPE          ::SG::Key::Escape
#define SG_KEY_ENTER           ::SG::Key::Enter
#define SG_KEY_TAB             ::SG::Key::Tab
#define SG_KEY_BACKSPACE       ::SG::Key::Backspace
#define SG_KEY_INSERT          ::SG::Key::Insert
#define SG_KEY_DELETE          ::SG::Key::Delete
#define SG_KEY_RIGHT           ::SG::Key::Right
#define SG_KEY_LEFT            ::SG::Key::Left
#define SG_KEY_DOWN            ::SG::Key::Down
#define SG_KEY_UP              ::SG::Key::Up
#define SG_KEY_PAGE_UP         ::SG::Key::PageUp
#define SG_KEY_PAGE_DOWN       ::SG::Key::PageDown
#define SG_KEY_HOME            ::SG::Key::Home
#define SG_KEY_END             ::SG::Key::End
#define SG_KEY_CAPS_LOCK       ::SG::Key::CapsLock
#define SG_KEY_SCROLL_LOCK     ::SG::Key::ScrollLock
#define SG_KEY_NUM_LOCK        ::SG::Key::NumLock
#define SG_KEY_PRINT_SCREEN    ::SG::Key::PrintScreen
#define SG_KEY_PAUSE           ::SG::Key::Pause
#define SG_KEY_F1              ::SG::Key::F1
#define SG_KEY_F2              ::SG::Key::F2
#define SG_KEY_F3              ::SG::Key::F3
#define SG_KEY_F4              ::SG::Key::F4
#define SG_KEY_F5              ::SG::Key::F5
#define SG_KEY_F6              ::SG::Key::F6
#define SG_KEY_F7              ::SG::Key::F7
#define SG_KEY_F8              ::SG::Key::F8
#define SG_KEY_F9              ::SG::Key::F9
#define SG_KEY_F10             ::SG::Key::F10
#define SG_KEY_F11             ::SG::Key::F11
#define SG_KEY_F12             ::SG::Key::F12
#define SG_KEY_F13             ::SG::Key::F13
#define SG_KEY_F14             ::SG::Key::F14
#define SG_KEY_F15             ::SG::Key::F15
#define SG_KEY_F16             ::SG::Key::F16
#define SG_KEY_F17             ::SG::Key::F17
#define SG_KEY_F18             ::SG::Key::F18
#define SG_KEY_F19             ::SG::Key::F19
#define SG_KEY_F20             ::SG::Key::F20
#define SG_KEY_F21             ::SG::Key::F21
#define SG_KEY_F22             ::SG::Key::F22
#define SG_KEY_F23             ::SG::Key::F23
#define SG_KEY_F24             ::SG::Key::F24
#define SG_KEY_F25             ::SG::Key::F25

/* Keypad */
#define SG_KEY_KP_0            ::SG::Key::KP0
#define SG_KEY_KP_1            ::SG::Key::KP1
#define SG_KEY_KP_2            ::SG::Key::KP2
#define SG_KEY_KP_3            ::SG::Key::KP3
#define SG_KEY_KP_4            ::SG::Key::KP4
#define SG_KEY_KP_5            ::SG::Key::KP5
#define SG_KEY_KP_6            ::SG::Key::KP6
#define SG_KEY_KP_7            ::SG::Key::KP7
#define SG_KEY_KP_8            ::SG::Key::KP8
#define SG_KEY_KP_9            ::SG::Key::KP9
#define SG_KEY_KP_DECIMAL      ::SG::Key::KPDecimal
#define SG_KEY_KP_DIVIDE       ::SG::Key::KPDivide
#define SG_KEY_KP_MULTIPLY     ::SG::Key::KPMultiply
#define SG_KEY_KP_SUBTRACT     ::SG::Key::KPSubtract
#define SG_KEY_KP_ADD          ::SG::Key::KPAdd
#define SG_KEY_KP_ENTER        ::SG::Key::KPEnter
#define SG_KEY_KP_EQUAL        ::SG::Key::KPEqual

#define SG_KEY_LEFT_SHIFT      ::SG::Key::LeftShift
#define SG_KEY_LEFT_CONTROL    ::SG::Key::LeftControl
#define SG_KEY_LEFT_ALT        ::SG::Key::LeftAlt
#define SG_KEY_LEFT_SUPER      ::SG::Key::LeftSuper
#define SG_KEY_RIGHT_SHIFT     ::SG::Key::RightShift
#define SG_KEY_RIGHT_CONTROL   ::SG::Key::RightControl
#define SG_KEY_RIGHT_ALT       ::SG::Key::RightAlt
#define SG_KEY_RIGHT_SUPER     ::SG::Key::RightSuper
#define SG_KEY_MENU            ::SG::Key::Menu

#endif //SG_BROWSER_KEYCODES_H
