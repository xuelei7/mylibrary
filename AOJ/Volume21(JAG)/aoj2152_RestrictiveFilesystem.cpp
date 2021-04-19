// Problem D: Restrictive Filesystem
// あなたは新型記録媒体の開発チームに所属するプログラマーである．この記録媒体はデータの読み込み及び消去はランダムアクセスが可能である．一方，データを書き込むときは，常に先頭から順番にアクセスしていき，最初に見つかった空き領域にしか書き込むことができない．

// あなたはこの記録媒体用のファイルシステムの構築を始めた．このファイルシステムでは，記録媒体の制限から，データは先頭の空き領域から順に書き込まれる．書き込みの途中で別のデータが存在する領域に至った場合は，残りのデータをその後ろの空き領域から書き込んでいく．

// データの書き込みはセクタと呼ばれる単位で行われる．セクタには 0 から始まる番号が割り当てられており，この番号は記憶媒体上の物理的な位置を指す．セクタ番号は，記憶媒体の先頭から後方に向かって順に 0，1，2，3，… と割り当てられている．

// ファイルシステムには，書き込み，削除，セクタの参照という 3 つのコマンドが存在する．

// あなたの仕事はこのファイルシステムの挙動を再現した上で，参照コマンドが実行されたとき対象セクタにはどのファイルが配置されているか出力するプログラムを書くことである．なお，初期状態では記録媒体には何も書き込まれていない．

// 例えば，Sample Input の最初の例を見てみよう．最初の命令では 0 という識別子を持ったサイズが 2 であるファイルを書き込む．初期状態では記録媒体には何も書き込まれていない，すなわち全てのセクタが空き領域であるから，先頭にある 2 つのセクタ，すなわち 0 番目のセクタと 1 番目のセクタに書き込みが行われる．したがって，書き込みの後の記憶媒体は次のようになっている．

// ０ ０ 空 空 空 空 空 空 …
// 2 番目の命令によって，1 という識別子を持つファイルが 2 番目と 3 番目のセクタに書き込まれる．この後の記憶媒体の状態は次のようになる．

// ０ ０ １ １ 空 空 空 空 …
// 3 番目の命令によって，0 の識別子を持つファイルが削除される．記憶媒体の状態は次のようになる．

// 空 空 １ １ 空 空 空 空 …
// 4 番目の命令によって，2 という識別子を持つファイルを 0 番目，1 番目，4 番目，5 番目のセクタに書き込む．

// ２ ２ １ １ ２ ２ 空 空 …
// 最後の命令では，3 番目のセクタが参照される．いま，3 番目のセクタには 1 という識別子のファイルが配置されているので，あなたのプログラムは 1 と出力しなければならない．

// Input
// 入力は複数のデータセットからなる．各データセットは次の形式で与えられる．

// N
// Command1
// Command2
// ...
// CommandN
// N は実行されるコマンドの数 (1 ≤ N ≤ 10,000)，Commandi は i 番目に実行されるコマンドをそれぞれ表す．

// 各コマンドは，コマンド名と 1 つまたは 2 つの引数からなる．コマンド名は 1 つの文字のみからなり，「W」，「D」，「R」のいずれかである．コマンドと引数の間，および引数と引数の間はそれぞれ 1 つのスペースで区切られる．

// 「W」は書き込みのコマンドを表す．2 つの引数 I (0 ≤ I ≤ 109) と S (1 ≤ S ≤ 109) が与えられる．それぞれ，書き込むファイルの識別子とそのファイルを記憶するのに必要とするセクタの数を示す．

// 「D」は削除のコマンドを表す．1 つの引数 I (0 ≤ I ≤ 109) が与えられる．削除するファイルの識別子を示す．

// 「R」は参照のコマンドを表す．1 つの引数 P (0 ≤ P ≤ 109) が与えられる．参照するセクタの番号を示す．

// 109 よりも大きな番号を持つセクタにはアクセスする必要はないと仮定してよい．また，同じファイル識別子を持つファイルを複数回書き込むことはないことが保証されている．

// 入力の終わりは，1 つの 0 を含む 1 行で示される．

// Output
// 各データセットについて，参照のコマンドが現れるごとに，そのコマンドによって参照されたファイルの識別子を 1 行に出力せよ．参照したセクタにファイルが書き込まれていなかった場合は，ファイル識別子の代わりに -1 を出力せよ．

// 各データセットの後には空行を入れること．

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

map<int,V<int>> rec;
set<pair<int,int>> st;

void Write(int id, int len) {
    int pre = 0;
    V<pair<int,int>> dlt, inst;
    for (auto& p: st) {
        if (p.second == -1) {
            if (p.first - pre < len) {
                dlt.push_back(p);
                inst.push_back({p.first, id});
                rec[id].push_back(p.first);
                len -= p.first - pre;
            } else if (p.first - pre == len) {
                dlt.push_back(p);
                inst.push_back({p.first, id});
                rec[id].push_back(p.first);
                break;
            } else {
                inst.push_back({pre+len, id});
                rec[id].push_back(pre+len);
                break;
            }
        }
        pre = p.first;
    }
    for (auto p:dlt) {
        st.erase(p);
    }
    for (auto p:inst) {
        st.insert(p);
    }
#ifdef LOCAL
    cerr << "Write " << id << " " << len << endl;
    for (auto p:st) {
        cerr << "{" << p.first << "," << p.second << "}";
    }
    cerr << endl;
#endif
}

void Delete(int id) {
    for (auto p: rec[id]) {
        st.erase({p,id});
        st.insert({p,-1});
    }
    rec.erase(id);
}

int Read(int id) {
    return (*lower_bound(all(st),make_pair(id+1,-2))).second;
}

auto solve (int n) -> V<int> {
    rec.clear();
    st.clear();
    st.insert({1e9+1,-1});
    V<int> ret;
    rep(i,0,n) {
        char c;
        int id, len;
        cin >> c >> id;
        if (c == 'W') cin >> len;

        if (c == 'W') Write(id, len);
        else if (c == 'D') Delete(id);
        else ret.push_back(Read(id));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n;
    while (cin >> n) {
        if (n == 0) break;
        // solve
        auto ans = solve(n);

        for (auto a: ans) {
            cout << a << endl;
        }
        cout << endl;
    }
    return 0;
}