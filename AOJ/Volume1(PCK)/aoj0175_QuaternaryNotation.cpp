// ４進数
// 10 進数は現在使われている一般的な記数法で、0、1、2、3、4、5、6、7、8、9 の10 個の記号を用いて全ての数字を表します。

// 2 進数はコンピュータの世界でよく使われる記数法で、0 と1 の二つの記号を用いて全ての数字を表します。

// 4 進数で用いられるのは 0、1、2、3 の 4 つの数字だけです。4 進数では 0 から順に数を増やしていったときに 4 まで来たら次の位に桁上がりします。そのため、10 進数の 4 は桁上がりして「10」という表現になります。

// 10 進数	0	1	2	3	4	5	6	7	8	9	10	...
// 2 進数	0	1	10	11	100	101	110	111	1000	101	1010	...
// 4 進数	0	1	2	3	10	11	12	13	20	21	22	...

// 昔ハワイでは魚やタロイモを指にはさんで数えていたので、10 進数ではなく4 進数を使っていたそうです。

// 10 進数で入力される整数 n を 4 進数に変換し出力するプログラムを作成してください。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりは -1 ひとつの行で示されます。各データセットとして１つの整数 n (0 ≤ n ≤ 1000000) が１行に与えられます。

// データセットの数は 2000 を超えません。

// Output
// 入力データセット毎に 4 進数に変換した結果を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

auto solve (int n) -> void {
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    V<int> v;
    while (n > 0) {
        v.push_back(n % 4);
        n /= 4;
    }

    rrep(i,0,v.size()) {
        cout << v[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n) {
        if (n == -1) break;
        solve(n);
    }
    
    return 0;
}