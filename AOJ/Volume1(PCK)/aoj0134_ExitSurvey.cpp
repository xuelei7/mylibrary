// 出口調査
// あるデパートで買い物金額の出口調査を行いました。買い物金額のデータを入力とし、1 人あたりの平均買い物金額を計算し、出力するプログラムを作成してください。調査人数は、10 万人以下とし、一人あたりの買い物金額は 100 万円を超えないものとします。

// Input
// 入力は以下の形式で与えられます。

// n
// v1
// v2
// :
// vn
// 1 行目に調査人数 n、続く n 行に i 人目の買い物金額を表す整数 vi が与えられます。

// Output
// 平均買い物金額（整数：小数点以下は切り捨て）を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
    }
    cout << sum / n << endl;
    return 0;
}