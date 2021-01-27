// マス目
// n×n のマス目にそれぞれ 1 か 0 が書いてあります。この情報を入力とし、上下、左右、または、対角線方向に並んだ 1 の列のうち、最大のものの長さを出力するプログラムを作成してください。

// 例えば、下の図で一番長いのは点線で囲まれた列です。



// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下のとおりです。

// n
// line1
// line2
// :
// linen
// １行目にマス目の大きさ n（2 ≤ n ≤ 255）が与えられます。続く n 行に、i 行目のマス目の情報を表す n 文字の文字列 linei （1と0だけを含む）が与えられます。

// データセットの数は 200 を超えません。

// Output
// 入力データセットごとに列の長さの最大値（整数）を１行に出力します。

#include <bits/stdc++.h>
using namespace std;
bool maze[300][300];
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                maze[i][j] = (s[j]=='1'?1:0);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (maze[i][j]) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (maze[i][j]) {
                    cnt++;
                    ans = max(ans,cnt);
                } else {
                    cnt = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i <= j; i++) {
                if (maze[i][j-i]) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }
            cnt = 0;
            for (int i = 0; i < n-j; i++) {
                if (maze[i][j+i]) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i <= j; i++) {
                if (maze[n-i-1][j-i]) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }
            cnt = 0;
            for (int i = 0; i < n-j; i++) {
                if (maze[n-i-1][j+i]) {
                    cnt++;
                    ans = max(ans, cnt);
                } else {
                    cnt = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}