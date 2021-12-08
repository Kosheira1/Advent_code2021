//
// Created by dleonard on 08.12.21.
//
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <algorithm> // for std::copy

using namespace std;

//#include <boost/network/protocol/http/client.hpp>
#include <string>
#include <iostream>

int main() {

  ifstream is("input.txt");
  istream_iterator<int> start(is), end;
  vector<int> numbers(start, end);
  int counter = 0;
  for(vector<int>::size_type i = 1; i != numbers.size(); ++i){
    if(numbers[i] > numbers[i-1]){counter++;}
  }
  cout << "The solution is: " << counter << endl;

  int sliding_window_a, sliding_window_b, window_counter = 0;
  for(vector<int>::size_type i = 3; i != numbers.size(); ++i){
    if(numbers[i] > numbers[i-3]){window_counter++;}
  }

  cout << "Solution for sliding window is: " << window_counter << endl;
  return 0;
}