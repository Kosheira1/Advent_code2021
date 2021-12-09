#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include <algorithm>// for std::copy

using namespace std;

//#include <boost/network/protocol/http/client.hpp>
#include <iostream>
#include <string>

struct Command {
    string direction;
    string magnitude;

    friend istream &operator>>(istream &str, Command &data) {
        string line;
        Command tmp;
        if (getline(str, line)) {
            std::stringstream iss(line);
            if (std::getline(iss, tmp.direction, ' ') &&
                std::getline(iss, tmp.magnitude, ' ')) {
                data.swap(tmp);
            } else {
                // One operation failed
                // So set the state on the main stream
                // to indicate failure.
                str.setstate(std::ios::failbit);
            }
        }
        return str;
    }
    void swap(Command &other)// C++03 as this answer was written a long time ago.
    {
        direction = other.direction;
        magnitude = other.magnitude;
    }
};

enum string_code {
    c_forward,
    c_up,
    c_down,
    c_unknown
};

string_code hashit (string const& inString) {
    if(inString == "forward") return c_forward;
    if(inString == "up") return c_up;
    if(inString == "down") return c_down;
    return c_unknown;
}

void move(Command command, int &hoz_pos, int &depth){
    switch(hashit(command.direction)) {
        case c_forward:
            hoz_pos += stoi(command.magnitude);
            break;
        case c_up:
            depth -= stoi(command.magnitude);
            break;
        case c_down:
            depth += stoi(command.magnitude);
            break;
        default :
            cout << "Invalid Command" << endl;
    }
}

void move_aimed(Command command, int &hoz_pos, int &depth, int &aim){
    switch(hashit(command.direction)) {
        case c_forward:
            hoz_pos += stoi(command.magnitude);
            depth += aim*stoi(command.magnitude);
            break;
        case c_up:
            aim -= stoi(command.magnitude);
            break;
        case c_down:
            aim += stoi(command.magnitude);
            break;
        default:
            cout << "Invalid Command" << endl;
    }
}

int main() {
    ifstream read("input.txt");
    istream_iterator<Command> start(read), end;
    vector<Command> commands(start, end);

    int depth = 0, hoz_pos = 0, aim = 0;

    for(auto &it : commands) {
       move(it, hoz_pos, depth);
    }

    cout << "The solution is: " << hoz_pos*depth << endl;

    hoz_pos = 0;
    depth = 0;
    for(auto &it : commands) {
        move_aimed(it, hoz_pos, depth, aim);
    }

    cout << "The aimed solution is: " << hoz_pos*depth << endl;
    read.close();
    return 0;
}
