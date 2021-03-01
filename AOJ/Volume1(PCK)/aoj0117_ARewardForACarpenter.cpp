// 大工の褒美
// ある日、殿様は一人の大工に、「台風や地震が来たときに町人が避難できる、頑丈で大きな建物を造りなさい。」と命じました。しかし、その頑丈で大きな建物を完成させるには、大きな太い柱が必要です。町にそんな大きな柱はありません。そこで、大工は遠くの山里まで大きな柱を調達しに行くことになりました（大工は町から里山に行って、町に戻ってくる必要があります）。

// 大工の褒美は、殿様から受け取ったお金から柱の代金と交通費を差し引いた余りです。下の地図のように、山里に行くには、いろいろな町を通るたくさんの街道があり、2つの町をつなぐ街道はそれぞれ交通費が違います。大工の褒美を最大にするにはどのように街道をたどり調達すればよいでしょうか。最大となる大工の褒美を出力するプログラムを作成してください。ただし、町の数を n とすれば、各町は 1 から n までの整数で識別されます。2 つの町を直接つなぐ街道は 2 本以上ありません。


// ※ 矢印上の数字は、その方向に行くための交通費を示します。

// Input
// 入力は以下の形式で与えられます。

// n
// m
// a1,b1,c1, d1
// a2,b2,c2, d2
// :
// am,bm,cm, dm
// s,g,V,P
// 1 行目に町の総数 n（ n ≤ 20）、2 行目に街道の総数 m (m ≤ 100) が与えられます。続く m 行に i 番目の街道の情報 ai, bi, ci, di (1 ≤ ai, bi ≤ n, 0 ≤ ci, di ≤ 1,000) が与えられます。ai, bi は街道 i がつないでいる町の番号、 ci は ai から bi への交通費、 di は bi から ai への交通費を表します。

// 最終行に大工が出発する町の番号 s、柱のある山里の番号 g、殿様から大工が受け取ったお金 V、柱の代金 P が与えられます。

// Output
// 大工の褒美（整数）を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
int dst[50][50];
int main() {
    int n,m,s,g,v,p;
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            dst[i][j] = inf;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        for (size_t j = 0; j < str.size(); j++) {
            if (str[j] == ',') str[j] = ' ';
        }
        stringstream ss(str);
        int a,b,c,d;
        ss >> a >> b >> c >> d;
        a--;
        b--;
        dst[a][b] = c;
        dst[b][a] = d;
    }
    cin >> str;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ',') str[i] = ' ';
    }
    stringstream ss(str);
    ss >> s >> g >> v >> p;
    s--;
    g--;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dst[i][j] = min(dst[i][k] + dst[k][j], dst[i][j]);
            }
        }
    }
    cout << v - dst[s][g] - dst[g][s] - p << endl;
    return 0;
}