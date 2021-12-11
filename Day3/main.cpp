#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

istream &operator>>(istream &str, vector<int> &data) {
    data = vector<int>();
    string line;
    if (getline(str, line)) {
        for (char const &c : line){
            data.push_back(c - '0');
        }
    }
    return str;
}

vector<int> extract_column(vector<vector<int>> binary_matrix, int column_index){
    vector<int> tmp;
    for(auto &it : binary_matrix){
        tmp.push_back(it[column_index]);
    }
    return tmp;
}

int main() {
    // Input Parsing
    ifstream read("input.txt");
    vector<vector<int>> binary_matrix;
    vector<int> tmp;

    while (read >> tmp){
        binary_matrix.push_back(tmp);
    }
    int rows = binary_matrix.size();
    int columns = binary_matrix[0].size();

    cout << "The binary input has " << rows << " rows." << endl;
    cout << "The binary input has " << columns << " columns." << endl;

    // Part 1
    int gamma_rate = 0;

    for (int i = 0; i < columns; i++){
        vector<int> column = extract_column(binary_matrix, i);
        if(accumulate(column.begin(), column.end(), 0) >= rows/2){gamma_rate+=pow(2,columns-i-1);}
    }

    int epsilon_rate = pow(2, columns) - 1 - gamma_rate;

    cout << gamma_rate << endl;
    cout << epsilon_rate << endl;

    cout << "The solution is: " << gamma_rate * epsilon_rate << endl;

    // Part 2
    vector<vector<int>> binary_matrix_oxygen(binary_matrix);
    int ox_gen_rating = 0;
    for (int i = 0; i < columns; i++){
        int rows_ox = binary_matrix_oxygen.size();
        if (rows_ox == 1) {break;}
        vector<vector<int>> binary_matrix_oxygen_tmp = vector<vector<int>>();
        vector<int> column = extract_column(binary_matrix_oxygen, i);
        if(accumulate(column.begin(), column.end(), 0) > (double)rows_ox/2.0 ||  ((accumulate(column.begin(), column.end(), 0) == rows_ox/2 ) && (rows_ox%2 == 0))){
            for(int j = 0; j < rows_ox; j++){
                if(binary_matrix_oxygen[j][i] == 1) {binary_matrix_oxygen_tmp.push_back(binary_matrix_oxygen[j]);}
            }
        }
        else{
            for(int j = 0; j < rows_ox; j++) {
                if (binary_matrix_oxygen[j][i] == 0) { binary_matrix_oxygen_tmp.push_back(binary_matrix_oxygen[j]); }
            }
        }
        binary_matrix_oxygen = binary_matrix_oxygen_tmp;
    }

    cout << "number of rows left in oxygen: " << binary_matrix_oxygen.size() << endl;
    for(int i = 0; i < columns; i++){
        if(binary_matrix_oxygen[0][i]){
            ox_gen_rating += pow(2,columns-i-1);
        }

    }
    cout << endl;

    cout << "oxygen rating: " << ox_gen_rating << endl;

    vector<vector<int>> binary_matrix_co2(binary_matrix);
    int co2_scrub_rating = 0;
    for (int i = 0; i < columns; i++){
        int rows_co2 = binary_matrix_co2.size();
        if (rows_co2 == 1) {break;}
        vector<vector<int>> binary_matrix_co2_tmp = vector<vector<int>>();
        vector<int> column = extract_column(binary_matrix_co2, i);
        if(accumulate(column.begin(), column.end(), 0) > (double)rows_co2/2.0 ||  ((accumulate(column.begin(), column.end(), 0) == rows_co2/2 ) && (rows_co2%2 == 0))){
            for(int j = 0; j < rows_co2; j++){
                if(binary_matrix_co2[j][i] == 0) {binary_matrix_co2_tmp.push_back(binary_matrix_co2[j]);}
            }
        }
        else{
            for(int j = 0; j < rows_co2; j++) {
                if (binary_matrix_co2[j][i] == 1) { binary_matrix_co2_tmp.push_back(binary_matrix_co2[j]); }
            }
        }
        binary_matrix_co2 = binary_matrix_co2_tmp;
    }

    cout << "number of rows left in co2: " << binary_matrix_co2.size() << endl;
    for(int i = 0; i < columns; i++){
        if(binary_matrix_co2[0][i]){
            co2_scrub_rating += pow(2 ,columns-i-1);
        }
    }
    cout << endl;

    cout << "co2 rating: " << co2_scrub_rating << endl;
    cout << "Part 2 Solution: " << co2_scrub_rating * ox_gen_rating << endl;

    return 0;
}
