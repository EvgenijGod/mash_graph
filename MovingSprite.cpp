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
            if (tmp != Pixel{0, 0, 0, 0})
                screen.PutPixel(x, y, tmp);
        }
    }

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
