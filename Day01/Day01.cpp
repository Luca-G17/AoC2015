#include <iostream>
#include <utility>
#include <fstream>

using namespace std;

string readFile(string filename) {
    string txt;
    ifstream file(filename);
    if (file.is_open()) {
        file >> txt;
    }
    return txt;
}

int countFloor(string instructions) {
    int floor = 0;
    for (auto ch : instructions) {
        if (ch == '(') {
            floor++;
        }
        else if (ch == ')') {
            floor--;
        }
    }
    return floor;
}

int findBasementIndex(string instructions) {
    int floor = 0;
    for (int i = 0; i < instructions.size(); i++) {
        if (instructions[i] == '(') {
            floor++;
        }
        else if (instructions[i] == ')') {
            floor--;
        }
        if (floor < 0)
            return i + 1;
    }
    return -1;
}

int main() {
    cout << "The instructions lead santa to floor " + to_string(countFloor(readFile("input.txt"))) << endl;
    cout << "The first time santa enters the basement is at instruction number " + to_string(findBasementIndex(readFile("input.txt"))) << endl;
    return 0;
}

