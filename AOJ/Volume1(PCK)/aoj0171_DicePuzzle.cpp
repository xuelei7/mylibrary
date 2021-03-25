
// 組み合わせ方には条件があり、各サイコロの向き合う面は同じアルファベットでかつ一方が小文字、も う一方が大文字でなければなりません。例えば、a と描かれた面に接することができるのは A と描か れた面です。ただし、接するときの文字の向きは問いません。




// このルールに従い、８つのサイコロの情報を入力とし、立方体を作れるか否かを判定するプログラムを作成してください。立方体を作れる場合は YES（半角英大文字）、作れない場合は NO（半角英大文字）と出力してください。

// なお、サイコロの各面の文字を次の図にあるように c1 〜 c6 と表すことにします。 また、1つのサイコロに同じ文字が複数回描かれていることは無いものとします（同じアルファベットの大文字と小文字はその限りではありません）。




// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下の形式で与えられます。

// s1
// s2
// :
// s8
// i 行目に i 個目のサイコロの情報 si が与えられます。si は長さ 6 の文字列であり j 文字目がサイコロの各面 cj に対応します。

// データセットの数は 50 を超えません。

// Output
// データセットごとに判定結果（半角英大文字）を１行に出力します。

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

auto solve (V<string>& s) -> void {
    int r[8][3] = {
        0,1,2,
        0,2,4,
        0,4,3,
        0,3,1,
        5,1,3,
        5,3,4,
        5,4,2,
        5,2,1
    };

    int rec[8][3] = {};
    bool used[8] = {};
    auto dfs = [&] (auto self, int id) -> bool {
        if (id == 8) return true;

        rep(i,0,8) { // 使うダイス
            if (used[i]) continue;
            used[i] = true;
            rec[id][0] = i;

            rep(j,0,8) { // 使う3つの面
                rec[id][1] = j;
                rep(k,0,3) { // 使う面の回転
                    rec[id][2] = k;

                    if (id&1) { // 前後
                        int a1 = rec[id][0];
                        int b1 = rec[id][1];
                        int c1 = rec[id][2];
                        int a2 = rec[id-1][0];
                        int b2 = rec[id-1][1];
                        int c2 = rec[id-1][2];

                        int cc1 = (c1+1) % 3;
                        int cc2 = (c2+1) % 3;
                        if ((s[a1][r[b1][cc1]] ^ 32) != s[a2][5-r[b2][cc2]]) continue;
                    }

                    if (id&2) { // 左右
                        int a1 = rec[id][0];
                        int b1 = rec[id][1];
                        int c1 = rec[id][2];
                        int a2 = rec[id-2][0];
                        int b2 = rec[id-2][1];
                        int c2 = rec[id-2][2];

                        int cc1 = (c1+2) % 3;
                        int cc2 = (c2+2) % 3;
                        if ((s[a1][5-r[b1][cc1]] ^ 32) != s[a2][r[b2][cc2]]) continue;
                    }

                    if (id&4) { // 上下
                        int a1 = rec[id][0];
                        int b1 = rec[id][1];
                        int c1 = rec[id][2];
                        int a2 = rec[id-4][0];
                        int b2 = rec[id-4][1];
                        int c2 = rec[id-4][2];

                        int cc1 = c1;
                        int cc2 = c2;
                        if ((s[a1][r[b1][cc1]] ^ 32) != s[a2][5-r[b2][cc2]]) continue;
                    }

                    if (self(self, id+1)) return true;

                }
            }

            used[i] = 0;
        }

        return false;
    };

    cout << (dfs(dfs, 0)? "YES": "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    V<string> s(8);
    while (cin >> s[0]) {
        if (s[0] == "0") break;
        rep(i,1,8) cin >> s[i];
        solve(s);
    }
    
    return 0;
}