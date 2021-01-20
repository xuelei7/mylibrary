// そろばん


// そろばんを習い始める友人からのお願いで、あなたはそろばんの珠の並び を表示するプログラムを作成することになりました。ある数字を入力として、そろばんの珠の並びを出力するプログラムを作成してください。ただし、表示するそろばんの桁数は 5 桁とし、0 から 9 までの珠の配置はそれぞれ '*' (半角アスタリスク)、' ' (半角空白)、'=' (半角イコール) を用いて以下のように表すものとします。



// Input
// 複数のテストケースが与えられます。各テストケースとして 5 桁までの数字（整数）が １ 行に与えられます。

// テストケースの数は 1024 を超えません。

// Output
// 各テストケースついてそろばんの珠の配置を出力してください。テストケースの間に１行の空行を入れてください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool bg = 1;
    while (cin >> s) {
        if (!bg) cout << endl;
        bg = 0;
        reverse(s.begin(),s.end());
        while (s.size() < 5) s += '0';
        bool maze[5][8] = {};
        for (int i = 0; i < s.size(); i++) {
            int num = s[i] - '0';
            if (num >= 5) maze[i][0] = 1;
            else maze[i][1] = 1;
            maze[i][3 + num % 5] = 1;
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 4; j >= 0; j--) {
                if (i == 2) cout << '=';
                else {
                    cout << (maze[j][i]? ' ': '*');
                }
            }
            cout << endl;
        }
    }
    return 0;
}