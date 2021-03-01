// 標高差
// 今まで登ったことのある山の標高を記録したデータがあります。このデータを読み込んで、一番高い山と一番低い山の標高差を出力するプログラムを作成してください。

// Input
// 入力は以下の形式で与えられます。

// 山の高さ
// ...
// ...
// 山の高さが複数行に渡って与えられます。入力される値はすべて 0 以上 1,000,000 以下の実数です。入力される山の高さの数は 50 以下です。

// Output
// 一番高い山と一番低い山の標高差を実数で出力する。出力は0.01以下の誤差を含んでもよい。

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<double> v;
    double n;
    while (cin >> n) {
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    cout << *(v.end() - 1) - *(v.begin()) << endl;
    return 0;
}