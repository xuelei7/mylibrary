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
    
    int h,w,n;
    cin >> h >> w >> n;
    VV<char> maze(h, V<char>(w));
    V<int> sh(n+1), sw(n+1);

    rep(i,0,h) {
        rep(j,0,w) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') maze[i][j] = '0';
        }
    }
    rep(i,0,h) {
        rep(j,0,w) {
            rep(k,0,n+1) {
                if (maze[i][j] - '0' == k) {
                    sh[k] = i;
                    sw[k] = j;
                }
            }
        }
    }

    int inf = 1e9;
    V<VV<int>> d(n, VV<int>(h, V<int>(w, inf)));
    rep(i,0,n) {
        d[i][sh[i]][sw[i]] = 0;
        queue<pair<int,int>> q;
        q.push({sh[i], sw[i]});

        int dh[4] = {-1,0,1,0};
        int dw[4] = {0,1,0,-1};

        while (!q.empty()) {
            auto tp = q.front(); q.pop();
            int hh = tp.first;
            int ww = tp.second;
            rep(j,0,4) {
                int th = hh + dh[j];
                int tw = ww + dw[j];
                if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                if (maze[th][tw] == 'X') continue;
                if (d[i][th][tw] > d[i][hh][ww] + 1) {
                    d[i][th][tw] = d[i][hh][ww] + 1;
                    q.push({th, tw});
                }
            }
        }
    }

    int ret = 0;
    rep(i,0,n) {
        ret += d[i][sh[i+1]][sw[i+1]];
    }
    cout << ret << endl;
    return 0;
}