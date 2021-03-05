#include "Player.h"
#include <iostream>

bool Player::Moved() const {
    if (coords.x == old_coords.x && coords.y == old_coords.y)
        return false;
    else
        return true;
}

void Player::ProcessInput(MovementDir dir) {

    int move_dist = move_speed * 1;
    auto iter = map->end();
    std::string name{"ground"};

    iter = map->find({coords.x / tileSize, (coords.y ) / tileSize });
    if (iter == map->end()) {
        std::cout << "Map Error\n";
        return;
    }
    name = iter->second;
    std::cout << name << " " << iter->first.x << ":" << iter->first.y << "\n";

    switch (dir) {
        case MovementDir::UP:
            iter = map->find({coords.x / tileSize, (coords.y + move_dist) / tileSize });
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second;
            //std::cout << name << " " << iter->first.x << ":" << iter->first.y << "\n";
            if (true) {
                old_coords.y = coords.y;
                coords.y += move_dist;
            }
            break;
        case MovementDir::DOWN:
            old_coords.y = coords.y;
            coords.y -= move_dist;
            break;
        case MovementDir::LEFT:
            old_coords.x = coords.x;
            coords.x -= move_dist;
            break;
        case MovementDir::RIGHT:
            old_coords.x = coords.x;
            coords.x += move_dist;
            break;
        default:
            break;
    }
}

void Player::Draw(Image &screen) {
    if (Moved()) {
        for (int y = old_coords.y; y <= old_coords.y + tileSize; ++y) {
            for (int x = old_coords.x; x <= old_coords.x + tileSize; ++x) {
                screen.PutPixel(x, y, backgroundColor);
            }
        }
        old_coords = coords;
    }

    for (int y = coords.y; y <= coords.y + tileSize; ++y) {
        for (int x = coords.x; x <= coords.x + tileSize; ++x) {
            screen.PutPixel(x, y, color);
        }
    }
}

