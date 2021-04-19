// Problem B Squeeze the Cylinders
// Laid on the flat ground in the stockyard are a number of heavy metal cylinders with (possibly) different diameters but with the same length. Their ends are aligned and their axes are oriented to exactly the same direction.

// We'd like to minimize the area occupied. The cylinders are too heavy to lift up, although rolling them is not too difficult. So, we decided to push the cylinders with two high walls from both sides.

// Your task is to compute the minimum possible distance between the two walls when cylinders are squeezed as much as possible. Cylinders and walls may touch one another. They cannot be lifted up from the ground, and thus their order cannot be altered.


// Figure B.1. Cylinders between two walls

// Input
// The input consists of a single test case. The first line has an integer N (1≤N≤500), which is the number of cylinders. The second line has N positive integers at most 10,000. They are the radii of cylinders from one side to the other.

// Output
// Print the distance between the two walls when they fully squeeze up the cylinders. The number should not contain an error greater than 0.0001.

#include <bits/stdc++.h>
using namespace std;
double r[510];
double d[510][510];
double p[510];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = sqrt((r[i]+r[j])*(r[i]+r[j])-(r[i]-r[j])*(r[i]-r[j]));
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            p[i] = max(p[i],p[j]+d[i][j]);
        }
    }
    double ans = p[n-1];
    double mx = r[0];
    for (int i = 0; i < n; i++) {
        mx = max(mx, -p[i]+r[i]);
    }
    ans += mx;
    mx = r[n-1];
    for (int i = 0; i < n; i++) {
        mx = max(mx, p[i] + r[i] - p[n-1]);
    }
    ans += mx;
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}