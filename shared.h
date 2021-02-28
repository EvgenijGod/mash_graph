

#define GLFW_DLL
#include <GLFW/glfw3.h>

constexpr int tileSize = 32;


constexpr GLsizei WINDOW_WIDTH = 1024 - tileSize, WINDOW_HEIGHT = 1024 - tileSize;

class Position {
public:
    int x, y;

    bool operator == (Position tmp) const {
        return tmp.x == x and tmp.y == y;
    }
};

class Pixel {
public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    bool operator == (Pixel &tmp) const {
        return tmp.r == r and tmp.g == g and tmp.b == b and tmp.a == a;
    }
};

enum LAYER {BACK_LAYER, FRONT_LAYER};

