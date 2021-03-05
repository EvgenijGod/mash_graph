

#define GLFW_DLL
#include <GLFW/glfw3.h>

constexpr int tileSize = 16;


constexpr GLsizei PLAY_WINDOW_WIDTH = tileSize * 57, PLAY_WINDOW_HEIGHT = tileSize * 57;
constexpr GLsizei WINDOW_WIDTH = PLAY_WINDOW_WIDTH + tileSize * 10, WINDOW_HEIGHT = PLAY_WINDOW_HEIGHT;

class Position {
public:
    int x, y;

    Position (int x, int y) : x(x), y(y) {};

    bool operator == (const Position &tmp) const {
        return tmp.x == x and tmp.y == y;
    }

    bool operator != (const Position &tmp) const {
        return !(*this == tmp);
    }

    bool operator< (const Position &tmp) const {
        std::pair<int, int> first{x, y}, second{tmp.x, tmp.y};
        return first < second;
    }

    Position& operator= (const Position& tmp) = default;
};

class Pixel {
public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    bool operator == (const Pixel &tmp) const {
        return tmp.r == r and tmp.g == g and tmp.b == b and tmp.a == a;
    }

    bool operator != (const Pixel &tmp) const {
        return !(*this == tmp);
    }
};

enum LAYER {BACK_LAYER, FRONT_LAYER};

enum class MovementDir {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

