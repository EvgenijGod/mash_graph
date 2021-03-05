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
    Sprite(const std::string &type,
           const std::string &file,
           Position position,
           LAYER layer,
           Position start_corner = {0, 0},
           Position end_corner = {0, 0});

    void draw(Image &screen);

    LAYER get_layer() const {
        return draw_layer;
    }

    std::string get_type() const {return type;}

private:
    std::string type;
    Image image;
    Position pos, start_corner, end_corner;
    int img_width, img_height;
    LAYER draw_layer;
    enum Rotation {NORMAL, ROTATE_DOWN_AND_CAPTURE, CAPTURE, ROTATE_LEFT} side = NORMAL;
};
