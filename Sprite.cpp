//
// Created by evgenijk on 27.02.2021.
//

#include "Sprite.h"

Sprite::Sprite(const std::string &type, const std::string &file, Position position, LAYER layer) : image(file),
                                                                                                   pos(position),
                                                                                                   draw_layer(layer),
                                                                                                   type(type) {
    img_height = image.Height();
    img_width = image.Width();
}

void Sprite::draw(Image &screen) {
    for (int i = pos.y; i < pos.y + img_height; i++) {
        for (int j = pos.x; j < pos.x + img_width; j++) {
            Pixel tmp = image.GetPixel(i, j);
            screen.PutPixel(i, j, tmp);
        }
    }
}