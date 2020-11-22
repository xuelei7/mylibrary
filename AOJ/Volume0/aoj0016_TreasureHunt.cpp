// Treasure Hunt

//  "go ahead a number of steps equivalent to the first integer, and turn clockwise by degrees equivalent to the second integer"

//  His grand mother says that Sanbonmatsu was standing at the center of town. However, now buildings are crammed side by side and people can not walk along exactly what the paper says in. Your task is to write a program which hunts for the treature on the paper.

// For simplicity, 1 step is equivalent to 1 meter. Input consists of several pairs of two integers d (the first integer) and t (the second integer) separated by a comma. Input ends with "0, 0". Your program should print the coordinate (x, y) of the end point. There is the treature where x meters to the east and y meters to the north from the center of town.

// You can assume that d ≤ 100 and -180 ≤ t ≤ 180.

// Input
// A sequence of pairs of integers d and t which end with "0,0".

// Output
// Print the integer portion of x and y in a line respectively.

#include <bits/stdc++.h>
using namespace std;

vector<int> split_string(string s, char c) {
    vector<int> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
            left_side = i + 1;
        }
        if (i == s.size() - 1) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i+1-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
        }
    }
    return v;
}

int main() {
    string s;
    double x = 0, y = 0;
    double d = acos(-1) / 2;
    while (cin >> s) {
        vector<int> v = split_string(s, ',');
        if (v[0] == 0 && v[1] == 0) break;
        x += v[0] * cos(d);
        y += v[0] * sin(d);
        d -= acos(-1) * v[1] / 180;
    }
    cout << (int)x << endl;
    cout << (int)y << endl;
    return 0;
}