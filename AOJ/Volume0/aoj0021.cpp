// Parallelism
// There are four points: A(x1,y1), B(x2,y2), C(x3,y3), and D(x4,y4). Write a program which determines whether the line AB and the line CD are parallel. If those two lines are parallel, your program should prints "YES" and if not prints "NO".

// to geometry

#include <bits/stdc++.h>
using namespace std;
double cross(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (abs(cross(x2-x1,y2-y1,x4-x3,y4-y3)) < 1e-10) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}