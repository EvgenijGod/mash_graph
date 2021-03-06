//
// Created by evgenijk on 05.03.2021.
//

#include "SnowBall.h"

SnowBall::SnowBall(const std::string &type,
                           const std::string &file,
                           Position position,
                           MovementDir dir,
                           Position start_corner ,
                           Position end_corner,
                   std::map<Position, Sprite *> *map)
        : MovingSprite(type, file, position, dir, start_corner, end_corner) {
    img_height = image.Height();
    img_width = image.Width();
    set_dir(dir);
    this->map = map;


    //std::cout << img_width << " " << img_height << "\n";
}
