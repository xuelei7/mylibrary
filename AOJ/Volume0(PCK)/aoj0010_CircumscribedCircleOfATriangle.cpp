// Circumscribed(外接) Circle of A Triangle.
// Write a program which prints the central coordinate (px,py) and the radius r of a circumscribed circle of a triangle which is constructed by three points (x1,y1), (x2,y2) and (x3,y3) on the plane surface.

// Input
// Input consists of several datasets. In the first line, the number of datasets n is given. Each dataset consists of:

// x1 y1 x2 y2 x3 y3

// in a line. All the input are real numbers.

// Output
// For each dataset, print px, py and r separated by a space in a line. Print the solution to three places of decimals. Round off the solution to three decimal places.

// Constraints
// −100<=x1,y1,x2,y2,x3,y3<=100
// n<=20

// to geometry

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double x1,x2,x3,y1,y2,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double px,py,r;
        py = ((x1-x3) * (x1*x1 - x2*x2 + y1*y1 - y2*y2) - (x1-x2) * (x1*x1 - x3*x3 + y1*y1 - y3*y3)) / (2 * ((y1-y2)*(x1-x3) - (y1-y3)*(x1-x2)));
        if (x1 != x2) px = (x1*x1 - x2*x2 + y1*y1 - y2*y2) / (2 * (x1-x2)) - py * (y1-y2) / (x1-x2);
        else px = (x1*x1 - x3*x3 + y1*y1 - y3*y3) / (2 * (x1-x3)) - py * (y1-y3) / (x1-x3);
        r = sqrt((x1 - px) * (x1 - px) + (y1 - py) * (y1 - py));
        cout << fixed << setprecision(3) << px << " " << py << " " << r << endl;
    }
    return 0;
}