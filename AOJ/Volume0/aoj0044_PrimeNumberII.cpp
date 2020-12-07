// 素数 II
// 素数というのは、1 よりも大きくそれ自身か 1 でしか割りきれない整数をいいます。例えば、2 は、2 と 1 でしか割り切れないので素数ですが、12 は、12 と 1 のほかに、2, 3, 4, 6 で割りきれる数なので素数ではありません。

// 整数 n を入力したとき、n より小さい素数のうち最も大きいものと、n より大きい素数のうち最も小さいものを出力するプログラムを作成してください。

// Input
// 複数のデータセットが与えられます。各データセットに n (3 ≤ n ≤ 50,000) が１行に与えられます。

// データセットの数は 50 を超えません。

// Output
// 各データセットに対して、n より小さい素数のうち最大のものと、n より大きい素数のうち最小のものを１つのスペースで区切って１行に出力して下さい。
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
    int n;
    while (cin >> n) {
        cout << *(upper_bound(v.begin(),v.end(),n-1) - 1) << " " << *lower_bound(v.begin(),v.end(),n+1) << endl;
    }
    return 0;
}