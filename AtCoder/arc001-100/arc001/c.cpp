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

VV<char> maze(8,V<char>(8));

bool ok(int h, int w) {
    int dh[8] = {-1,0,1,0,1,1,-1,-1};
    int dw[8] = {0,1,0,-1,1,-1,1,-1};
    rep(i,0,8) {
        int th = h + dh[i], tw = w +  dw[i];
        while (th >= 0 && th < 8 && tw >= 0 && tw < 8) {
            if (maze[th][tw] == 'Q') return false;
            th += dh[i];
            tw += dw[i];
        }
    }
    return true;
}

bool ok() {
    rep(i,0,8) {
        rep(j,0,8) {
            if (maze[i][j] == 'Q') {
                if (!ok(i,j)) return 0;
            }
        }
    }
    return 1;
}

bool dfs(int k) {
    if (k == 8) return ok();

    rep(i,0,8) {
        rep(j,0,8) {
            if (maze[i][j] == '.') {
                if (ok(i,j)) {
                    maze[i][j] = 'Q';
                    if (dfs(k+1)) return true;
                    maze[i][j] = '.';
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    rep(i,0,8) rep(j,0,8) cin >> maze[i][j];

    if (!ok()) {
        cout << "No Answer" << endl;
        return 0;
    }

    if (dfs(3)) {
        rep(i,0,8) {
            rep(j,0,8) {
                cout << maze[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "No Answer" << endl;
    }

    
    return 0;
}