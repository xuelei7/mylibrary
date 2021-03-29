// 博士の研究室
// 会津大学の鶴賀博士はとても研究熱心なことで有名です。彼の研究室には複数の学生がいますが、彼は毎日夜遅くまで研究をするので必ず最後に帰宅します。彼の研究室にはドアでつながった複数の部屋があり、最後に研究室を出る人がすべての部屋の明かりを消して帰宅することになっています。

// 最近、大学では省エネに力を入れているため、すべての明かりが消えているか厳しくチェックされます。困ったことに彼は誰もが認める極度の臆病者で、明かりの消えた部屋には決して入ることができません。そこで、彼はある部屋の照明のON/OFFを他の部屋から操作できるように研究室の照明設備を改造しました。

// ところが、予算の都合で１つの部屋からコントロールできる部屋が限られています。その上、帰宅時の各部屋の明かりの状態も日によって異なるため、全ての明かりを消して出口までたどりつくのに毎日かなりの時間が掛かっています。そこで、研究員のあなたが博士を助けるためにプログラムを作成することになりました。

// 研究室の部屋情報、各部屋の明かりの点灯情報、各部屋の照明スイッチの情報を入力とし、博士がすべての明かりを消して帰宅できるかどうかを出力するプログラムを作成してください。ただし、部屋の数 n は 1 以上 15 以下の整数、ドアの数 m は 1 以上 30 以下の整数、照明の点灯情報 l は 0 または 1 の整数でそれぞれ消灯と点灯を表し、各部屋には 1 以上 n 以下の整数で番号が付与されているものとします。出口は番号 n の部屋に存在し、博士は常に部屋 1 からスタートするものとします。

// なお、出力は、博士の取るべき行動に応じて以下の 3 通りに分けて出力します。

// ケース１. 出口以外の全ての明かりを消して出口にたどりつける場合（経路の過程で出口を通ってもよい）。

// You can go home in X steps.
// と出力します。ここで X は部屋の移動、スイッチのON/OFF をそれぞれ１ステップとした場合の、博士の部屋から出口にたどり着くまでの最短のステップ数です。さらに、以下の文字列に従い博士の部屋から出口までの経路（博士のとるべき行動）を X 行で出力します。

// 部屋 R へ移動する場合
// Move to room R.
// 部屋 R の照明を消す場合
// Switch off room R.
// 部屋 R の照明を点灯する場合
// Switch on room R.
// ここで、R は部屋の番号を表します。博士がある部屋に移動した直後、複数のスイッチを操作して次の部屋に移動する場合は操作する部屋番号が小さいほうから出力してください。この条件を満たす限り、複数の解がある場合は、どれを出力してもかまいません。この情報をもとに、博士は無事帰宅することができます。

// ケース2. 出口にたどり着くことはできるが、出口のある部屋以外の全ての明かりを消すことが できない場合。

// You can not switch off all lights.
// と出力する。この場合、博士は省エネを守らなかったとして大学に罰せられます。

// ケース3. どうあがいても出口にたどり着けない場合。

// Help me!
// と出力する。この場合、博士は警備員に緊急救助を求めます。

// 簡単な例を示します。この例では、研究室は 4 つの部屋で構成され、部屋 1 と 2、2 と 3、2 と 4 がそれぞれ繋がっています。また、部屋 1 及び 4 から部屋 2、3 の照明を操作することができ、部屋 3 から部屋 1、2、4 の照明を操作することができます。最初、部屋 2、3、4 の照明が消えた状態で、博士が部屋 1 にいます。



// この状況では、博士が取るべき行動は次のようになります。

// 部屋2と3の照明をonにする。
// 部屋2に移動する。
// 部屋3に移動する。
// 部屋1の照明をoffにし、部屋4の照明をonにする。
// 部屋2に移動する。
// 部屋4に移動する。
// 部屋2と3の照明をoffにする。
// これで博士は部屋 4 以外の照明を消すことができ、帰宅することができます。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロ2つの行で示されます。 各データセットは以下の形式で与えられます。

// n m
// s1 t1
// s2 t2
// :
// sm tm
// l1 l2 ... ln
// k1 r1 r2 ...  rk1
// k2 r1 r2 ...  rk2
// :
// kn r1 r2 ...  rkn
// １行目に部屋の数 n (1 ≤ n ≤ 15) とドアの数 m (1 ≤ m ≤ 30) が空白区切りで与えられます。続く m 行に i 個目のドアの情報が与えられます。si ti は部屋 si と部屋 ti がドアで繋がっていることを表します。

