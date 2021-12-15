//
// Created by dleonard on 15.12.21.
//

#ifndef DAY4_BOARD_H
#define DAY4_BOARD_H
#include <vector>

class Board{
private:
    int rows;
    int columns;
    std::vector<std::vector<int>> data;
    std::vector<std::vector<int>> call_mask;
public:
    Board(int, int, std::vector<std::vector<int>>);
    bool check_win();
    void process_input(int);
    std::vector<int> extract_column(int);
    std::vector<int> extract_row(int);
};
#endif//DAY4_BOARD_H
