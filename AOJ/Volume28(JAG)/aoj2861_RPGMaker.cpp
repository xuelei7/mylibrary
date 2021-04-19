// RPG Maker
// You are planning to create a map of an RPG. This map is represented by a grid whose size is H×W. Each cell in this grid is either '@', '*', '#', or '.'. The meanings of the symbols are as follows.

// '@': The start cell. The story should start from this cell.
// '*': A city cell. The story goes through or ends with this cell.
// '#': A road cell.
// '.': An empty cell.
// You have already located the start cell and all city cells under some constraints described in the input section, but no road cells have been located yet. Then, you should decide which cells to set as road cells.

// Here, you want a "journey" exists on this map. Because you want to remove the branch of the story, the journey has to be unforked. More formally, the journey is a sequence of cells and must satisfy the following conditions:

// The journey must contain as many city cells as possible.
// The journey must consist of distinct non-empty cells in this map.
// The journey must begin with the start cell.
// The journey must end with one of the city cells.
// The journey must contain all road cells. That is, road cells not included in the journey must not exist.
// The journey must be unforked. In more detail, all road cells and city cells except for a cell at the end of the journey must share edges with the other two cells both of which are also contained in the journey. Then, each of the start cell and a cell at the end of the journey must share an edge with another cell contained in the journey.
// You do not have to consider the order of the cities to visit during the journey.
// Initially, the map contains no road cells. You can change any empty cells to road cells to make a journey satisfying the conditions above. Your task is to print a map which maximizes the number of cities in the journey.

// Input
// The input consists of a single test case of the following form.

// H W
// S1
// S2
// :
// SH
// The first line consists of two integers N and W. H and W are guaranteed to satisfy H=4n−1 and W=4m−1 for some positive integers n and m (1≤n,m≤10). The following H lines represent a map without road cells. The (i+1)-th line consists of a string Si of length W. The j-th character of Si is either '*', '@' or '.' if both i and j are odd, otherwise '.'. The number of occurrences of '@' in the grid is exactly one. It is guaranteed that there are one or more city cells on the grid.

// Output
// Print a map indicating a journey. If several maps satisfy the condition, you can print any of them.

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

auto solve (int H, int W, VV<char>& maze) -> VV<char> {
    VV<char> ret(H,V<char>(W));
    int sh, sw;
    rep(i,0,H) {
        rep(j,0,W) {
            if (maze[i][j] == '@') {
                sh = i;
                sw = j;
            }
            ret[i][j] = '.';
        }
    }

    // 回字サークルを作る
    int u = 0, l = 0, b = H, r = W;
    while (u < b && l < r) {
        rep(i,u,b) {
            ret[i][l] = '#';
            ret[i][r-1] = '#';
        }
        rep(i,l,r) {
            ret[u][i] = '#';
            ret[b-1][i] = '#';
        }
        u+=2; b-=2;
        l+=2; r-=2;
    }
#ifdef LOCAL
    rep(i,0,H) {
        rep(j,0,W) {
            cerr << ret[i][j];
        }
        cerr << endl;
    }    
#endif


    // 橋を作る
    int mid = W / 2;
    u-=2; b+=2;
    l-=2; r+=2;
    bool f = 1;
    // 中から外側に
    b--; // 上の開区間が疲れたので閉区間にする
    while (u - 2 >= 0) {
        if (f) {
            ret[u][mid] = '.';
            ret[u-2][mid] = '.';
            ret[u-1][mid-1] = '#';
            ret[u-1][mid+1] = '#';
        } else {
            ret[b][mid] = '.';
            ret[b+2][mid] = '.';
            ret[b+1][mid-1] = '#';
            ret[b+1][mid+1] = '#';
        }
        u -= 2;
        b += 2;
        f = !f;
    }

    // 始点の周辺一つを削除する
    int dh[4] = {-1,0,1,0};
    int dw[4] = {0,1,0,-1};
    rep(i,0,4) {
        int th = sh + dh[i];
        int tw = sw + dw[i];
        if (th < 0 || tw < 0 || th >= H || tw >= W) continue;
        if (ret[th][tw] != '#') continue;
        ret[th][tw] = '.';
        th += dh[i];
        tw += dw[i];
        sh = th;
        sw = tw;
        break;
    }

    // 最初の街まで行く
    while (1) {
        if (maze[sh][sw] == '*') break;
        ret[sh][sw] = '.';
        rep(i,0,4) {
            int th = sh + dh[i];
            int tw = sw + dw[i];
            if (th < 0 || tw < 0 || th >= H || tw >= W) continue;
            if (ret[th][tw] != '#') continue;
            sh = th;
            sw = tw;
            break;
        }
    }

    // いろいろ入れる
    rep(i,0,H) {
        rep(j,0,W) {
            if (maze[i][j] != '.') {
                ret[i][j] = maze[i][j];
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int h,w;
    cin >> h >> w;

    VV<char> maze(h,V<char>(w));
    rep(i,0,h) {
        rep(j,0,w) {
            cin >> maze[i][j];
        }
    }

    auto ans = solve(h,w,maze);
    rep(i,0,h) {
        rep(j,0,w) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}