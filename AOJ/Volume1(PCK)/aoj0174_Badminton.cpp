// バドミントン
// A君、Bさん、C君で久しぶりに遊ぶことになりました。 A君とBさんがプレイヤー、C君が審判になりバドミントンのシングルスのゲームをしました。3人で決めたルールは以下の通りです。

// 3 ゲームを行います。
// 11 点を先取した人が、そのゲームの勝者となります。
// 第 1 ゲームの最初のサーブはA君から始まりますが、次のサーブは直前のポイントを取った人が行います。
// 第 2 ゲーム、第 3 ゲームは前のゲームを取った人が最初のサーブを行います。
// 10 - 10 になって以降は 2 点差をつけた人が勝者となります。
// 全てのゲームが終わり、得点を見ようとしたのですが、審判のC君が得点を記録するのを忘れていました。しかし、サーブを打った人をきちんと記録していました。サーブ順の記録から得点を計算するプログラムを作成してください。ただし、二人が打ったサーブの回数の合計は 100 以下とし、サーブ順の記録は、サーブを打った人を表す "A" または "B" の文字列で表されます。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されま す。各データセットは以下の形式で与えられます。

// record1
// record2
// record3
// i 行目に第 i ゲームのサーブ順を表す文字列が与えられます。

// データセットの数は 20 を超えません。

// Output
// データセット毎に、i 行目に第 i ゲームのA君の得点とBさんの得点を空白区切りで出力してください。

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

auto solve (string s) -> void {
    int n = s.size();
    int score[2] = {};

    rep(i,1,n) {
        score[s[i]-'A']++;
    }

    if (score[0] > score[1]) {
        score[0]++;
    } else {
        score[1]++;
    }

    cout << score[0] << " " << score[1] << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s;
    while (cin >> s) {
        if (s == "0") break;
        solve(s);
    }
    
    return 0;
}