#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include <map>
//#include "Sprite.h"
//#include "MovingSprite.h"
#include <iostream>
#include <deque>
#include <vector>
#include "SnowBall.h"

struct Player {

    explicit Player(Position pos, int tileSize, std::map<Position, Sprite *> *map, int &floor_complete);

    bool Moved() const;

    void ProcessInput(MovementDir dir);

    void Draw(Image &screen);

    ~Player() {
        for (auto ptr : _lives) {
            delete ptr;
        }
        for (auto ptr : _balls) {
            delete ptr;
        }
    }

    void damage();

    void throw_snowball() ;

private:

    int HP_LVL = 5;
    std::vector<Sprite *> _lives;
    std::deque<SnowBall *> _balls;
    MovingSprite player_sprite;
    MovementDir cur_state = MovementDir::DOWN;
    std::map<Position, Sprite *> *map;
    int &floor_complete;
    Position coords{10, 10}, default_coords{0, 0};
    Position old_coords{10, 10};
    Pixel color{.r = 255, .g = 255, .b = 0, .a = 255};
    int move_speed = 4;
    int tileSize = 16;
    int hit_freeze = 0;

    int make_damage_effect = 0;
};

#endif //MAIN_PLAYER_H
