//
// Created by evgenijk on 27.02.2021.
//

#ifndef MAIN_SPRITEMANAGER_H
#define MAIN_SPRITEMANAGER_H

#include "Sprite.h"
#include <vector>


class SpriteManager {
public:
    explicit SpriteManager(const Image& img): screen{img} {}

    void add(unsigned char cur_tile, int heigt_pos, int width_pos);

    void draw();

private:
    std::vector<Sprite*> _back;
    std::vector<Sprite*> _front;

    Image screen;


};


#endif //MAIN_SPRITEMANAGER_H
