//
// Created by evgenijk on 27.02.2021.
//

#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const std::string &type,
               const std::string &file,
               Position position,
               LAYER layer,
               Position start_corner ,
               Position end_corner)
        : type(type), image(file, start_corner, end_corner), pos(position), draw_layer(layer), start_corner(start_corner), end_corner(end_corner) {
    img_height = image.Height();
    img_width = image.Width();
    //std::cout << img_width << " " << img_height << "\n";
}

void Sprite::draw(Image &screen) {
    for (int y = pos.y; y < pos.y + img_height; y++) {
        for (int x = pos.x; x < pos.x + img_width; x++) {
            Pixel tmp{};
            switch (side) {
                case ROTATE_LEFT: {
                    tmp = image.GetPixel(x - pos.x, y - pos.y);
                    break;
                }
                case ROTATE_DOWN_AND_CAPTURE: {
                    tmp = image.GetPixel(y - pos.y, x - pos.x);
                    break;
                }
                case NORMAL: {
                    tmp = image.GetPixel(x - pos.x, img_height - (y - pos.y) - 1);
                    break;
                }
                case CAPTURE: {
                    tmp = image.GetPixel(img_height - (y - pos.y) - 1, img_width - (x - pos.x) - 1);
                    break;
                }
            }
            screen.PutPixel(x, y, tmp);
        }
    }
}
