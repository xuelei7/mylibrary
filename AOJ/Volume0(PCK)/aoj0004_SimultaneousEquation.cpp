// Simultaneous Equation
// Write a program which solve a simultaneous equation:

// ax+by=c
// dx+ey=f

// The program should print x and y for given a, b, c, d, e and f (-1,000 ≤ a,b,c,d,e,f ≤ 1,000). You can suppose that given equation has a unique solution.

// Input
// The input consists of several data sets, 1 line for each data set. In a data set, there will be a,b,c,d,e,f separated by a single space. The input terminates with EOF.

// Output
// For each data set, print x and y separated by a single space. Print the solution to three places of decimals. Round off the solution to three decimal places.

// to algebra

#include <bits/stdc++.h>
using namespace std;

int main() {
    double a,b,c,d,e,f;
    while (cin >> a >> b >> c >> d >> e >> f) {
        double x = (b * f - c * e) / (b * d - a * e);
        if (b * f - c * e == 0) x = 0;
        double y = (c * d - a * f) / (b * d - a * e);
        if (c * d - a * f == 0) y = 0;
        cout << setprecision(3) << fixed << x << " " << y << endl;
    }

}