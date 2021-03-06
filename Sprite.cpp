//
// Created by evgenijk on 27.02.2021.
//

#include "Sprite.h"
#include <iostream>
#include <climits>

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
//    if (draw_normal == false) {
//        need_draw = false;
//    }
    if (need_draw) {
        for (int y = pos.y; y < pos.y + img_height; y++) {
            for (int x = pos.x; x < pos.x + img_width; x++) {
                Pixel tmp{};
                switch (side) {
                    case ROTATE_LEFT: {
                        tmp = image.GetPixel_part(x - pos.x, y - pos.y);
                        break;
                    }
                    case ROTATE_DOWN_AND_CAPTURE: {
                        tmp = image.GetPixel_part(y - pos.y, x - pos.x);
                        break;
                    }
                    case NORMAL: {
                        tmp = image.GetPixel_part(x - pos.x, img_height - (y - pos.y) - 1);
                        break;
                    }
                    case CAPTURE: {
                        tmp = image.GetPixel_part(img_height - (y - pos.y) - 1, img_width - (x - pos.x) - 1);
                        break;
                    }
                }
                if (draw_normal) {
                    if (Pixel{0, 0, 0, 0} != tmp)
                        screen.PutPixel(x, y, tmp);
                } else {
                    // draw black
                    need_draw = false;
                    screen.PutPixel(x, y, Pixel{0, 0, 0, 0});
                }
            }
        }

        if (type == "fire") {
            animation++;
            if (animation > step) {
                start_corner.x = (start_corner.x + tileSize) % (4 * tileSize);
                end_corner.x = end_corner.x % (4 * tileSize) + tileSize;
                //std::cout << start_corner.x << " " << end_corner.x << " " << image.Full_Width() << "\n";

                image.CutPart(start_corner,end_corner);
                animation = 0;
            }
            double radius = tileSize * 3 / 2;
            for (int x = pos.x - tileSize; x < pos.x + 2 * tileSize; x++) {
                for (int y = pos.y - tileSize; y < pos.y + 2 * tileSize; y++) {
                    double x_center = pos.x + 0.5 * tileSize, y_center = pos.y + 0.5 * tileSize;
                    double c = ((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center)) / (radius * radius);
                    if (c > 1.2) {
                        c = 0;
                    } else {
                        c = 1.2 - c;
                    }
                    auto pix = screen.GetPixel_full(x, y);
                    //std::cout << (int)pix.r << " " << c << " \n";
                    double coef = 120;
                    if (pix.r + c * coef < 255) {
                        pix.r += c * coef;
                    } else {
                        pix.r = 255;
                    }
                    screen.PutPixel(x, y, pix);
                }
            }

        }
    }

}