// 続く１行に、部屋 i の照明の点灯情報 li (0 または 1) が空白区切りで与えられます。

// 続く n 行に部屋 i のスイッチ情報が与えられます。ki (0 ≤ ki ≤ 12) は部屋 i のスイッチの数、r1 ... rki は照明を操作できる部屋の番号を表します。

// データセットの数は100 を超えません。

// Output
// データセットごとに、上記の 3 通りの結果に応じて以下の形式で出力します。

// ケース 1 の場合

// 1行目: You can go home in X steps.
// 2行目: 1つ目の博士が取るべき行動
// 3行目: 2つ目の博士が取るべき行動
// :
// X+1 行目: X 個目の博士が取るべき行動
// ケース 2 の場合

// 1 行目: You can not switch off all lights.
// ケース 3 の場合

// 1 行目: Help me!


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

auto solve (int n, VV<int>& G, int s, VV<int>& R) -> void {
    VV<bool> dp((1<<n), V<bool>(n,0));
    VV<pair<int,int>> pre((1<<n), V<pair<int,int>>(n));
    queue<pair<int,int>> q;
    q.push({s,0});
    dp[s][0] = 1;
    pre[s][0] = {s,-1};

    bool goal = 0;

    rep(i,0,n) sort(R[i].begin(), R[i].end());

    while (!q.empty()) {
        auto tp = q.front(); q.pop();
        if (tp.second == n-1) goal = 1;

#ifdef LOCAL
    cerr << "search " << tp.second << " " << bitset<4>(tp.first) << endl;
#endif

        // 移動しない場合
        rep(i,0,R[tp.second].size()) {
            int roomid = R[tp.second][i];
            if (roomid == tp.second) continue;
            int nxt_status;
            if (tp.first & (1<<roomid)) {
                nxt_status = tp.first - (1<<roomid);
            } else {
                nxt_status = tp.first + (1<<roomid);
            }
            if (dp[nxt_status][tp.second]) continue;
            dp[nxt_status][tp.second] = 1;
            q.push({nxt_status, tp.second});
            pre[nxt_status][tp.second] = tp;
        }

        // 移動する場合
        rep(i,0,G[tp.second].size()) {
            int to = G[tp.second][i];
            if (!((tp.first >> to) & 1)) continue;
            if (dp[tp.first][to]) continue;
            dp[tp.first][to] = 1;
            q.push({tp.first,to});
            pre[tp.first][to] = tp;
        }

    }

    if (dp[1<<(n-1)][n-1]) { // case 1
        V<int> ret;
        int now_status = 1<<(n-1);
        int now = n-1;
        while (1) {
            auto p = pre[now_status][now];
            int nxt_status = p.first;
            int nxt = p.second;
            if (nxt == -1) break;

            // go to room pre
            if (nxt != now) {
                ret.push_back(now+101);
            } else { // turn on/off lights
                rep(i,0,n) {
                    int b1 = ((now_status >> i) & 1);
                    int b2 = ((nxt_status >> i) & 1);
                    if (b1 == b2) continue;
                    ret.push_back(b1 ? i+1 : -(i+1));
                }
            }
            now_status = nxt_status;
            now = nxt;
        }

        // result part
        cout << "You can go home in " << ret.size() << " steps.\n";
        rrep(i,0,ret.size()) {
            if (ret[i] > 100) {
                cout << "Move to room " << ret[i] - 100 << ".\n";
            } else if (ret[i] > 0) {
                cout << "Switch on room " << ret[i] << ".\n";
            } else {
                cout << "Switch off room " << -ret[i] << ".\n";
            }
        }
        return;
    }

    // case 2
    if (goal) {
        cout << "You can not switch off all lights.\n";
        return;
    }
    // case 3
    cout << "Help me!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n,m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        VV<int> G(n);
        rep(i,0,m) {
            int s,t;
            cin >> s >> t;
            s--;
            t--;
            G[s].push_back(t);
            G[t].push_back(s);
        }
        int s = 0;
        rep(i,0,n) {
            int l;
            cin >> l;
            if (l) s += (1<<i);
        }
        VV<int> R(n);
        rep(i,0,n) {
            int k;
            cin >> k;
            rep(j,0,k) {
                int r;
                cin >> r;
                r--;
                R[i].push_back(r);
            }
        }

        solve(n,G,s,R);
    }

    return 0;
}