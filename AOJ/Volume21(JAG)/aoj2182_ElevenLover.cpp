// Problem H: Eleven Lover
// Edward Leven loves multiples of eleven very much. When he sees a number, he always tries to find consecutive subsequences (or substrings) forming multiples of eleven. He calls such subsequences as 11-sequences. For example, he can find an 11-sequence 781 in a number 17819.

// He thinks a number which has many 11-sequences is a good number. He would like to find out a very good number. As the first step, he wants an easy way to count how many 11-sequences are there in a given number. Even for him, counting them from a big number is not easy. Fortunately, one of his friends, you, is a brilliant programmer. He asks you to write a program to count the number of 11-sequences. Note that an 11-sequence must be a positive number without leading zeros.

// Input
// The input is a sequence of lines each of which contains a number consisting of less than or equal to 80000 digits.

// The end of the input is indicated by a line containing a single zero, which should not be processed.

// Output
// For each input number, output a line containing the number of 11-sequences.

// You can assume the answer fits in a 32-bit signed integer.

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

auto solve(string s) -> ll {
    V<int> pre(11,0);
    ll ans = 0;
    rep(i,0,s.size()) {
        V<int> now(11,0);
        if (s[i] != '0') now[s[i] - '0']++;

        rep(j,0,11) {
            now[(j*10+s[i]-'0') % 11] += pre[j];
        }

        rep(j,0,11) pre[j] = now[j];
        ans += pre[0];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s;
    while (cin >> s) {
        if (s == "0") break;
        cout << solve(s) << endl;
    }


    return 0;
}