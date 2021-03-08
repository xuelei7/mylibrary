// 暗号化システム
// あるプログラマーが新しい暗号化システムを開発した． しかし，そのシステムには異なる複数の文字列が同じ文字列に暗号化されてしまうという問題点があった．

// 彼のシステムによって暗号化された文字列が与えられる． 元の文字列を復号するため，暗号化される前の文字列の候補をすべて列挙したい． あなたの仕事はそのためのプログラムを作成することである．

// 小文字 a-z からなる文字列に対して，暗号化は次のステップに従って実行される．

// 最初に現れた 'b' を 'a' に置き換える．'b' が存在しなければ何もしない．
// 最初に現れた 'c' を 'b' に置き換える．'c' が存在しなければ何もしない．
// ...
// 最初に現れた 'z' を 'y' に置き換える．'z' が存在しなければ何もしない．
// Input
// 入力は100個以下のデータセットからなる． 各データセットは1行であり，暗号化後の文字列を表す． 文字列は小文字a-zからなり，1文字以上，20文字以下である．

// 入力の終わりは，1つの # のみを含む行で示される．

// Output
// 各データセットに対して 暗号化する前の文字列の候補の数 n を1行目に出力し， その後，暗号化前の文字列の候補を1行に1つずつ出力せよ． もし n が10以下であれば，候補を辞書順ですべて出力し， そうでなければ辞書順における先頭と末尾の5個ずつを辞書順で出力すること．

// ここで辞書順は次のように再帰的に定義される． 空文字列は辞書順で最初に現れる． 2つの空でない文字列 x = x1 ... xk と y = y1 ... yl について， 文字列 x が辞書順で文字列 y より前であるとは，以下を満たすことをいう．

// x1 が y1 よりアルファベット順 ('a'から'z') で前である．または
// x1 と y1 が同じ文字であり x2 ... xk が y2 ... yl よりも辞書順で前に現れる
// ことをいう．

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

auto solve (string s) -> void {
    int n = s.size();
    set<string> st;

    auto f = [&](auto self, int pos, int u) -> void {
        if (pos == n) {
            st.insert(s);
            return;
        }

        // 非暗号
        if (s[pos] == 'a' || ((u>>(s[pos]-'a')) & 1)) {
            self(self,pos+1,u);
        }

        // 暗号
        if (s[pos] != 'z' && !((u>>(s[pos]-'a'+1))&1)) {
            s[pos]++;
            self(self,pos+1,u+(1<<(s[pos]-'a')));
            s[pos]--;
        }
    };

    f(f,0,0);

    // out
    if (st.size() <= 10) {
        cout << st.size() << endl;
        for (auto ss: st) {
            cout << ss << endl;
        }
    } else {
        cout << st.size() << endl;
        auto it = st.begin();
        rep(i,0,5) {
            cout << *it << endl;
            it++;
        }
        it = st.end();
        rep(i,0,5) {
            it--;
        }
        rep(i,0,5) {
            cout << *it << endl;
            it++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    string s;
    while (cin >> s) {
        if (s == "#") break;

        // solve
        solve(s);
    }

    return 0;
}