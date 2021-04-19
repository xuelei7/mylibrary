// スパイダー人
// 正義のヒーロー「スパイダー人」は、腕からロープを出してビルからビルへ飛び移ることができます。しかし、ロープが短いので自分からの距離が 50 以下のビルにしか移動できません。それより遠くのビルに移動するには、一旦別のビルに飛び移らなくてはなりません。





// ビルの数 n、n 個のビルの情報、スパイダー人の移動開始位置及び目的地を入力とし、その移動の最短経路を出力するプログラムを作成してください。どのようにビルを経由しても目標のビルに移動できない場合は NA と出力してください。各ビルは点として扱い、最短距離で移動するビルの経由方法が２つ以上存在することはないものとします。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下の形式で与えられます。

// n
// b1 x1 y1
// b2 x2 y2
// :
// bn xn yn
// m
// s1 g1
// s2 g2
// :
// sm gm
// １行目にビルの数 n (1 ≤ n ≤ 100)、続く n 行に i 番目のビルのビル番号 bi (1 ≤ bi ≤ n)、そのビルのx座標とy座標を表す整数 xi, yi (-1000 ≤ xi, yi ≤ 1000) が空白区切りで与えられます。

// 続く行に移動情報の個数 m (1 ≤ m ≤ 100)、続く m 行にi 番目の移動情報が与えられます。各移動情報として、移動を開始するビルの番号 si と目的地ビルの番号 gi が空白区切りで与えられます。

// データセットの数は 10 を超えません。

// Output
// 入力データセットごとに次の形式で出力します。

// i 行目に i 番目の移動情報に対する経路または NA を１行に出力します。各経路は以下の形式で出力します。

// si bri1 bri2 ... gi
// brij は i 番目の移動情報における、j 番目に経由するビルの番号を表します。

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-7
int inf = 1e9;
int n,m;
double d[110][110];
int pre[110];
double x[110],y[110];
double dp[110];

struct P{
    double dist;
    int id;
    P(double dist, int id):dist(dist),id(id) {}
    bool operator < (const P& p) const {
        if (dist != p.dist) return dist > p.dist;
        return id < p.id;
    }
};

void fd(int s, int g) {
    memset(pre,-1,sizeof(pre));
    for (int i = 0; i < n; i++) dp[i] = inf;
    dp[s] = 0;
    priority_queue<P> pq;
    pq.push(P(0,s));
    while (!pq.empty()) {
        P tp = pq.top();
        pq.pop();
        if (dp[tp.id] < tp.dist) continue;
        if (tp.id == g) {
            vector<int> v;
            v.push_back(g);
            int now = g;
            while (now != s) {
                now = pre[now];
                v.push_back(now);
            }
            for (int i = v.size() - 1; i >= 0; i--) cout << v[i]+1 << " \n"[i==0];
            return;
        }
        for (int i = 0; i < n; i++) {
            double dist = tp.dist + d[tp.id][i];
            if (dist < dp[i]) {
                dp[i] = dist;
                pre[i] = tp.id;
                pq.push(P(dp[i],i));
            }
        }
    }
    cout << "NA" << endl;
    return;
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            int id;
            cin >> id;
            id--;
            cin >> x[id] >> y[id];
        }
        for (int i = 0; i < n; i++) {
            d[i][i] = inf;
            for (int j = i+1; j < n; j++) {
                int dist = (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
                if (dist <= 2500) {
                    d[i][j] = d[j][i] = sqrt((double)dist);
                } else {
                    d[i][j] = d[j][i] = inf;
                }
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int f,t;
            cin >> f >> t;
            f--;
            t--;
            fd(f,t);
        }
    }
    return 0;
}