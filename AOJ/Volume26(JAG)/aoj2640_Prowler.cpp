// A さんと B 君は，N × M の長方形のマス目状の地域に住んでいる．各マス目は道か壁か家のどれかである．この地域は，道が複雑で入り組んでいるので痴漢被害がよく起こることで有名であるため，この地域と外部との境界は全て壁で囲まれており，隔離されている．

// B 君はなんとなく気が向いたので，A さんの家を眺めに行くことにした．しかし，不幸なことにB 君は明らかに怪しい顔をしているので，A さんの家に行く途中に少しでも痴漢の疑いがあるような行動を取ったらすぐに捕まってしまうだろう．特に，右手を壁から離して歩くことは絶対にやってはならない．B 君は，一瞬たりとも右手を離すことなく，A さんの家に辿り着くことが出来るだろうか？

// B 君はつねに上下左右いずれかの方向を向いていて，B 君の右手が届く範囲はB 君の向いている方向に対して正面，斜め右前，右，斜め右後ろの4 マスのみである．B 君は，次のいずれかの行動を繰り返す．ただし，これらを同時に行うことは出来ない．

// 前方に壁がない場合，1 マス進む．
// 向いている方向を90 度右に変える．
// 向いている方向を90 度左に変える．
// 右手が接するマスを変える．ただし，この時にB 君は右手を離すことが出来ないので，変更前のマスと変更後のマスの間には共通した点を持っていなくてはならない．
// Input
// 入力は以下の形式で与えられる．

// N M
// S1
// S2
// :
// SN
// Si (1 ≤ i ≤ N) は， M 文字の文字列で各文字は次を表す．

// "^"，"v"，"<"，">" は B 君の最初の位置と最初に向いている方向（上下左右の向き）を表す．
// "." は，何もないマスである．B 君は，このマスの上を移動することができる．
// "#" は，壁を表す．壁の上を移動することは出来ない．
// "G" は A さんの家の位置を表す．B 君は，A さんの家にたどり着くまで移動を繰り返す．
// Constraints
// 1 ≤ N ≤ 50
// 1 ≤ M ≤ 50
// 入力には，文字 "^"，"v"，"<"，">" のうちいずれかが必ず一つのみ現れる．
// 同様に，入力には，文字 "G" が必ず一つのみ現れる．
// 初期状態では，B 君が向いている方向から右の壁にB 君の右手が接している．
// Output
// 一度も右手を離さずにA さんの家に辿り着くことが出来る場合には，A さんの家にたどり着くまでに通った異なるマスの数の最小値を出力せよ．A さんの家に辿り着くことが出来ない場合には，-1 を出力せよ．

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

auto solve (int h, int w, VV<char>& maze) -> int {

    // 初期位置を決める
    int sh, sw, sd, gh, gw;
    rep(i,0,h) rep(j,0,w) {
        if (maze[i][j] == 'G') {
            gh = i;
            gw = j;
        } else if (maze[i][j] != '.' && maze[i][j] != '#') {
            sh = i;
            sw = j;
            string dir = "^>v<";
            rep(k,0,4) if (maze[i][j] == dir[k]) sd = k;
        }
    }


    auto wall = [&](int hh, int ww) -> bool {
        if (hh < 0 || hh >= h || ww < 0 || ww >= w) return true;
        if (maze[hh][ww] == '#') return true;
        return false;
    };

    struct status {
        int h, w, d;
        status(int h, int w, int d) : h(h), w(w), d(d) {}
        bool operator <(const status& s) const {
            if (d != s.d) return d < s.d;
            if (h != s.h) return h < s.h;
            return w < s.w;
        }
    };

    auto go = [&](status s) -> status {
        int dh[4] = {-1,0,1,0};
        int dw[4] = {0,1,0,-1};
        s.h = s.h + dh[s.d];
        s.w = s.w + dw[s.d];
        return s;
    };

    auto change_dir = [&](status s, int d) -> status {
        s.d = (s.d + d) % 4;
        return s;
    };

    set<status> used_s;
    set<pair<int,int>> used;
    status now(sh,sw,sd);
    while (1) {
        // ループになっている場合
        if (used_s.find(now) != used_s.end()) return -1;
        used_s.insert(now);
        used.insert(make_pair(now.h, now.w));
        if (now.h == gh && now.w == gw) return used.size();

        auto f = go(now); // 前
        auto fr = go(change_dir(go(now),1)); // 右前

        // 前に壁がある場合, 左に曲がる
        if (wall(f.h, f.w)) {
            now = change_dir(now, 3);
            continue;
        }

        // 右前に壁がある場合, 前進
        // そうでない場合，右前にいく，前のマスに印をつける
        if (wall(fr.h, fr.w)) {
            now = f;
        } else {
            now = fr;
            used.insert(make_pair(f.h,f.w));
            if (f.h == gh && f.w == gw) return used.size();
            used_s.insert(f);
            used_s.insert(change_dir(f,1));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int h,w;
    cin >> h >> w;
    VV<char> maze(h,V<char>(w));
    rep(i,0,h) rep(j,0,w) cin >> maze[i][j];

    // solve
    auto ans = solve(h,w,maze);

    // output
    cout << ans << endl;
    
    return 0;
}