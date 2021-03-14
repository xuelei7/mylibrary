// 短歌数
// 願はくは 花の下にて 春死なむ そのきさらぎの 望月のころ

// これは，西行法師が詠んだとされる，有名な短歌の一つである． 短歌は，日本において古くから親しまれている和歌の一種であり，その多くは 5・7・5・7・7 の五句三十一音からなる．

// ところで，57577 という数は，5 と 7 の二種類の数字からなる． このような，十進表記がちょうど二種類の数字からなる正の整数を，短歌数と呼ぶことにする． 例えば，10, 12, 57577, 25252 などは短歌数であるが，5, 11, 123, 20180701 などは短歌数ではない．

// 正の整数 N が与えられる．N 番目に小さい短歌数を求めよ．

// Input
// 入力は最大で 100 個のデータセットからなる．各データセットは次の形式で表される．

// N
// 整数 N は 1 ≤ N ≤ 1018 を満たす．

// 入力の終わりは 1 つのゼロからなる行で表される．

// Output
// 各データセットについて，N 番目に小さい短歌数を 1 行に出力せよ．

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

auto solve (ll N) -> string {

    // それぞれのnについて桁->先頭の感じで探す

    ll sum = 0;
    
    // 桁数を決める
    ll keta = 2;
    while (1) {
        ll ad = 81 * ((1LL<<(keta-1)) - 1);
        if (sum + ad >= N) break;
        sum += ad;
        keta++;
    }

    // 先頭数字を決める
    ll num1 = 1;
    while (1) {
        ll ad = 9 * ((1LL<<(keta-1)) - 1);
        if (sum + ad >= N) break;
        sum += ad;
        num1++;
    }

    string ret = to_string(num1);

    // 第二の数字を決める
    ll num2 = 0;
    keta--;
    while (1) {
        if (num2 == num1) {
            // 全部同じ数字
            if (keta - 1 == 0) {
                num2++;
                continue;
            }

            // 次の桁を見る
            ll ad = 9 * ((1LL<<(keta-1)) - 1);
            if (sum + ad >= N) { // 桁確定
                ret += to_string(num2);
                keta--;
                num2 = 0;
                continue;
            } else {
                sum += ad;
                num2++;
            }
        }

        else if (num2 != num1) {
            ll ad = 1LL<<(keta-1);
            if (sum + ad >= N) {
                ret += to_string(num2);
                keta--;
                break;
            } else {
                sum += ad;
                num2++;
            }
        }
    }

    dbg(ret);
    
    // 残りを決める
    if (num1 > num2) swap(num1, num2);
    while (keta) {
        ll ad = 1LL << (keta-1);
        if (sum + ad >= N) {
            ret += to_string(num1);
        } else {
            sum += ad;
            ret += to_string(num2);
        }
        keta--;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    ll n;
    while (cin >> n) {
        if (n == 0) break;
        auto ans = solve(n);
        cout << ans << endl;
    }
    return 0;
}