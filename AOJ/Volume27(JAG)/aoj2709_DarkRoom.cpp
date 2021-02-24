
// ログアウト
 
// 登録・設定
// 日本語   英語
// My Statusはじめての方へ    HOME- Volume27-2709
// Tag Discussion Solution Statistics Submit
 
// Dark Room
// 時間制限 : 2 sec, メモリ制限 : 262144 KB
// Japanese
// 真っ暗な部屋
// 目を覚ますと、A君は真っ暗な部屋の中にいた。 どうやらA君は N 個の部屋から構成されたダンジョンに迷い込んでしまったようだ。 あなたはA君がどの部屋に迷い込んだのかを知ることはできなかったが、幸いにもダンジョンのマップを手に入れることができた。 A君の進むべき道を示し明るい部屋に導こう。

// N 個の部屋のうち M 個の部屋が真っ暗な部屋であり、それぞれ D1, D2, ..., DM 番目の部屋が真っ暗な部屋であることが分かっている。 また、全ての部屋からちょうど K 本の一方通行の道が順に並んでおり、i 番目の部屋から出る道はそれぞれ vi,1, vi,2, ..., vi,K 番目の部屋に繋がっている。 あなたは、A君に対し今いる部屋から a1, a2, ..., al 番目の道を順に進ませることができる。 ただし、A君は明るい部屋に到達したらそれ以降の指示は無視する。 あなたは、指示の前後においてA君が今いる部屋の情報を知ることはできないため、A君がどの部屋にいたとしても明るい部屋に辿り着けるような指示列を伝えなければならない。 そのような指示のうち、最も短いものの長さを答えよ。

// Constraints
// 2≤N≤100
// 1≤M≤min(16,N−1)
// 1≤K≤N
// 1≤Di≤N
// Di は全て異なる
// 1≤vi,j≤N
// 全ての暗い部屋は少なくとも1つの明るい部屋に到達可能である
// Input Format
// 入力は以下の形式で標準入力から与えられる。

// N M K
// D1 D2 ... DM
// v1,1 v1,2 ... v1,K
// v2,1 v2,2 ... v2,K
// ...
// vN,1 vN,2 ... vN,K
// Output Format
// 答えを一行に出力せよ。

#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int d[20];
int v[110][110];
int dp[(1<<17)];
int inf = 1e9 + 7;
map<int,int> mp;
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> d[i];
        d[i]--;
        mp[d[i]] = i;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) {
        cin >> v[i][j];
        v[i][j]--;
    }
    for (int i = 0; i < (1<<16); i++) dp[i] = inf;
    queue<int> q;
    dp[(1<<m)-1] = 0;
    q.push((1<<m)-1);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int i = 0; i < k; i++) {
            int ss = 0;
            for (int j = 0; j < m; j++) {
                int to = v[d[j]][i];
                if ((s>>j)&1 && mp.count(to)) {
                    ss |= (1<<mp[to]);
                }
            }
            if (dp[ss] > dp[s] + 1) {
                dp[ss] = dp[s] + 1;
                q.push(ss);
            }
        }
    }

    cout << dp[0] << endl;
}