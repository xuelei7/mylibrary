// ぴょん吉の夏
// 会津大学には一面芝生で覆われた公園があり、日差しを遮る木や建物がありません。日差しの強い夏の日には、公園内に設置されたスプリンクラーが作動して芝生に散水しています。この公園にはカエルのぴょん吉が住み着いています。ぴょん吉は暑いのが苦手で、日差しが強い夏の日には常にスプリンクラーの水に当たっていないと干からびて死んでしまいます。公園に設置されたスプリンクラーは、節水のため一度に一つだけ散水することになっているので、ぴょん吉はスプリンクラーの作動に合わせて移動しなくてはなりません。


// (a) 公園の地図

	
// (b) ぴょん吉のジャンプ範囲	(c) スプリンクラーの散水範囲

// 公園は上図の(a)のとおりで、公園内の場所は縦横それぞれ 0~9 の座標で表し、黒い●がスプリンクラーで、その番号が作動する順番を表しています。これは一例で各スプリンクラーの場所と作動順序は日々変わります。

// ぴょん吉は不器用なので、移動するにも決まった距離をジャンプすることしかできません。ぴょん吉のジャンプできる範囲は上図(b)のとおりで、それ以外の場所に移動することはできません。しかも、一回のジャンプで相当体力を消耗するため、しばらく水に当たって休まなくてはなりません。

// スプリンクラーが散水できる範囲は上図(c)のとおりで、スプリンクラー自身の座標も含みます。各スプリンクラーは一定時間散水すると停止し、すぐに次のスプリンクラーが作動を開始します。ぴょん吉はこの時に一回だけジャンプするものとし、次に散水が停止するまでジャンプしないものとします。また、公園の四方は灼熱のアスファルトで囲まれているので公園の外にでてしまうような方向にはジャンプしないものとします。

// 猛暑となったこの夏。果たしてぴょん吉は生き延びることができたのでしょうか? ある日のぴょん吉の初期位置、スプリンクラーの位置と作動順序を読み込み、ぴょん吉が生き延びられる移動経路が存在している場合は”OK”、どう頑張っても死んでしまう場合は”NA”を出力するプログラムを作成してください。ただし、スプリンクラーの数は最大 10 個とし、ぴょん吉は一番目のスプリンクラーの作動と同時に初期位置からジャンプすることとします。

// Input
// 複数のデータセットが与えられます。各データセットは以下の形式で与えられます。

// px py
// n
// x1 y1 x2 y2 ... xn yn
// 1 行目にぴょん吉の初期位置の横座標 px と縦座標 py が与えられます。 2 行目にスプリンクラーの数 n が与えられます。 3 行目に i 番目に動作するスプリンクラーの横座標 xi と縦座標 yi が与えられます。

// 入力はゼロ２つの行で終わります。データセットの数は 20 を超えません。

// Output
// 各データセットについて、生存の場合は OK、そうでない場合は NA を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;
int px,py;
int jmp[12] = {-21,-20,-19,-12,-8,-2,2,8,12,19,20,21};
int spr[9] = {-11,-10,-9,-1,0,1,9,10,11};
int a[10];
int n;
bool dfs(int p, int d) {
    if (d == n) return 1;
    for (int i = 0; i < 12; i++) {
        int tp = p + jmp[i];
        if (tp < 0 || tp >= 100) continue;
        for (int j = 0; j < 9; j++) {
            int ta = a[d] + spr[j];
            if (ta < 0 || ta >= 100) continue;
            if (ta == tp)
                if (dfs(ta,d+1)) return 1;
        }
    }
    return 0;
}
int main() {
    while (cin >> px >> py) {
        if (px == 0 && py == 0) break;
        int p = px + 10*py;
        cin >> n;
        int f[n];
        for (int i = 0; i < n; i++) {
            cin >> px >> py;
            a[i] = px + 10*py;
        }
        cout << (dfs(p,0)? "OK":"NA") << endl;
    }
    return 0;
}