// 整数の差
// 8 個の 0 から 9 までの数字を入力したとき、その 8 個の数字を並べ替えてできる、最大の整数と最小の整数の差を出力するプログラムを作成してください。並び替えてできる数は 00135569 のように 0 から始まってもよいものとします。

// Input
// 複数のデータセットが与えられます。１行目にデータセット数 n (n ≤ 50) が与えられます。続いて n 行のデータが与えられます。各データは 8 個の数字の並び（0 から 9 の数字）です。

// Output
// 各データセットに対して、入力された数字を並べ替えてできる最大の整数と最小の整数の差を１行に出力して下さい。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        int a = stoi(s);
        reverse(s.begin(),s.end());
        int b = stoi(s);
        cout << b - a << endl;
    }
    return 0;
}