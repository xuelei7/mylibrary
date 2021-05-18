#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int h,w;
VV<char> maze(2010, V<char>(2010));
VV<pair<int,int>> point(2010, V<pair<int,int>>(2010, {-1,-1}));

int p (int hh, int ww) {
    if (maze[hh][ww] == '+') return 1;
    return -1;
}

pair<int,int> f(int hh, int ww) {
    if (hh == h-1 && ww == w-1) return {0,0};
    if (point[hh][ww] != make_pair(-1, -1)) return point[hh][ww];

    // only right
    if (hh == h - 1) {
        auto res = f(hh, ww+1);
        return point[hh][ww] = {res.second + p(hh, ww+1), res.first};
    }
    // only down
    if (ww == w - 1) {
        auto res = f(hh+1, ww);
        return point[hh][ww] = {res.second + p(hh+1,ww), res.first};
    }

    // both
    auto res1 = f(hh, ww+1); // right
    auto res2 = f(hh+1, ww); // down
    res1 = {res1.second + p(hh, ww+1), res1.first};
    res2 = {res2.second + p(hh+1, ww), res2.first};
    int p1 = res1.first - res1.second;
    int p2 = res2.first - res2.second;
    if (p1 >= p2) {
        return point[hh][ww] = res1;
    } else {
        return point[hh][ww] = res2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    cin >> h >> w;
    rep(i,0,h) {
        rep(j,0,w) {
            cin >> maze[i][j];
        }
    }
    
    pair<int,int> res = f(0,0);

    if (res.first > res.second) {
        cout << "Takahashi" << endl;
    } else if (res.first == res.second) {
        cout << "Draw" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}