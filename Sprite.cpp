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
        : image(file, start_corner, end_corner), pos(position), draw_layer(layer), start_corner(start_corner), end_corner(end_corner) {
    img_height = image.Height();
    img_width = image.Width();
    //std::cout << img_width << " " << img_height << "\n";
}

void Sprite::draw(Image &screen) {
    for (int i = pos.y; i < pos.y + img_height; i++) {
        for (int j = pos.x; j < pos.x + img_width; j++) {
            Pixel tmp{};
            switch (side) {
                case DOWN: {
                    tmp = image.GetPixel(j - pos.x, i - pos.y);
                    break;
                }
                case LEFT: {
                    tmp = image.GetPixel(i - pos.y, j - pos.x);
                    break;
                }
                case UP: {
                    tmp = image.GetPixel(i - pos.y, img_width - (j - pos.x) - 1);
                    break;
                }
                case RIGHT: {
                    tmp = image.GetPixel(img_height - (i - pos.y) - 1, img_width - (j - pos.x) - 1);
                    break;
                }
            }
            screen.PutPixel(i, j, tmp);
        }
    }
}
