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

    virtual void draw_animation(Image &screen);

    virtual void set_position(const Position &tmp) {
        this->pos.y = tmp.y;
        this->pos.x = tmp.x;
    }

    virtual void set_dir(const MovementDir new_dir) ;

    std::string get_type() const {return type;}

    bool draw_normal = true;
    bool need_draw = true;

protected:
    std::string type;
    Image image;
    Position pos, start_corner, end_corner;
    int img_width, img_height;
    LAYER draw_layer;
    enum Rotation {NORMAL, LEFT, RIGHT, DOWN, SNOWBALL_RIGHT} side = NORMAL;

    unsigned short animation = 0, player_animation = 0;
    bool animating = false;
    unsigned short step = 4;
    MovementDir dir;
};


#endif //MAIN_MOVINGSPRITE_H
