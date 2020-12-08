#include <bits/stdc++.h>
using namespace std;

struct Vec {
    int x,y;
    Vec() {}
    Vec(int a, int b) : x(a), y(b) {}
    void operator += (Vec b) {
        x += b.x;
        y += b.y;
    }
    Vec operator - (Vec b) const { return Vec(x - b.x, y - b.y); }
    long long operator * (Vec b) const {
        return x * 1LL * b.y - y * 1LL * b.x;
    }
    double d() {
        return sqrt(x * 1LL * x + y * 1LL * y);
    }
};
