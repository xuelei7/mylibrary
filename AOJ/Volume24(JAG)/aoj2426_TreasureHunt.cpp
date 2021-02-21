// 宝探し
// 太郎君はある広場にお宝を探しにやってきました。この広場にはたくさんのお宝が埋められていますが、太郎君は最新の機械を持っているので、どこにお宝が埋まっているかをすべて知っています。広場はとても広いので太郎君は領域を決めてお宝を探すことにしましたが、お宝はたくさんあるためどのお宝がその領域の中にあるかすぐにわかりません。そこで太郎君はその領域の中にあるお宝の数を数えることにしました。

// Input
// n m
// x1 y1
// x2 y2
// ...
// xn yn
// x11 y11 x12 y12
// x21 y21 x22 y22
// ...
// xm1 ym1 xm2 ym2
// nは広場に埋まっているお宝の数を表す
// mは調べる領域の数を表す
// 2行目からn+1行目はそれぞれのお宝が埋まっている座標を表す
// n+2行目からn+m+1行目はそれぞれの調べる領域を表す
// x軸の正の方向が東、y軸の正の方向が北を表す
// それぞれの領域は長方形であり、xi1とyi1は長方形の南西の頂点の座標、xi2とyi2は長方形の北東の頂点の座標を表す
// Constraints
// 1≤n≤5000
// 1≤m≤5×105
// |xi|,|yi|≤109(1≤i≤n)
// |xi1|,|yi1|,|xi2|,|yi2|≤109(1≤i≤m)
// xi1≤xi2,yi1≤yi2(1≤i≤m)
// すべての入力は整数で与えられる
// Output
// C1
// C2
// ...
// Cm
// それぞれの領域に含まれるお宝の数を各行に出力せよ

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5010;
int W, H, N;
int X[MAX_N], Y[MAX_N];
int cnt[MAX_N][MAX_N];

vector<int> compress(int *x1, int w) {
    vector<int> xs;

    for (int i = 0; i < w; i++) {
        int tx1 = x1[i];
        xs.push_back(tx1);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    return xs;
}

int main() {
    int n,m;
    cin >> n >> m;
    X[0] = Y[0] = -1e9-7;
    X[n+1] = Y[n+1] = 1e9+7;
    for (int i = 1; i <= n; i++) cin >> X[i] >> Y[i];
    vector<int> sx = compress(X,n+2);
    vector<int> sy = compress(Y,n+2);
    // for (auto p:sx) cout << p << " ";
    // cout << endl;
    // for (auto p:sy) cout << p << " ";
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        int tx = lower_bound(sx.begin(),sx.end(),X[i]) - sx.begin();
        int ty = lower_bound(sy.begin(),sy.end(),Y[i]) - sy.begin();
        cnt[tx][ty]++;
        // cout << X[i] << " " << Y[i] << " " << tx << " " << ty << endl;
    }
    H = sx.size();
    W = sy.size();
    for (int i = 1; i < H; i++) {
        for (int j = 1; j < W; j++) {
            cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            // cout << cnt[i][j] << " ";
        }
        // cout << endl;
    }

    for (int i = 0; i < m; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int tx2 = upper_bound(sx.begin(),sx.end(),x2) - 1 - sx.begin();
        int ty2 = upper_bound(sy.begin(),sy.end(),y2)  - 1- sy.begin();
        int tx1 = upper_bound(sx.begin(),sx.end(),x1-1) - 1 - sx.begin();
        int ty1 = upper_bound(sy.begin(),sy.end(),y1-1) - 1 - sy.begin();
        // cout << tx1 << " " << ty1 << " " << tx2 << " " << ty2 << endl;
        cout << cnt[tx2][ty2] - cnt[tx2][ty1] - cnt[tx1][ty2] + cnt[tx1][ty1] << endl;
    }
    return 0;
}
