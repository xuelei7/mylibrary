// p(i) を小さい方から i 番目の素数とします。例えば、7 は、2, 3, 5, 7 と小さい方から 4 番目の素数なので、p(4)=7 です。

// n が与えられたとき、i=1 から n までの p(i) の和 s

// s=p(1)+p(2)+ .... +p(n)

// を出力するプログラムを作成してください。例えば、n=9 のとき、s=2+3+5+7+11+13+17+19+23=100 となります。

// Input
// 複数のデータセットが与えられます。各データセットに整数 n (n ≤ 10000) が与えられます。n が 0 のとき入力の最後とします。データセットの数は 50 を超えません。

// Output
// 各データセットの n に対して、s を１行に出力して下さい。

// from number

#include <bits/stdc++.h>
using namespace std;
vector<int> getPrimeList() {
    const int MAXN = 1000000;
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
    for (int i = 1; i < v.size(); i++) v[i] += v[i-1];
    int n;
    while (cin >> n) {
        if (n == 0) break;
        cout << v[n-1] << endl;
    }
    return 0;
}