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

void make_maze(string s, VV<int>& maze) {
    int pos = 0;
    int f;
    while (pos < s.size()) {
        // col
        int col;
        char c = s[pos];
        pos++;
        if (c >= 'a' && c <= 't') {
            f = 1;
            col = c - 'a';
        } else {
            f = 2;
            col = c - 'A';
        }
        
        dbg(col);

        // row
        int row = 0;
        c = s[pos]; // first character
        pos++;
        row = c - '0';
        // second character
        if (s[pos] >= '0' && s[pos] <= '9') {
            row *= 10;
            row += s[pos] - '0';
            pos++;
        }
        row--; // 0 index

    #ifdef LOCAL
        cerr << row << " " << col << " " << f << endl;
    #endif
        assert(row < 20 && col < 20);
        maze[row][col] = f;
    }
}

int dh[4] = {-1,0,1,0};
int dw[4] = {0,1,0,-1};

string go(int h, int w, int d, VV<int>& maze) {
#ifdef LOCAL
    cerr << h << " " << w << " " << d << endl;
#endif
    if (maze[h][w] == 0) {
        ;
    } else if (maze[h][w] == 1) { // 1: '\'
        if (d == 0) d = 3;
        else if (d == 1) d = 2;
        else if (d == 2) d = 1;
        else if (d == 3) d = 0;
        maze[h][w] = 0;
    } else { // 2: '/'
        if (d == 0) d = 1;
        else if (d == 1) d = 0;
        else if (d == 2) d = 3;
        else if (d == 3) d = 2;
        maze[h][w] = 0;
    }
    if (h + dh[d] < 0 || w + dw[d] < 0 || h + dh[d] >= 20 || w + dw[d] >= 20) {
        return (char)('A' + w) + to_string(h+1);
    }
    return go (h + dh[d], w + dw[d], d, maze);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    string s;
    V<string> ans;
    while (cin >> s) {
        s = s.substr(1,s.size()-2);
        dbg(s.size());
        dbg(s);
        VV<int> maze(20,V<int>(20,0));
        // 1: '\', 2: '/'
        make_maze(s,maze);
        string last;
        rep(i,0,10) {
            last = go(i,0,1,maze);
            dbg(last);
        }
        ans.push_back(last);
    }
    rep(i,0,ans.size()) {
        cout << ans[i] << ",\n"[i == ans.size() - 1];
    }

    return 0;
}