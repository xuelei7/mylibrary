// Window
// In the building of Jewelry Art Gallery (JAG), there is a long corridor in the east-west direction. There is a window on the north side of the corridor, and N windowpanes are attached to this window. The width of each windowpane is W, and the height is H. The i-th windowpane from the west covers the horizontal range between W×(i−1) and W×i from the west edge of the window.


// Figure A1. Illustration of the window


// You received instructions from the manager of JAG about how to slide the windowpanes. These instructions consist of N integers x1,x2,...,xN, and xi≤W is satisfied for all i. For the i-th windowpane, if i is odd, you have to slide i-th windowpane to the east by xi, otherwise, you have to slide i-th windowpane to the west by xi.

// You can assume that the windowpanes will not collide each other even if you slide windowpanes according to the instructions. In more detail, N windowpanes are alternately mounted on two rails. That is, the i-th windowpane is attached to the inner rail of the building if i is odd, otherwise, it is attached to the outer rail of the building.

// Before you execute the instructions, you decide to obtain the area where the window is open after the instructions.

// Input
// The input consists of a single test case in the format below.

// N H W
// x1 ... xN
// The first line consists of three integers N,H, and W (1≤N≤100,1≤H,W≤100). It is guaranteed that N is even. The following line consists of N integers x1,...,xN while represent the instructions from the manager of JAG. xi represents the distance to slide the i-th windowpane (0≤xi≤W).

// Output
// Print the area where the window is open after the instructions in one line.

#include <bits/stdc++.h>
using namespace std;
int n,h,w;
int a[110];
bool ok[10010];
void solve() {
    memset(ok,0,sizeof(ok));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < w; j++) {
            ok[i*w+j+a[i]] = 1;
        }
    }
    for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < w; j++) {
            ok[i*w-a[i]+j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n*w; i++) {
        ans += h*ok[i];
    }
    cout << h * n * w - ans << endl;
}

int main() {
    while (cin >> n >> h >> w) {
        solve();
    }
}