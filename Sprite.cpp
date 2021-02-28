//
// Created by evgenijk on 27.02.2021.
//

#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const std::string &type, const std::string &file, Position position, LAYER layer) : image(file),
                                                                                                   pos(position),
                                                                                                   draw_layer(layer),
                                                                                                   type(type) {
    img_height = image.Height();
    img_width = image.Width();
    //std::cout << img_width << " " << img_height << "\n";
}

void Sprite::draw(Image &screen) {
    for (int i = pos.y; i < pos.y + img_height; i++) {
        for (int j = pos.x; j < pos.x + img_width; j++) {
            Pixel tmp = image.GetPixel(j - pos.x, i - pos.y);
            screen.PutPixel(i, j, tmp);
        }
    }
}