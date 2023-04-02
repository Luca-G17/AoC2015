#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

string readFile(string filename) {
    string txt;
    ifstream file(filename);
    if (file.is_open()) {
        file >> txt;
    }
    return txt;
}
pair<int, int> computeNewPosition(pair<int, int> p, char i) {
    switch (i) {
        case '^': 
            p.second -= 1;
            break;
        case 'v':
            p.second += 1;
            break;
        case '<':
            p.first -= 1;
            break;
        case '>':
            p.first += 1;
            break;
    }
    return p;
}

int allhousesVisitedBySantaAndRoboSanta(string instructions) {
    pair<int, int> robo{0, 0};
    pair<int, int> santa{0, 0};
    set<pair<int, int>> locs { robo };
    bool santasTurn = true;
    for (auto i : instructions) {
        if (santasTurn) {
            santa = computeNewPosition(santa, i);
            locs.insert(santa);
            santasTurn = false;
        } else {
            robo = computeNewPosition(robo, i);
            locs.insert(robo);
            santasTurn = true;
        }
    }
    return locs.size();
}
int allHousesVisitedBySanta(string instructions) {
    pair<int, int> loc{0, 0};
    set<pair<int, int>> locs{ loc };
    for (auto i : instructions) {
        loc = computeNewPosition(loc, i);
        locs.insert(loc);
    }
    return locs.size();
}

int main() {
    cout << "Total houses visited by santa " + to_string(allHousesVisitedBySanta(readFile("input.txt"))) << endl;
    cout << "Total houses visited by santa and robosanta " + to_string(allhousesVisitedBySantaAndRoboSanta(readFile("input.txt"))) << endl;
}