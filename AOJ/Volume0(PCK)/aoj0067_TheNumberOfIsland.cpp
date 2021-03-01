// 島の数
// 地勢を示す縦 12, 横 12 のマスからなる平面図があります。おのおののマスは白か黒に塗られています。白は海を、黒は陸地を表します。二つの黒いマスが上下、あるいは左右に接しているとき、これらは地続きであるといいます。この平面図では、黒いマス一つのみ、あるいは地続きの黒いマスが作る領域を「島」といいます。例えば下図には、5 つの島があります。

// ■■■■□□□□■■■■
// ■■■□□□□□■■■■
// ■■□□□□□□■■■■
// ■□□□□□□□■■■■
// □□□■□□□■□□□□
// □□□□□□■■■□□□
// □□□□□■■■■■□□
// ■□□□■■■■■■■□
// ■■□□□■■■■■□□
// ■■■□□□■■■□□□
// ■■■■□□□■□□□□
// □□□□□□□□□□□□
// マスのデータを読み込んで、島の数を出力するプログラムを作成してください。

// Input
// 入力は複数のデータセットからなります。各データセットに１つの平面図が与えられます。黒いマスを 1、白いマスを 0 で表現した 12 個の数字の列 12 行でひとつの平面図を表します。データセットの間は１つの空行で区切られています。

// データセットの数は 20 を超えません。

// Output
// データセットごとに、島の数を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

char maze[12][12];
bool used[12][12];
int dh[4] = {0,0,1,-1};
int dw[4] = {1,-1,0,0};
void dfs(int h, int w) {
    used[h][w] = 1;
    for (int i = 0; i < 4; i++) {
        int th = h + dh[i];
        int tw = w + dw[i];
        if (th < 0 || th >= 12 || tw < 0 || tw >= 12) continue;
        if (maze[th][tw] == '0') continue;
        if (used[th][tw]) continue;
        dfs(th,tw);
    }
}

int main() {
    string s;
    int row = 0;
    while (getline(cin,s)) {
        if (s.size() == 0) continue;
        if (row < 12) {
            for (int i = 0; i < 12; i++) maze[row][i] = s[i];
            row++;
        }
        if (row < 12) continue;
        row = 0;
        int ans = 0;
        for (int i = 0; i < 12; i++) memset(used[i],0,sizeof(used[i]));
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (used[i][j] || maze[i][j] == '0') continue;
                ans++;
                dfs(i,j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}