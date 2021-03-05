#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include <map>
#include "Sprite.h"
#include "MovingSprite.h"
#include <iostream>

struct Player {
    explicit Player(Position pos = {1, 1}, int tileSize = 16, std::map<Position, Sprite *> *map = nullptr) :
            player_sprite{"player",
                          "../resources/player.png",
                          pos,
                          MovementDir::DOWN,
                          {0, 0 },
                          {16, 16}}, coords(pos), old_coords(coords), tileSize(tileSize) {
        this->map = map;
        cur_state = MovementDir::DOWN;
    };

//    Player(const Player &tmp) : coords(tmp.coords), old_coords(coords), tileSize(tmp.tileSize) {
//        map = tmp.map;
//    };

    bool Moved() const;

    void ProcessInput(MovementDir dir);

    void Draw(Image &screen);

    MovementDir cur_state;

    bool idle = true;

private:

    MovingSprite player_sprite;
    std::map<Position, Sprite *> *map;
    Position coords{10, 10};
    Position old_coords{10, 10};
    Pixel color{.r = 255, .g = 255, .b = 0, .a = 255};
    int move_speed = 4;
    int tileSize = 16;
};

#endif //MAIN_PLAYER_H
