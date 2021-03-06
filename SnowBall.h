//
// Created by evgenijk on 05.03.2021.
//

#ifndef MAIN_SNOWBALL_H
#define MAIN_SNOWBALL_H

#include "MovingSprite.h"
#include "Sprite.h"
#include <map>
#include <iostream>

class SnowBall : public MovingSprite{
public:

    explicit SnowBall(const std::string &type,
                          const std::string &file,
                          Position position,
                          MovementDir layer,
                          Position start_corner = {0, 0},
                          Position end_corner = {0, 0},
                            std::map<Position, Sprite *> *map = nullptr);

    void set_dir(const MovementDir new_dir) ;

    void draw_animation(Image &screen) ;

    bool is_alive() const{
        return need_draw;
    }

private:
    std::map<Position, Sprite *> *map;
    int movement_speed = 4;
};


#endif //MAIN_SNOWBALL_H
