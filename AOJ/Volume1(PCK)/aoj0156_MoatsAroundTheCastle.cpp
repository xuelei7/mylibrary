// 城の堀
// いま、忍者が城外から天守閣に忍び入ろうと計画を立てています。この忍者は地面を走ったり、堀の中を泳いだりすることは難なくできますが、堀から這い上がることはとても苦手なので、忍者は堀に入る回数をできるだけ少なくしたいと考えています。

// お城の見取図を入力とし、城外から天守閣に至るまでに、堀から這い上がらなくてはならない最小回数を出力するプログラムを作成して下さい。お城の見取図は二次元格子として与えられます。見取り図に描かれた記号には、天守閣の位置を示す「&」と堀の位置を示す「#」の位置が記され、そのほかの地点には「.」（半角ピリオド）が記されています。なお、お城には天守閣は一つだけあるものとし、忍者は走ったり泳いだりして移動するときに東西南北方向に1マスずつ移動するものとし、斜めには移動しません。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロ２つの行で示されます。各データセットは以下の形式で与えられます。

// n m
// c1,1c1,2...c1,n
// c2,1c2,2...c2,n
// :
// cm,1cm,2...cm,n
// １行目に見取図の東西の幅 n と 南北の幅 m (1 ≤ n, m ≤ 100) が与えられる。続くm 行に見取り図の i 行目の情報が与えられる。各情報は記号「&」、「#」、「.」からなる長さ n の文字列である。

// データセットの数は 50 を越えない。

// Output
// データセットごとに堀から這い上がらなくてはならない最小回数（整数）を１行に出力します。

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> P;

int h,w;
char maze[110][110];
const int inf = 1e9;
int dp[110][110];
int dh[4] = {0,0,1,-1};
int dw[4] = {1,-1,0,0};
int sh,sw;
int main() {
    while (cin >> w >> h) {
        if (h == 0 && w == 0) break;
        for (int i = 0; i < h; i++) cin >> maze[i];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dp[i][j] = inf;
                if (maze[i][j] == '&') {
                    sh = i;
                    sw = j;
                }
            }
        }
        bool f = 0;
        priority_queue<P,vector<P>,greater<P>> pq;
        for (int i = 0; i < h; i++) {
            f |= (maze[i][0] == '&');
            f |= (maze[i][w-1] == '&');
            dp[i][0] = (maze[i][0] == '#'?1:0);
            dp[i][w-1] = (maze[i][w-1] == '#'?1:0);
            pq.push({dp[i][0],{i,0}});
            pq.push({dp[i][w-1],{i,w-1}});
        }
        for (int j = 0; j < w; j++) {
            f |= (maze[0][j] == '&');
            f |= (maze[h-1][j] == '&');
            dp[0][j] = (maze[0][j] == '#'?1:0);
            dp[h-1][j] = (maze[h-1][j] == '#'?1:0);
            pq.push({dp[0][j],{0,j}});
            pq.push({dp[h-1][j],{h-1,j}});
        }
        if (f) {
            cout << 0 << endl;
            continue;
        }
        while (!pq.empty()) {
            P tp = pq.top();
            pq.pop();
            int hh = tp.second.first;
            int ww = tp.second.second;
            if (dp[hh][ww] < tp.first) continue;
            for (int i = 0; i < 4; i++) {
                int th = hh + dh[i];
                int tw = ww + dw[i];
                if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                int addd = (maze[hh][ww] == '.') && (maze[th][tw] == '#');
                int dist = dp[hh][ww] + addd;
                if (dist < dp[th][tw]) {
                    dp[th][tw] = dist;
                    pq.push({dp[th][tw],{th,tw}});
                } 
            }
        }
        cout << dp[sh][sw] << endl;
    }    
    return 0;
}