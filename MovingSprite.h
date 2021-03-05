//
// Created by evgenijk on 05.03.2021.
//

#ifndef MAIN_MOVINGSPRITE_H
#define MAIN_MOVINGSPRITE_H

#include "Image.h"

class MovingSprite {
public:
    explicit MovingSprite(const std::string &type,
                    const std::string &file,
                    Position position,
                    MovementDir layer,
                    Position start_corner = {0, 0},
                    Position end_corner = {0, 0});

    void draw(Image &screen);


    void set_position(const Position &tmp) {
        this->pos.y = tmp.y;
        this->pos.x = tmp.x;
    }

    void set_dir(const MovementDir new_dir) {
        dir = new_dir;
        switch (dir) {
            case MovementDir::UP: {
                start_corner.y = 48;
                end_corner.y = 64;
                break;
            }
            case MovementDir::DOWN: {
                start_corner.y = 0;
                end_corner.y = 16;
                break;
            }
            case MovementDir::LEFT: {
                start_corner.y = 16;
                end_corner.y = 32;
                break;
            }
            case MovementDir::RIGHT: {
                start_corner.y = 32;
                end_corner.y = 48;
                break;
            }
        }
        animating = true;
    }

    std::string get_type() const {return type;}

private:
    std::string type;
    Image image;
    Position pos, start_corner, end_corner;
    int img_width, img_height;
    LAYER draw_layer;
    MovementDir dir;
    enum Rotation {NORMAL, ROTATE_DOWN_AND_CAPTURE, CAPTURE, ROTATE_LEFT} side = NORMAL;

    unsigned short animation = 0, player_animation = 0;
    bool animating = false;
    unsigned short step = 4;
};


#endif //MAIN_MOVINGSPRITE_H
