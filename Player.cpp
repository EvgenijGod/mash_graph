#include "Player.h"
#include <iostream>

bool Player::Moved() const {
    if (coords.x == old_coords.x && coords.y == old_coords.y)
        return false;
    else
        return true;
}

void Player::ProcessInput(MovementDir dir) {
    //std::cout << coords.x << " " << coords.y << "\n";
    int move_dist = move_speed * 0.5;
    auto iter = map->end();
    std::string name{"ground"};
    const int bias = tileSize / 3 * 2;
    switch (dir) {
        case MovementDir::UP:
            iter = map->find({coords.x / tileSize, (coords.y + move_dist + bias ) / tileSize });
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.y = coords.y;
                coords.y += move_dist;
                //cur_state = MovementDir::UP;
            }
            break;
        case MovementDir::DOWN:
            iter = map->find({coords.x / tileSize, (coords.y - move_dist) / tileSize });
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.y = coords.y;
                coords.y -= move_dist;
                //cur_state = MovementDir::DOWN;
            }
            break;
        case MovementDir::LEFT:
            iter = map->find({(coords.x - move_dist) / tileSize, coords.y / tileSize });
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.x = coords.x;
                coords.x -= move_dist;
                //cur_state = MovementDir::LEFT;
            }
            break;
        case MovementDir::RIGHT:
            iter = map->find({(coords.x + move_dist + bias) / tileSize, coords.y / tileSize });
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.x = coords.x;
                coords.x += move_dist;
                //cur_state = MovementDir::RIGHT;
            }
            break;
        default:
            break;
    }
    if (Moved()) {
        player_sprite.set_dir(dir);
        player_sprite.set_position(coords);
    }
}

void Player::Draw(Image &screen) {

    player_sprite.draw(screen);


//    if (Moved()) {
//        for (int y = old_coords.y; y <= old_coords.y + tileSize; ++y) {
//            for (int x = old_coords.x; x <= old_coords.x + tileSize; ++x) {
//                screen.PutPixel(x, y, backgroundColor);
//            }
//        }
//        old_coords = coords;
//    }
//
//    for (int y = coords.y; y <= coords.y + tileSize; ++y) {
//        for (int x = coords.x; x <= coords.x + tileSize; ++x) {
//            screen.PutPixel(x, y, color);
//        }
//    }
}

