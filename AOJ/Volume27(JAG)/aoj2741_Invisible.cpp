// D - インビジブル
// Problem Statement
// あなたは友達と"インビジブル"というカードゲームを遊ぼうとしている． このカードゲームでは，"得点カード"と"妨害カード"という2種類のカードを使う． それぞれの得点カードには，正の値が書かれている．このカードゲームのルールは次の通りである．

// ゲームはプレイヤー1とプレイヤー2の2人のプレイヤーで行われる．ゲームはプレイヤー1のターンから始まる．
// 場には，1つのスタックと2つのデッキがある．スタックは，2人のプレイヤーが置いたカードからなる．また，それぞれのプレイヤーが持つデッキはそのプレイヤーが持つ得点カードと妨害カードからなる．プレイヤーは自分，もしくは相手デッキのカードの順番をいつでも確認できる．ゲームの開始時点ではスタックには1枚もカードはない．
// 2人のプレイヤーは交互に次の2つの行動のどちらかをちょうど1回行う．
// 自分のデッキの一番上のカードをスタックの一番上に置く．ただし，この行動は自分のデッキにカードが1枚も存在しない時には行うことができない．
// 自分のターンをパスする．
// プレイヤーがターンをパスした時，次の処理を行う．
// 各プレイヤーは次の2つの条件を満たすスタック中のすべての得点カードを得る．得た得点カードは場から取り除かれる．
// 自分がスタックにおいた得点カードである．
// 相手が置いたどの妨害カードよりも上にある (スタック中に相手の妨害カードが存在しないとき，プレイヤーは自分がスタックに置いたすべてのカードを得る)．
// スタックのカードをすべて取り除く．
// もしスタックにカードがない状態で両プレイヤーが連続してパスした場合，ゲームを終了する． 各プレイヤーの最終的なスコアは，各プレイヤーが得た得点カードに書かれた数の総和である．

// 各プレイヤーは，自分のスコアから相手のスコアを引いた値を最大化するために最適な行動をとる． あなたの仕事は，与えられた各プレイヤーのデッキに対し，各プレイヤーが最適に行動したときのプレイヤー1のスコアとプレイヤー2のスコアの差を計算することである．

// Input
// 入力は次のような形式の単一テストケースからなる．

// n m
// a1 a2 … an
// b1 b2 … bm

// 1行目は山札の枚数を表す正の整数 n, m (1≤n,m≤50) からなる． 2行目は n 個の整数からなり，ai はプレイヤー1のデッキの上から i 番目のカードを表す (1≤i≤n)．ai は 1 以上，1,000,000 以下，または −1 である． 3行目は m 個の整数からなり，bj はプレイヤー2のデッキの上から j 番目のカードを表す (1≤j≤m)．bj は 1 以上，1,000,000 以下，または −1 である． ai, bj が正の整数の時は得点カードを表し，−1 の時は妨害カードを表す．

// Output
// お互いのプレイヤーが最適に行動した時の (プレイヤー1のスコア) - (プレイヤー2のスコア) を出力せよ．

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

// head a, head b
// point a, point b
// player, pass
int dp[51][51][51][51][2][3];
bool used[51][51][51][51][2][3];

int dfs(V<int>& me, V<int>& you, int ha, int hb, int pa, int pb, bool player, int pass) {
    if (used[ha][hb][pa][pb][player][pass]) return dp[ha][hb][pa][pb][player][pass];
    used[ha][hb][pa][pb][player][pass] = 1;

    int ret = -1e9;

    // 出す
    if (ha < me.size()) {
        if (me[ha] == -1) {
            ret = max(ret, -dfs(you, me, hb, ha+1, hb, pa, !player, 0));
        } else {
            ret = max(ret, -dfs(you, me, hb, ha+1, pb, pa, !player, 0));
        }
    }

    // pass
    int score = 0;
    rep(i,pa,ha) {
        if (me[i] != -1) score += me[i];
    }
    rep(i,pb,hb) {
        if (you[i] != -1) score -= you[i];
    }
    // 3 passes
    if (pass == 2) ret = max(ret, 0);
    else ret = max(ret, score - dfs(you, me, hb, ha, hb, ha, !player, pass+1));

    return dp[ha][hb][pa][pb][player][pass] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m;
    cin >> n >> m;
    V<int> a(n), b(m);
    rep(i,0,n) cin >> a[i];
    rep(i,0,m) cin >> b[i];
    
    cout << dfs(a,b,0,0,0,0,0,1) << endl;
    return 0;
}