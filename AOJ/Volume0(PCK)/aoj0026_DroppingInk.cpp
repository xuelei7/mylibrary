// Dropping Ink
// As shown in the following figure, there is a paper consisting of a grid structure where each cell is indicated by (x, y) coordinate system.

// We are going to put drops of ink on the paper. A drop comes in three different sizes: Large, Medium, and Small. From the point of fall, the ink sinks into surrounding cells as shown in the figure depending on its size. In the figure, a star denotes the point of fall and a circle denotes the surrounding cells.

// Originally, the paper is white that means for each cell the value of density is 0. The value of density is increased by 1 when the ink sinks into the corresponding cells. For example, if we put a drop of Small ink at (1, 2) and a drop of Medium ink at (3, 2), the ink will sink as shown in the following figure (left side):

// In the figure, density values of empty cells are 0. The ink sinking into out of the paper should be ignored as shown in the figure (top side). We can put several drops of ink at the same point.

// Your task is to write a program which reads a sequence of points of fall (x, y) with its size (Small = 1, Medium = 2, Large = 3), and prints the number of cells whose density value is 0. The program must also print the maximum value of density.

// You may assume that the paper always consists of 10 × 10, and 0 ≤ x < 10, 0 ≤ y < 10.

// Input
// x1,y1,s1
// x2,y2,s2
//   :
//   :
// (xi, yi) represents the position of the i-th drop and si denotes its size. The number of drops is less than or equal to 50.

// Output
// Print the number of cells whose density value is 0 in first line.
// Print the maximum value of density in the second line.

#include <bits/stdc++.h>
using namespace std;

// from string
// split string s by character c and return all the integer elements
vector<int> split_string_to_int(string s, char c) {
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
int main () {
    string s;
    int mp[10][10] = {};
    int dx[13] = {0,1,-1,0,0,-1,-1,1,1,0,0,2,-2};
    int dy[13] = {0,0,0,1,-1,1,-1,1,-1,2,-2,0,0};
    int num[3] = {5,9,13};
    while (cin >> s) {
        vector<int> v = split_string_to_int(s,',');
        int x = v[0], y = v[1];
        for (int i = 0; i < num[v[2]-1]; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx < 10 && ty >= 0 && ty < 10) mp[tx][ty]++;
        }
    }
    int cnt0 = 0, mx = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (mp[i][j] == 0) cnt0++;
            mx = max(mx,mp[i][j]);
        }
    }
    cout << cnt0 << "\n" << mx << "\n";
    return 0;
}