// ゲームバランス
// あなたは冒険ゲームを作成している．このゲームのプレイヤーは，主人公を操作して敵モンスターを倒し，主人公のレベルを上げることで冒険を進めていく．主人公の初期レベルは 1 である．

// このゲームには N 種類の敵モンスターが用意されており，弱い順で i 番目の種類の敵モンスターの強さは si である．主人公が 1 回の戦闘を行うときには，次に戦う敵モンスターの種類を自由に選び，ちょうど 1 体の敵モンスターと戦闘を行う．主人公は同じ種類の敵モンスターと何回でも戦うことができ，何回でも倒すことができる．

// あなたはいま，このゲームのバランスを調整するために，あるパラメーター X を決めようとしている．パラメーター X は正の整数であり下記のように使われる．

// 主人公のレベルが L のとき，強さ si が L+X 未満の敵は倒せるが，それより強い敵モンスターは倒せない．
// 主人公のレベルが L のとき，強さ si の敵を倒すと max(1, X-|L-si|) だけ主人公のレベルが上がる．
// このゲームは，最も強い（N 種類目の）敵モンスターを初めて倒したときにゲームクリアとなる．あなたは，ゲームクリアまでに必要となる戦闘の回数が最低でも M 回以上となるようにパラメーター X を決めたいと考えている．ただし，敵モンスターの強さの設定によっては，X をどのように設定しても M 回未満の戦闘回数でゲームクリアできてしまうか，ゲームをクリアできなくなってしまう場合があることに注意せよ．

// パラメーター X を決めるとき，上記の条件を満たす範囲で最大のパラメーター値 Xmax を計算するプログラムを作ってほしい．

// Input
// 入力は複数のデータセットから構成される．データセットの個数は最大でも 50 を超えない．各データセットは次の形式で表される．

// N M
// s1 s2 ... sN
// 1 行目は空白で区切られた 2 つの整数 N, M からなる．N は用意した敵モンスターの種類の数，M はゲームクリアまでに必要となるべき最小の戦闘の数であり，1 ≤ N ≤ 100,000, 2 ≤ M ≤1,000,000 を満たす．

// 2 行目は空白で区切られた N 個の整数 s1, s2, ..., sN からなり，N 種類の敵モンスターそれぞれの強さを表す．各 si は 1 ≤ si ≤ 1,000,000 を満たし，また si < si+1 (1 ≤ i ≤ N-1) である．

// 入力の終わりは空白で区切られた 2 つのゼロからなる行で表される．

// Output
// 各データセットについて，ゲームクリアまでに必要となる戦闘の回数が M 回以上となるパラメーター X の内の最大値 Xmax を整数で出力せよ．X をどのように設定しても M 回未満の戦闘回数でゲームクリアできてしまうかゲームをクリアできなくなってしまうテストケースの場合には -1 のみからなる行を出力せよ．

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

auto solve (int N, int M, V<int>& S) -> int {
    auto f = [&](int X) -> int {
#ifdef LOCAL
    cerr << "search " << X << endl;
#endif
        int ret = 0;
        int lv = 1;
        while (1) {
            ret++;
// #ifdef LOCAL
//     cerr << ret << ": " << lv << endl;
// #endif
            if (lv + X > S[S.size() - 1]) break;
            int lvup = 1;
            int pos = lower_bound(all(S), lv) - S.begin();
            if (pos == N) {
                pos--;
                lvup = max(lvup, X - abs(lv - S[pos]));
            } else if (S[pos] == lv) {
                lvup = max(lvup, X);
            } else {
                if (S[pos] < lv + X) {
                    lvup = max(lvup, X - abs(lv - S[pos]));
                }
                if (pos > 0) {
                    lvup = max(lvup, X - abs(lv - S[pos-1]));
                }
            }
            lv += lvup;
        }
#ifdef LOCAL
    cerr << X << " " << ret << endl;
#endif
        return ret;
    };
    
    int l = max(1, S[0]), r = 1e9;
    if (f(l) < M) return -1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (f(mid) < M) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }

    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m;
    while (cin >> n >> m) {
        if (n+m == 0) break;
        V<int> s(n);
        rep(i,0,n) {
            cin >> s[i];
        }
        auto ans = solve(n,m,s);
        cout << ans << endl;
    }
    
    return 0;
}