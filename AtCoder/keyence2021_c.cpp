#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
ll h,w,k;
int maze[5010][5010];
ll dp[5010][5010];
int main() {
    cin >> h >> w >> k;
    for (int i = 0; i < k; i++) {
        int hh, ww;
        char c;
        cin >> hh >> ww >> c;
        hh--;
        ww--;
        // X: 1, R: 2, D: 3
        maze[hh][ww] = (c == 'X'? 1: (c == 'R'? 2: 3));
    }
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                if (maze[i][j-1] == 0) {
                    dp[i][j] += dp[i][j-1] * 2;
                } else if (maze[i][j-1] == 1 || maze[i][j-1] == 2) {
                    dp[i][j] += dp[i][j-1];
                }
            } else if (j == 0) {
                if (maze[i-1][j] == 0) {
                    dp[i][j] += dp[i-1][j] * 2;
                } else if (maze[i-1][j] == 1 || maze[i-1][j] == 3) {
                    dp[i][j] += dp[i-1][j];
                }
            } else {
                if (maze[i-1][j] != 0 && maze[i][j-1] != 0) {
                    if (maze[i-1][j] == 1 || maze[i-1][j] == 3) dp[i][j] += dp[i-1][j];
                    if (maze[i][j-1] == 1 || maze[i][j-1] == 2) dp[i][j] += dp[i][j-1];
                } else {
                    if (maze[i-1][j] == 0) dp[i][j] += dp[i-1][j] * 2;
                    else if (maze[i-1][j] == 1 || maze[i-1][j] == 3) dp[i][j] += dp[i-1][j] * 3;
                    if (maze[i][j-1] == 0) dp[i][j] += dp[i][j-1] * 2;
                    else if (maze[i][j-1] == 1 || maze[i][j-1] == 2) dp[i][j] += dp[i][j-1] * 3;
                }
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[h-1][w-1] * (maze[h-1][w-1] == 0 ? 3 : 1) % mod << endl;
    return 0;
}