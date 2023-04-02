#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

vector<string> readlines(string filename) {
    vector<string> v;
    string line;
    ifstream file(filename);
    while (getline(file, line)) {
        v.push_back(line);
    }
    return v;
}

vector<string> splitString(string s, char delimiter) {
    std::stringstream stream(s);
    string segment;
    vector<string> v;
    while (getline(stream, segment, delimiter)) {
        v.push_back(segment);
    }
    return v;
}


//LxWxH
//2*L*W + 2*W*H + 2*H*L
int areaRequiredForPresent(vector<int> dimensions) {
    int l = dimensions.at(0);
    int w = dimensions.at(1);
    int h = dimensions.at(2);
    int s1 = l * w;
    int s2 = w * h;
    int s3 = h * l;
    int minS = fmin(s1, s2);
    minS = fmin(minS, s3);
    return (2 * (s1 + s2 + s3)) + minS;
}

int ribbonRequiredForPresent(vector<int> dimensions) {
    int l = dimensions.at(0);
    int w = dimensions.at(1);
    int h = dimensions.at(2);
    int s1 = 2 * (l + w);
    int s2 = 2 * (w + h);
    int s3 = 2 * (h + l);
    int minS = fmin(s1, s2);
    minS = fmin(minS, s3);
    return minS + (l * w * h);
}

pair<int, int> sumAreas(vector<string> presents) {
    int sumArea = 0;
    int sumRibbon = 0;
    for (string present : presents) {
        vector<string> dimensionsStr = splitString(present, 'x');
        vector<int> dimensions { 
            stoi(dimensionsStr.at(0)),
            stoi(dimensionsStr.at(1)),
            stoi(dimensionsStr.at(2))
        };
        sumArea += areaRequiredForPresent(dimensions);
        sumRibbon += ribbonRequiredForPresent(dimensions);
    }
    return pair<int, int> { sumArea, sumRibbon };
}

int main() {
    vector<string> presents = readlines("input.txt");
    pair<int, int> materialsRequired = sumAreas(presents);
    cout << "Total area of wrapping paper required " + to_string(materialsRequired.first) << endl;
    cout << "Total length of ribbon required " + to_string(materialsRequired.second) << endl;

    return 0;
}