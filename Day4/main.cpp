#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;
class Board{
private:
    int rows;
    int columns;
    vector<vector<int>> data;
    vector<vector<int>> call_mask;
public:
    Board(int, int, vector<vector<int>>);
    bool check_win();
    void process_input(int);
    vector<int> extract_column;
    vector<int> extract_row;
};

class squid_bingo_game{
private:
    vector<Board> boards;

    friend istream& operator>>(istream& str, squid_bingo_game& setup)
    {
        return str;
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
