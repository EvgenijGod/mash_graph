#include "Player.h"
#include <iostream>


Player::Player(Position pos, int tileSize, std::map<Position, Sprite *> *map,
               int &floor_complete) :
        player_sprite{"player",
                      "../resources/player.png",
                      pos,
                      MovementDir::DOWN,
                      {0, 0},
                      {16, 16}},
        coords(pos),
        old_coords(coords),
        tileSize(tileSize),
        floor_complete{floor_complete} {
    default_coords = coords;
    this->map = map;
    _lives.emplace_back(new Sprite("hp_bar",
                                   "../resources/hp_bar1.png",
                                   {PLAY_WINDOW_WIDTH, WINDOW_HEIGHT - 100},
                                   LAYER::FRONT_LAYER,
                                   Position{0, 0},
                                   Position{0, 0}));
    if (HP_LVL > 5) {
        HP_LVL = 5;
    }
    for (int i = 0; i < HP_LVL; i++) {
        _lives.emplace_back(new Sprite("hp_heart",
                                       "../resources/heart1.png",
                                       {PLAY_WINDOW_WIDTH, WINDOW_HEIGHT - 250 - i * tileSize * 10},
                                       LAYER::FRONT_LAYER,
                                       Position{0, 0},
                                       Position{0, 0}));
    }
};


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
            iter = map->find({coords.x / tileSize, (coords.y + move_dist + bias) / tileSize});
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.y = coords.y;
                coords.y += move_dist;
            }
            cur_state = MovementDir::UP;
            break;
        case MovementDir::DOWN:
            iter = map->find({coords.x / tileSize, (coords.y - move_dist) / tileSize});
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.y = coords.y;
                coords.y -= move_dist;
            }
            cur_state = MovementDir::DOWN;
            break;
        case MovementDir::LEFT:
            iter = map->find({(coords.x - move_dist) / tileSize, coords.y / tileSize});
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.x = coords.x;
                coords.x -= move_dist;
            }
            cur_state = MovementDir::LEFT;
            break;
        case MovementDir::RIGHT:
            iter = map->find({(coords.x + move_dist + bias) / tileSize, coords.y / tileSize});
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "ground" || name == "empty" || name == "exit") {
                old_coords.x = coords.x;
                coords.x += move_dist;
            }
            cur_state = MovementDir::RIGHT;
            break;
        default:
            break;
    }
    if (name == "exit") {
        floor_complete += 1;
    }
    if (Moved()) {
        player_sprite.set_dir(dir);
        player_sprite.set_position(coords);
        bool tmp = false;
        iter = map->find({(coords.x + move_dist + bias) / tileSize, (coords.y + move_dist + bias) / tileSize});
        if (iter == map->end()) {
            std::cout << "Map Error\n";
            return;
        }
        name = iter->second->get_type();
        if (name == "empty") {
            tmp = true;
        }
        if (tmp == false) {
            iter = map->find({(coords.x) / tileSize, (coords.y) / tileSize});
            if (iter == map->end()) {
                std::cout << "Map Error\n";
                return;
            }
            name = iter->second->get_type();
            if (name == "empty") {
                tmp = true;
            }
        }
        if (tmp) {
            damage();
        }
    }
}

void Player::Draw(Image &screen) {
    if (hit_freeze > 0)
        hit_freeze -= 1;
    player_sprite.draw(screen);

    for (auto it : _lives) {
        it->draw(screen);
    }

    for (auto it : _balls) {
        it->draw(screen);
    }

    while (!_balls.empty() && !_balls[0]->is_alive()) {
        delete _balls[0];
        _balls.pop_front();
    }

    if (make_damage_effect != 0) {
        for (int x = 0; x < PLAY_WINDOW_WIDTH; ++x) {
            for (int y = 0; y < PLAY_WINDOW_HEIGHT; ++y) {
                auto pix = screen.GetPixel_full(x, y);
                pix.r = make_damage_effect;
                screen.PutPixel(x, y, pix);
            }
        }
        make_damage_effect -= 10;
        if (make_damage_effect < 0) {
            make_damage_effect = 0;
        }
    }



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

void Player::damage(){
    if (HP_LVL >= 1) {
        //std::cout << "DAMAGED " << HP_LVL << "\n";
        _lives[HP_LVL]->draw_normal = false;
        //std::cout
        make_damage_effect = 250;
        player_sprite.set_position(default_coords);
        player_sprite.set_dir(MovementDir::DOWN);
        coords = default_coords;
        old_coords = default_coords;
        HP_LVL -= 1;
    }
}

bool Player::is_alive() {
    return (HP_LVL >= 1);
}

void Player::throw_snowball() {
    if (hit_freeze == 0) {
        _balls.emplace_back(new SnowBall("snowball",
                                         "../resources/snowball_sprite.png",
                                         coords,
                                         cur_state,
                                         Position{0, 0},
                                         Position{16, 16},
                                         map));
        hit_freeze = 10;
    }
}

