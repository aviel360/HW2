#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <memory>
#include "../Auxiliaries.h"
#include "../Exceptions.h"
#include "../Character/Character.h"

namespace mtm{

enum Team { POWERLIFTERS, CROSSFITTERS };
enum CharacterType {SOLDIER, MEDIC, SNIPER};
typedef int units_t;

typedef std::vector<std::vector<std::shared_ptr<Character>>> Board;

class Exception :std::exception{};
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

    class Exception {}; 

    private:
    static void attackNow(Board board, const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
    static void clearCasualties(Board board);

    static bool isTheCellInTheBoard(const GridPoint& coordinates);
    static bool isTheCellOccupied(const GridPoint& coordinates);
    static bool isTypeValid(CharacterType type);
    static bool isTeamValid(Team team);
    static bool isHealthValid(units_t health);
    static bool isAmmoValid(units_t ammo);
    static bool isRangeValid(units_t range);
    static bool isPowerValid(units_t power);
    static bool isValidCharcterMovement(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
    static bool isAttackInRange(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
    static bool issStillEnoughAmmo(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
    static bool isCharacterAttackValid(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);




};


}
#endif