//
// Created by evgenijk on 27.02.2021.
//

#ifndef MAIN_SPRITEMANAGER_H
#define MAIN_SPRITEMANAGER_H

#include <vector>
#include "Player.h"
#include <map>

class SpriteManager {
public:
    explicit SpriteManager(const Image &img) : screen{img} {}

    void add(unsigned char cur_tile, int width_pos, int heigt_pos);

    void draw();

    Player& get_player() {return player;}

    Player player;

    ~SpriteManager() {
        delete map;
        for (auto ptr : _back) {
            delete ptr;
        }
        for (auto ptr : _front) {
            delete ptr;
        }
    }

private:
    std::vector<Sprite*> _back;
    std::vector<Sprite*> _front;
    std::map<Position, std::string> *map = new std::map<Position, std::string>();
    Image screen;
};


#endif //MAIN_SPRITEMANAGER_H
