// ゴールドバッハの予想
// 4 以上の偶数は 2 つの素数の和で表すことができるということが知られています。これはゴールドバッハ予想といい、コンピュータの計算によりかなり大きな数まで正しいことが確かめられています。例えば、10 は、7 + 3、5 + 5 の 2 通りの素数の和で表すことができます。

// 整数 n を入力し、n を 2 つの素数の和で表す組み合わせ数が何通りあるかを出力するプログラムを作成してください。ただし、n は 4 以上、50,000 以下とします。また、入力される n は偶数であるとはかぎりません。

// Input
// 複数のデータセットが与えられます。各データセットに n が１行に与えられます。n が 0 のとき入力の最後とします。データセットの数は 10,000 を超えません。

// Output
// 各データセットに対して、n を 2 つの素数の和で表す組み合わせ数を１行に出力して下さい。

// to number

#include <bits/stdc++.h>
using namespace std;
vector<bool> getPrimeList1() {
    const int MAXN = 1000000;
    vector<bool> isprime(MAXN);
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    return isprime;
}
vector<int> getPrimeList2() {
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
    vector<bool> v1 = getPrimeList1();
    vector<int> v2 = getPrimeList2();
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int cnt = 0;
        for (int i = 0; i < v2.size() && v2[i] <= n / 2; i++) {
            cnt += v1[n - v2[i]];
        }
        cout << cnt << endl;
    }
    return 0;
}