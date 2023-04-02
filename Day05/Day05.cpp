#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

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

bool stringContains(string str1, string str2) {
    return str1.find(str2) != string::npos;
}

bool stringHas3Vowels(string str) {
    vector<char> vowels{ 'a', 'e', 'i', 'o', 'u' };
    int count = 0;
    for (auto c : str) {
        if (find(vowels.begin(), vowels.end(), c) != vowels.end()) {
            count++;
        }
        if (count == 3) {
            return true;
        }
    }
    return false;
}

bool stringContainsALetterOccuringTwiceInARow(string str) {
    char prevC = ']';
    for (auto c : str) {
        if (c == prevC) {
            return true;
        }
        prevC = c;
    }
    return false;
}

bool stringDoesNotContainsNaughtyString(string str) {
    vector<string> naughtyStrings{ "ab", "cd", "pq", "xy" };
    for (auto naughty : naughtyStrings) {
        if (stringContains(str, naughty)) {
            return false;
        }
    }
    return true;
}

bool stringIsNice(string str) {
    if (stringDoesNotContainsNaughtyString(str)) {
        if (stringHas3Vowels(str) && stringContainsALetterOccuringTwiceInARow(str)) {
            return true;
        }
    }
    return false;
}

bool stringContainsPairSeperatedByASingleChar(string str) {
    char before;
    char after;

    for (int i = 1; i < str.size() - 1; i++) {
        before = str[i - 1];
        after = str[i + 1];
        if (before == after) {
            return true;
        }
    }
    return false;
}

bool stringContainsTwoPairsWithoutOverlap(string str) {
    for (int i = 0; i < str.size() - 1; i++) {
        string pair = str.substr(i, 2);
        string removedPairStr = str;
        removedPairStr.erase(i);
        removedPairStr.erase(i);
        if (stringContains(removedPairStr, pair)) {
            return true;
        }
    }
    return false;
}

bool stringIsNicePart2(string str) {
    return stringContainsPairSeperatedByASingleChar(str) && stringContainsTwoPairsWithoutOverlap(str);
}

pair<int, int> countNiceStrings(vector<string> strs) {
    int count = 0;
    int count2 = 0;
    for (string str : strs) {
        if (stringIsNice(str)) {
            count++;
        }
        if (stringIsNicePart2(str)) {
            count2++;
        }
    }
    return pair<int, int> { count, count2 };
}

int main() {
    vector<string> strs = readlines("input.txt");
    //vector<string> strs{ "qjhvhtzxzqqjkmpb", "jchzalrnumimnmhp"};
    pair<int, int> counts = countNiceStrings(strs);
    cout << "Number of nice strings (Part 1) = " + to_string(counts.first) << endl;
    cout << "Number of nice strings (Part 2) = " + to_string(counts.second) << endl;

}
