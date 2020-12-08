// 爆弾の連鎖
// 縦 8、横 8 のマスからなる図1 のような平面があります。その平面上に、いくつかの爆弾が置かれています。図2 にその例を示します（● = 爆弾）。

// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	●	□	□	●	□
// □	□	□	□	□	●	□	□
// ●	□	□	□	●	□	□	●
// □	□	●	□	□	□	●	□
// □	●	□	□	□	□	□	□
// □	□	□	□	●	□	□	□
// ●	□	●	□	□	□	●	□
// □	●	□	●	□	□	●	□
// 図1	図2

// 爆弾が爆発すると、その爆弾の上下左右 3 マスに爆風の影響が及び、それらのマスに置かれている爆弾も連鎖的に爆発します。たとえば、図 3 に示す爆弾が爆発すると図 4 の■のマスに爆風の影響が及びます。

// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	●	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	□	□	□	□	□
// □	□	□	■	□	□	□	□
// □	□	□	■	□	□	□	□
// □	□	□	■	□	□	□	□
// ■	■	■	●	■	■	■	□
// □	□	□	■	□	□	□	□
// □	□	□	■	□	□	□	□
// 図3	図4

// 爆弾が置かれている状態と最初に爆発する爆弾の位置を読み込んで、最終的な平面の状態を出力するプログラムを作成してください。

// Input
// 入力は以下の形式で与えられます。

// n
// （空行）
// データセット 1
// （空行）
// データセット 2
// ..
// ..
// データセット n
// １行目にデータセットの数 n (n ≤ 20) が与えられます。続いて n 個のデータセットが与えられます。各データセットの直前に１つの空行が与えられます。各データセットは以下の形式で与えられます。

// g1,1g2,1...g8,1
// g1,2g2,2...g8,2
// :
// g1,8g2,8...g8,8
// X
// Y
// 最初の８行に、平面を表す８つの文字列が与えられます。各文字列は８文字からなる数列で、爆弾が置かれているマスを 1、置かれていないマスを 0 で表します。 続く２行で、最初に爆発する爆弾の X 座標と Y 座標が与えられます。左上、左下、右上、右下の座標が、それぞれ、(1, 1)、(1, 8)、(8, 1)、(8, 8) です。例えば、図 4 に示す爆弾が最初に爆発するとき、与えられる座標は (4, 6) です。

// Output
// 各データセットについて以下のように出力して下さい。

// 爆発しないで残った爆弾のあるマスを 1、爆弾のないマスを 0 で表現することとします。平面の一行を数字 8 個からなる一行とし 8 行の文字列で最終的な平面の状態を出力してください。各データセットの先頭は、サンプル出力のように Data x: から出力しなければなりません。ここで、x はデータセットの番号です。

#include <bits/stdc++.h>
using namespace std;
char maze[8][8];
int n;
int x,y;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
void f(int xx, int yy) {
    maze[xx][yy] = '0';
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 4; j++) {
            int tx = xx + dx[j] * i;
            int ty = yy + dy[j] * i;
            if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8) continue;
            if (maze[tx][ty] == '0') continue;
            f(tx,ty);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        for (int i = 0; i < 8; i++) {
            cin >> s;
            for (int j = 0; j < 8; j++) maze[i][j] = s[j];
        }
        cin >> x >> y;
        f(y-1,x-1);
        cout << "Data " << i << ":" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) cout << maze[i][j];
            cout << endl;
        }
    }
    return 0;
}