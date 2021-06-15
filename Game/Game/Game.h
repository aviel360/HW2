#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <memory>
#include "../Character/Character.h"



enum Team { POWERLIFTERS, CROSSFITTERS };
enum CharacterType {SOLDIER, MEDIC, SNIPER};
typedef int units_t;

typedef std::vector<std::vector<std::shared_ptr<Character>>> Board;

class Game {
    Board board;

    public:
    Game(int height, int width);
    ~Game();
    Game(const Game& other);
    Game& operator=(const Game& other);
    void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);
    virtual void move(const GridPoint& src_coordinates, const GridPoint& dst_coordinates);
    void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
    void reload(const GridPoint & coordinates);
    static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                units_t health, units_t ammo, units_t range, units_t power);

};

#endif