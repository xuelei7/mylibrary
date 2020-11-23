// Hit and Blow
// Let's play Hit and Blow game. A imagines four numbers and B guesses the numbers. After B picks out four numbers, A answers:

// The number of numbers which have the same place with numbers A imagined (Hit)
// The number of numbers included (but different place) in the numbers A imagined (Blow)
// For example, if A imagined numbers:

// 9 1 8 2

// and B chose:

// 4 1 5 9

// A should say 1 Hit and 1 Blow.

// Write a program which reads four numbers A imagined and four numbers B chose and prints the number of Hit and Blow respectively. You may assume that the four numbers are all different and within from 0 to 9.

// Input
// The input consists of multiple datasets. Each dataset set consists of:

// a1 a2 a3 a4
// b1 b2 b3 b4
// , where ai (0 ≤ ai ≤ 9) is i-th number A imagined and bi (0 ≤ bi ≤ 9) is i-th number B chose.

// The input ends with EOF. The number of datasets is less than or equal to 50.

// Output
// For each dataset, print the number of Hit and Blow in a line. These two numbers should be separated by a space.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a1,a2,b1,b2,c1,c2,d1,d2;
    while (cin >> a1 >> b1 >> c1 >> d1) {
        cin >> a2 >> b2 >> c2 >> d2;
        int a = 0, b = 0;
        if (a1 == a2) a++;
        if (b1 == b2) a++;
        if (c1 == c2) a++;
        if (d1 == d2) a++;
        if (a1 == b2 || a1 == c2 || a1 == d2) b++;
        if (b1 == a2 || b1 == c2 || b1 == d2) b++;
        if (c1 == a2 || c1 == b2 || c1 == d2) b++;
        if (d1 == a2 || d1 == b2 || d1 == c2) b++;
        cout << a << " " << b << endl;
    }
    return 0;
}