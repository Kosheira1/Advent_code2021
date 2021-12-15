//
// Created by dleonard on 15.12.21.
//

#ifndef DAY4_SQUID_BINGO_GAME_H
#define DAY4_SQUID_BINGO_GAME_H

#include <iostream>
#include <fstream>
#include "Board.h"
#include <string>
#include <vector>

class squid_bingo_game{
private:
    std::vector<Board> boards;
    std::vector<int> call_numbers;
public:
    squid_bingo_game(std::string);
    friend std::istream& operator>>(std::istream& str, squid_bingo_game& setup)
    {
        return str;
    }
};

squid_bingo_game::squid_bingo_game(std::string input) {
    std::ifstream read(input);
    read>>*this;
}
#endif//DAY4_SQUID_BINGO_GAME_H
