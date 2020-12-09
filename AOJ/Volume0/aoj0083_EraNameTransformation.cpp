// 西暦和暦変換
// 西暦で表された年月日を、元号を用いた和暦に変換し、その年月日を出力するプログラムを作成してください。入力は例に示すように 3 つの整数であり、順に西暦年、月、日です。これを、出力例に示すように変換してください。なお、明治以前の年月日が入力された場合は「pre-meiji」と表示してください。

// 各年号の最初の年は「元年」ではなく「１年」と出力することとします。

// 元号	期間
// meiji	1868. 9. 8 〜 1912. 7.29
// taisho	1912. 7.30 〜 1926.12.24
// showa	1926.12.25 〜 1989. 1. 7
// heisei	1989. 1. 8 〜

// 入力
// 複数のデータが与えられます。各データとして年、月、日を表す３つの整数が空白区切りで１行に与えられます。

// 入力の終わりまで処理してください。データの数は 50 を超えません。

// 出力
// 空白区切りの元号、年、月、日、または「pre-meiji」を１行に出力してください。

// to utils

#include <bits/stdc++.h>
using namespace std;

int count_days(int y, int m, int d) {
    int ret = 0;
    for (int i = 1; i < y; i++) {
        if (i % 400 == 0) ret += 366;
        else if (i % 100 == 0) ret += 365;
        else if (i % 4 == 0) ret += 366;
        else ret += 365;
    }
    int cnt[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int i = 1; i < m; i++) {
        ret += cnt[i-1];
    }
    if (m > 2) {
        if (y % 400) ret++;
        else if (y % 100 != 0 && y % 4 == 0) ret++;
    }
    return ret + d;
}

int main() {
    int y,m,d;
    while (cin >> y >> m >> d) {
        int day = f(y,m,d);
        if (day >= f(1989,1,8)) {
            cout << "heisei " << y - 1989 + 1 << " " << m << " " << d << endl;
        } else if (day >= f(1926,12,25)) {
            cout << "showa " << y - 1926 + 1 << " " << m << " " << d << endl;
        } else if (day >= f(1912,7,30)) {
            cout << "taisho " << y - 1912 + 1 << " " << m << " " << d << endl;
        } else if (day >= f(1868,9,8)) {
            cout << "meiji " << y - 1868 + 1 << " " << m << " " << d << endl;
        } else {
            cout << "pre-meiji" << endl;
        }
    }
    return 0;
}