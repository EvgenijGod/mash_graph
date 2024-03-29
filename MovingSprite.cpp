//
// Created by evgenijk on 27.02.2021.
//

#include "MovingSprite.h"
#include <iostream>
#include <climits>

MovingSprite::MovingSprite(const std::string &type,
               const std::string &file,
               Position position,
               MovementDir dir,
               Position start_corner ,
               Position end_corner)
        : type(type), image(file, start_corner, end_corner), pos(position), dir(dir), start_corner(start_corner), end_corner(end_corner) {
    img_height = image.Height();
    img_width = image.Width();

    //std::cout << img_width << " " << img_height << "\n";
}

void MovingSprite::draw(Image &screen) {
    if (draw_normal == false) {
        need_draw = false;
    }
    if (need_draw) {
        for (int y = pos.y; y < pos.y + img_height; y++) {
            for (int x = pos.x; x < pos.x + img_width; x++) {
                Pixel tmp{};
                switch (side) {
                    case DOWN: {
                        tmp = image.GetPixel_part(x - pos.x, y - pos.y);
                        break;
                    }
                    case LEFT: {
                        tmp = image.GetPixel_part(y - pos.y, x - pos.x);
                        break;
                    }
                    case NORMAL: {
                        tmp = image.GetPixel_part(x - pos.x, img_height - (y - pos.y) - 1);
                        break;
                    }
                    case RIGHT: {
                        tmp = image.GetPixel_part(img_height - (y - pos.y) - 1, img_width - (x - pos.x) - 1);
                        break;
                    }
                    case SNOWBALL_RIGHT: {
                        tmp = image.GetPixel_part(img_width - (x - pos.x) - 1, y - pos.y);
                        break;
                    }
                }
                if (draw_normal) {
                    if (Pixel{0, 0, 0, 0} != tmp)
                        screen.PutPixel(x, y, tmp);
                } else {
                    // draw black
                    screen.PutPixel(x, y, Pixel{0, 0, 0, 0});
                }
            }
        }
        draw_animation(screen);
    }
}

void MovingSprite::draw_animation(Image &screen) {
    if (type == "player" && animating) {
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
        animating = false;
    }
}

void MovingSprite::set_dir(const MovementDir new_dir) {
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


