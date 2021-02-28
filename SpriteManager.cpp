//
// Created by evgenijk on 27.02.2021.
//

#include "SpriteManager.h"
#include <iostream>

void SpriteManager::add(unsigned char cur_tile, int heigt_pos, int width_pos) {
    Sprite *tmp;
    //std::cout << cur_tile << std::endl;
    switch (cur_tile) {
        case ' ':
            tmp = new Sprite("empty", "../resources/alex.png", {width_pos, heigt_pos}, LAYER::BACK_LAYER);
            break;
        case '@':
            tmp = new Sprite("empty", "../resources/alex.png", {width_pos, heigt_pos}, LAYER::BACK_LAYER);
            break;
        case '.':
            tmp = new Sprite("empty", "../resources/alex.png", {width_pos, heigt_pos}, LAYER::BACK_LAYER);
            break;
        case '#':
            tmp = new Sprite("empty", "../resources/wall.png", {width_pos, heigt_pos}, LAYER::BACK_LAYER);
            break;
        case 'x':
            tmp = new Sprite("empty", "../resources/alex.png", {width_pos, heigt_pos}, LAYER::BACK_LAYER);
            break;
//        default:
//            tmp = new Sprite("empty", "../resources/alex.png", {width_pos, heigt_pos}, LAYER::BACK_LAYER);
//            break;
    }

    if (tmp->get_layer() == LAYER::BACK_LAYER) {
        _back.emplace_back(tmp);
    } else if (tmp->get_layer() == LAYER::FRONT_LAYER) {
        _front.emplace_back(tmp);
    }
}

void SpriteManager::draw() {
    for (auto it : _back) {
        it->draw(screen);
    }

    for (auto it : _front) {
        it->draw(screen);
    }
}
