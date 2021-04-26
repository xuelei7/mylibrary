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
    rep(i,0,h) {
        rep(j,0,w) {
            cin >> maze[i][j];
        }
    }

    VV<bool> bad_point(h+1, V<bool>(w+1));
    rep(i,0,h-1) {
        rep(j,0,w-1) {
            int cnt = 0;
            rep(a,0,2) {
                rep(b,0,2) {
                    if (maze[i+a][j+b] == '#') cnt++;
                }
            }
            if (cnt&1) bad_point[i+1][j+1] = 1;
        }
    }
    
    VV<int> hist(h+1, V<int>(w+1));
    rep(i,1,h+1) {
        rep(j,0,w+1) {
            hist[i][j] = hist[i-1][j] + 1;
            if (bad_point[i-1][j]) hist[i][j] = 1;
        }
    }

    VV<int> lft(h+1, V<int>(w+1)), rt(h+1, V<int>(w+1));
    // left
    rep(i,1,h+1) {
        stack<int> id, height;
        rep(j,0,w+1) {
            while (!id.empty() && height.top() >= hist[i][j]) {
                id.pop();
                height.pop();
            }
            
            if (!id.empty()) {
                lft[i][j] = id.top();
            } else {
                lft[i][j] = 0;
            }

            id.push(j);
            height.push(hist[i][j]);
        }
    }
    // right
    rep(i,1,h+1) {
        stack<int> id, height;
        rrep(j,0,w+1) {
            while (!id.empty() && height.top() >= hist[i][j]) {
                id.pop();
                height.pop();
            }
            
            if (!id.empty()) {
                rt[i][j] = id.top();
            } else {
                rt[i][j] = w;
            }

            id.push(j);
            height.push(hist[i][j]);
        }
    }

    // rep(i,0,h+1) {
    //     rep(j,0,w+1) {
    //         cout << hist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // get answer
    int ans = 0;
    rep(i,1,h+1) {
        rep(j,0,w+1) {
            ans = max(ans, hist[i][j] * (rt[i][j] - lft[i][j]));
        }
    }
    cout << ans << endl;
    return 0;
}