// 双子素数
// 素数は暗号、符号、通信、計測などに広く利用されています。素数の中でも「5 と 7」「11 と 13」のような差が 2 となる素数の組を双子素数と言います。双子素数を構成する素数のうち大きい素数をその双子素数の大きさと呼ぶことにします。 入力された整数 n 以下の双子素数で大きさが最大のものを出力するプログラムを作成してください。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。各データセットとして、整数n (5 ≤ n ≤ 10000) が１行に与えられます。

// データセットの数は 10000 を超えません。

// Output
// データセットごとに、n に対する双子素数 p1、 q1 を空白区切りで出力してください。ここで、p1 を双子素数を構成する小さい素数、q1 を双子素数を構成する大きい素数とします。

// from util

#include <bits/stdc++.h>
using namespace std;
vector<int> getPrimeList() {
    const int MAXN = 100000;
    bool isprime[MAXN];
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    vector<int> v;
    for (int i = 2; i < MAXN; i++) if (isprime[i]) v.push_back(i);
    return v;
}
int main() {
    vector<int> v = getPrimeList();
    vector<int> vv;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i+1]-v[i] == 2) vv.push_back(v[i+1]);
    }
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int num = *(upper_bound(vv.begin(),vv.end(),n)-1);
        cout << num - 2 << " " << num << endl;
    }
    return 0;
}