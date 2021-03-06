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

    void set_dir(const MovementDir new_dir) {
        dir = new_dir;
        switch (dir) {
            case MovementDir::UP: {
                side = RIGHT;
                break;
            }
            case MovementDir::DOWN: {
                side = LEFT;
                break;
            }
            case MovementDir::LEFT: {
                side = NORMAL;
                break;
            }
            case MovementDir::RIGHT: {
                //std::cout << "RIGHT_SET\n";
                side = SNOWBALL_RIGHT;
                break;
            }
        }
        animating = true;
    }

    void draw_animation(Image &screen) {
        if (type == "snowball" && animating) {
            //std::cout << "A\n";
            player_animation++;
            if (player_animation > step) {
                start_corner.x = (start_corner.x + tileSize) % (6 * tileSize);
                end_corner.x = end_corner.x % (6 * tileSize) + tileSize;

//            std::cout << start_corner.x << ":" << start_corner.y << " " << end_corner.x << ":" <<
//            end_corner.y << " " << image.Full_Width() << "\n";

                //std::cout << img_height << img_width << std::endl;
                image.CutPart(start_corner,end_corner);
                player_animation = 0;
            }
        }
        switch (dir) {
            case MovementDir::UP: {
                pos.y = pos.y + movement_speed;
                break;
            }
            case MovementDir::DOWN: {
                pos.y = pos.y - movement_speed;
                break;
            }
            case MovementDir::LEFT: {
                pos.x = pos.x - movement_speed;
                break;
            }
            case MovementDir::RIGHT: {
                pos.x = pos.x + movement_speed;
                break;
            }
        }

        auto iter = map->end();
        std::string name{"ground"};
        iter = map->find(Position{pos.x / tileSize, (pos.y) / tileSize});
        if (iter == map->end()) {
            std::cout << "Map Error\n";
            return;
        }
        name = iter->second->get_type();
        if (name == "break_able_wall" || (name != "ground" && name != "empty")) {
            need_draw = false;
            if (name == "break_able_wall") {
                iter->second->need_draw = false;
                iter->second->set_type("ground");
            }
        }
    }

    bool is_alive() const{
        return need_draw;
    }

private:
    std::map<Position, Sprite *> *map;
    int movement_speed = 4;
};


#endif //MAIN_SNOWBALL_H
