// パターンの回転
// 8 文字 × 8 行のパターンを右回りに 90 度、180 度、270 度回転させて出力するプログラムを作成してください。

// Input
// 8 文字 × 8 行からなるパターンが与えられます。文字は、英数字、半角シャープ '#' 、アスタリスク '*' からなります。

// Output
// 次の形式で、回転させたパターンを出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    char p[4][8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> p[0][i][j];
        }
    }
    int a[3] = {90,180,270};
    for (int cnt = 0; cnt < 3; cnt++) {
        cout << a[cnt] << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                p[cnt+1][j][8-i-1] = p[cnt][i][j];
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << p[cnt+1][i][j];
            }
            cout << endl;
        }
    }
    return 0;
}