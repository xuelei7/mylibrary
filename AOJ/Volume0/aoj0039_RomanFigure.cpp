// ローマ数字
// 古代ローマでは数を数えることは難しい仕事でした。アラビア数字の 0,1,2,3,…, 9 はまだ流布していませんでした。その代わり次のような記号が使われていました。

// アラビア数字	ローマ数字	アラビア数字	ローマ数字	アラビア数字	ローマ数字
// 1	I	11	XI	30	XXX	
// 2	II	12	XII	40	XL	
// 3	III	13	XIII	50	L	
// 4	IV	14	XIV	60	LX	
// 5	V	15	XV	70	LXX	
// 6	VI	16	XVI	80	LXXX	
// 7	VII	17	XVII	90	XC	
// 8	VIII	18	XVIII	100	C	
// 9	IX	19	XIX	500	D	
// 10	X	20	XX	1000	M	

// I は 1、 V は 5、 X は 10、 L は 50、 C は 100、 D は 500、 M は 1000、 他の例は上の表を見てください。小さい数が大きい数に続いている、つまり右側にあるときは足し算をします。小さい数が大きい数の前に、つまり左にあるときは、大きい数から小さい数を引きます。大きい数字の前にあって引き算を表す小さな数字は一回の引き算あたりひとつしかありません。

// ローマ数字をアラビア数字（通常の数字）の表記（10 進表示）に変換して出力するプログラムを作成してください。ただし、与えられるローマ数字は上記のルールにのみ従っています(実際のローマ数字の表記にはもっと細かいルールがありますが、ここでは考慮する必要はありません。たとえば、実際のローマ数字ではI はV かX から、X はL かC から、C はD かM からしか引き算しませんし、同じローマ数字は４つ以上（または５つ以上）足し並べることはありません。)

// Input
// 複数のデータセットが与えられます。それぞれのデータセットにローマ数字（半角大文字のI, V, X, L, C, D ,M で表される連続した文字列）が１行に与えられます。与えられるローマ数字の文字列の長さはおのおの 100 以下です。

// データセットの数は 50 を超えません。

// Output
// 各データセットに対し、アラビア数字（整数）を１行に出力して下さい。

// to utils

#include <bits/stdc++.h>
using namespace std;

int roman_figure(string s) {
    int ans = 0, biggest = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        int now ;
        if (s[i] == 'I') now = 1;
        else if (s[i] == 'V') now = 5;
        else if (s[i] == 'X') now = 10;
        else if (s[i] == 'L') now = 50;
        else if (s[i] == 'C') now = 100;
        else if (s[i] == 'D') now = 500;
        else if (s[i] == 'M') now = 1000;
        if (now >= biggest) {
            biggest = now;
            ans += now;
        } else {
            ans -= now;
        }
    }
    return ans;
}

int main() {
    string s;
    while (cin >> s) {
        cout << roman_figure(s) << endl;
    }
    return 0;
}