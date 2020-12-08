// 三目並べ
// 三目並べは，３ × ３のマス目の中に交互に ○ と × を入れていき、縦・横・斜めの何れかに一列 ○ か × が並んだときに、勝ちとなるゲームです（図1〜図3 を参照）

		
// 図１：○の勝ち	図２：× の勝ち	図３：引き分け

// 三目並べは、○と×が交互にマス目を埋めていき、どちらかが一列揃ったときにゲーム終了となります。そのため、図 4 のように、○と×が両方とも一列そろっている場合はありえない局面です。ありえない局面が入力されることはありません。


// 図４：ありえない局面

// 三目並べの盤面を読み込んで、勝敗の結果を出力するプログラムを作成して下さい。

// Input
// 入力は複数のデータセットからなります。各データセットとして、盤面を表す１つの文字列が１行に与えられます。 盤面の文字列は、○、×、空白をそれぞれ半角英小文字の o、x、s であらわし、下図のマス目の順に並んでいます。



// データセットの数は 50 を超えません。

// Output
// データセットごとに、○が勝ちなら半角英小文字の o を、×が勝ちなら半角英小文字の x を、引き分けならば半角英小文字の d を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        char maze[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                maze[i][j] = s[i*3+j];
            }
        }
        char ret = 'd';
        for (int i = 0; i < 3; i++) {
            // row
            if (maze[i][0] == maze[i][1] && maze[i][1] == maze[i][2]) {
                if (maze[i][0] != 's') {
                    ret = maze[i][0];
                    break;
                }
            }
            // col
            if (maze[0][i] == maze[1][i] && maze[1][i] == maze[2][i]) {
                if (maze[0][i] != 's') {
                    ret = maze[0][i];
                }
            }
        }
        if (maze[0][0] == maze[1][1] && maze[1][1] == maze[2][2]) {
            if (maze[0][0] != 's') ret = maze[0][0];
        }
        if (maze[0][2] == maze[1][1] && maze[1][1] == maze[2][0]) {
            if (maze[0][2] != 's') ret = maze[0][2];
        }
        cout << ret << endl;
    }
    return 0;
}