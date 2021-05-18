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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int h,w;
    cin >> h >> w;
    VV<char> maze(h, V<char>(w));
    int sh, sw, gh, gw;
    cin >> sh >> sw >> gh >> gw;
    sh--; sw--; gh--; gw--;

    rep(i,0,h) {
        rep(j,0,w) {
            cin >> maze[i][j];
        }
    }

    int inf = 1e9;
    VV<int> d(h, V<int>(w, inf));
    d[sh][sw] = 0;
    queue<pair<int,int>> q;
    q.push({sh, sw});

    int dh[4] = {-1,0,1,0};
    int dw[4] = {0,1,0,-1};

    while (!q.empty()) {
        auto tp = q.front(); q.pop();
        int hh = tp.first;
        int ww = tp.second;
        rep(i,0,4) {
            int th = hh + dh[i];
            int tw = ww + dw[i];
            if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
            if (maze[th][tw] == '#') continue;
            if (d[th][tw] > d[hh][ww] + 1) {
                d[th][tw] = d[hh][ww] + 1;
                q.push({th, tw});
            }
        }
    }

    cout << d[gh][gw] << endl;
    return 0;
}