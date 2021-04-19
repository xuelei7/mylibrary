// Problem C:Champernowne Constant
// Champernown constant is an irrational number represented in decimal by "0." followed by concatenation of all positive integers in the increasing order. The first few digits of this constant are: 0.123456789101112...

// Your task is to write a program that outputs the K digits of Chapnernown constant starting at the N-th place for given two natural numbers K and N.

// Input
// The input has multiple lines. Each line has two positive integers N and K (N ≤ 109, K ≤ 100) separated by a space.

// The end of input is indicated by a line with two zeros. This line should not be processed.

// Output
// For each line, output a line that contains the K digits.

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

// 数字の開始場所を返す
ll digit(ll num) {
    ll digit = log10(num) + 1;
    if (digit == 1) return num;
    ll sum = 0;
    ll increase = 9;
    rep(i,0,digit-1) {
        sum += increase * (i+1);
        increase *= 10;
    }
    increase /= 9;
    return sum + digit * (num - increase) + 1;
}

char get_digit(int k) {
    if (k < 10) return (char)(k + '0');
    // 二分探索でkを含む数字を探す
    ll l = 1, r = 1e9;
    ll bg;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        // 開始する桁がk以下である
        ll tmp = digit(mid);
        if (tmp <= k) {
            l = mid;
            bg = tmp;
        } else r = mid - 1;
    }
    
    string s = to_string(l);
    return s[k-bg];
}

auto solve (int n, int k) -> string {
    // 桁ごとを計算する
    string ret = "";
    rep(i,0,k) ret += get_digit(n+i);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n,k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;

        // solve
        auto ans = solve(n,k);

        // output
        cout << ans << endl;
    }

    return 0;
}