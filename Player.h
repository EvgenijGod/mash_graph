#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include <map>
#include "Sprite.h"


struct Point {
    int x;
    int y;
};

enum class MovementDir {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Player {
    explicit Player(Point pos = {1, 1}, int tileSize = 16, std::map<Position, Sprite*> *map = nullptr) :
            coords(pos), old_coords(coords), tileSize(tileSize) {
        this->map = map;
    };

    Player (const Player &tmp): coords(tmp.coords), old_coords(coords), tileSize(tmp.tileSize) {
        map = tmp.map;
    };

    bool Moved() const;

    void ProcessInput(MovementDir dir);

    void Draw(Image &screen);

private:
    std::map<Position, Sprite*> *map;
    Point coords{.x = 10, .y = 10};
    Point old_coords{.x = 10, .y = 10};
    Pixel color{.r = 255, .g = 255, .b = 0, .a = 255};
    int move_speed = 4;
    int tileSize = 16;

};

#endif //MAIN_PLAYER_H
