// Problem A. GuruGuru
// You are playing a game called Guru Guru Gururin. In this game, you can move with the vehicle called Gururin. There are two commands you can give to Gururin: 'R' and 'L'. When 'R' is sent, Gururin rotates clockwise by 90 degrees. Otherwise, when 'L' is sent, Gururin rotates counterclockwise by 90 degrees.

// During the game, you noticed that Gururin obtains magical power by performing special commands. In short, Gururin obtains magical power every time when it performs one round in the clockwise direction from north to north. In more detail, the conditions under which magical power can be obtained is as follows.

// At the beginning of the special commands, Gururin faces north.
// At the end of special commands, Gururin faces north.
// Except for the beginning and the end of special commands, Gururin does not face north.
// During the special commands, Gururin faces north, east, south, and west one or more times, respectively, after the command of 'R'.
// At the beginning of the game, Gururin faces north. For example, if the sequence of commands Gururin received in order is 'RRRR' or 'RRLRRLRR', Gururin can obtain magical power. Otherwise, if the sequence of commands is 'LLLL' or 'RLLR', Gururin cannot obtain magical power.

// Your task is to calculate how many times Gururin obtained magical power throughout the game. In other words, given the sequence of the commands Gururin received, calculate how many special commands exists in it.

// Input
// The input consists of a single test case in the format below.

// S
// The first line consists of a string S, which represents the sequence of commands Gururin received. S consists of 'L' and 'R'. The length of S is between 1 and 103 inclusive.

// Output
// Print the number of times Gururin obtained magical power throughout the game in one line.

#include <bits/stdc++.h>
using namespace std;

string s;

bool ok(int f, int t) {
    bool d[4] = {};
    int a = 0;
    for (int i = f; i < t; i++) {
        if (s[i] == 'R') a++;
        else a--;
        a = (a + 4) % 4;
        if (s[i] == 'R')
            d[a%4] = 1;
    }
    return d[0] && d[1] && d[2] && d[3];
}

int main() {
    cin >> s;
    int a = 0, bf = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') a++;
        else a--;
        a = (a + 4) % 4;
        if (a == 0) {
            ans += ok(bf,i+1);
            bf = i+1;
        }
    }
    cout << ans << endl;
}