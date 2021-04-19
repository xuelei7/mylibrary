#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int h,w,a,b;
int maze[20][20];

int dfs(int hh, int ww, int aa, int bb) {
    if (ww == w) {
        ww = 0;
        hh++;
    }
#ifdef LOCAL
    cerr << hh << " " << ww << " " << aa << " " << bb << endl;
    rep(i,0,h) {
        rep(j,0,w) {
            cerr << maze[i][j];
        }
        cerr << endl;
    }
#endif
    
    if (hh == h) return (aa == 0 && bb == 0);
    if (maze[hh][ww] != 0) return dfs(hh,ww+1,aa,bb);

    int ans = 0;
    // 1: 1*1
    if (bb > 0) {
        maze[hh][ww] = 1;
        ans += dfs(hh,ww+1,aa,bb-1);
        maze[hh][ww] = 0;
    }
    // 2: 1*2
    if (aa > 0 && ww + 1 < w && maze[hh][ww+1] == 0) {
        maze[hh][ww] = 2;
        maze[hh][ww+1] = 2;
        ans += dfs(hh,ww+1,aa-1,bb);
        maze[hh][ww] = 0;
        maze[hh][ww+1] = 0;
    }
    // 3: 2*1
    if (aa > 0 && hh + 1 < h && maze[hh+1][ww] == 0) {
        maze[hh+1][ww] = 3;
        maze[hh][ww] = 3;
        ans += dfs(hh,ww+1,aa-1,bb);
        maze[hh+1][ww] = 0;
        maze[hh][ww] = 0;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> h >> w >> a >> b;
    cout << dfs(0,0,a,b) << endl;
    
    return 0;
}