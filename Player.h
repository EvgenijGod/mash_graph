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

    explicit Player(Position pos, int tileSize, std::map<Position, Sprite *> *map);

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

    void damage() {
        if (HP_LVL >= 2) {
            std::cout << "DAMAGED " << HP_LVL << "\n";
            _lives[HP_LVL]->draw_normal = false;
            //std::cout
            make_damage_effect = 250;
            player_sprite.set_position(default_coords);
            player_sprite.set_dir(MovementDir::DOWN);
            coords = default_coords;
            old_coords = default_coords;
            HP_LVL -= 1;
        }
        // TODO: add death
    }

    void throw_snowball() {
        if (hit_freeze == 0) {
            _balls.emplace_back(new SnowBall("snowball",
                                             "../resources/snowball_sprite.png",
                                             coords,
                                             cur_state,
                                             Position{0, 0},
                                             Position{16, 16},
                                             map));
            hit_freeze = 10;
        }
    }

private:
    int HP_LVL = 5;
    std::vector<Sprite *> _lives;
    std::deque<SnowBall *> _balls;
    MovingSprite player_sprite;
    MovementDir cur_state = MovementDir::UP;
    std::map<Position, Sprite *> *map;
    Position coords{10, 10}, default_coords{0, 0};
    Position old_coords{10, 10};
    Pixel color{.r = 255, .g = 255, .b = 0, .a = 255};
    int move_speed = 4;
    int tileSize = 16;
    int hit_freeze = 0;

    int make_damage_effect = 0;
};

#endif //MAIN_PLAYER_H
