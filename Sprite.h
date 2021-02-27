//
// Created by evgenijk on 27.02.2021.
//

#ifndef MAIN_SPRITE_H
#define MAIN_SPRITE_H

#endif //MAIN_SPRITE_H

#include <string>
//#include "shared.h"
#include "Image.h"

class Sprite {
public:
    Sprite(const std::string &type, const std::string &file, Position position, LAYER layer);

    void draw(Image &screen);

    LAYER get_layer() const {
        return draw_layer;
    }

private:
    std::string type;
    Image image;
    Position pos;
    int img_width, img_height;
    LAYER draw_layer;
};
