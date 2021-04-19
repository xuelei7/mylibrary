// Problem F: City Merger
// Recent improvements in information and communication technology have made it possible to provide municipal service to a wider area more quickly and with less costs. Stimulated by this, and probably for saving their not sufficient funds, mayors of many cities started to discuss on mergers of their cities.

// There are, of course, many obstacles to actually put the planned mergers in practice. Each city has its own culture of which citizens are proud. One of the largest sources of friction is with the name of the new city. All citizens would insist that the name of the new city should have the original name of their own city at least as a part of it. Simply concatenating all the original names would, however, make the name too long for everyday use.

// You are asked by a group of mayors to write a program that finds the shortest possible name for the new city that includes all the original names of the merged cities. If two or more cities have common parts, they can be overlapped. For example, if "FUKUOKA", "OKAYAMA", and "YAMAGUCHI" cities are to be merged, "FUKUOKAYAMAGUCHI" is such a name that include all three of the original city names. Although this includes all the characters of the city name "FUKUYAMA" in this order, it does not appear as a consecutive substring, and thus "FUKUYAMA" is not considered to be included in the name.

// Input
// The input is a sequence of datasets. Each dataset begins with a line containing a positive integer n (n ≤ 14), which denotes the number of cities to be merged. The following n lines contain the names of the cities in uppercase alphabetical letters, one in each line. You may assume that none of the original city names has more than 20 characters. Of course, no two cities have the same name.

// The end of the input is indicated by a line consisting of a zero.

// Output
// For each dataset, output the length of the shortest possible name of the new city in one line. The output should not contain any other characters.

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

auto solve (int n, V<string>& s) -> int {
    // 含まれるものをのぞく
    V<bool> included(n);
    rep(i,0,n) {
        rep(j,0,n) {
            if (i == j) continue;
            if (s[i].size() > s[j].size()) continue;
            rep(k,0,s[j].size()) {
                if (k+s[i].size() > s[j].size()) break;
                if (s[j].substr(k,s[i].size()) == s[i]) included[i] = true;
            }
        }
    }
    V<string> new_s;
    rep(i,0,n) {
        if (!included[i]) {
            new_s.push_back(s[i]);
        }
    }
    n = new_s.size();
    s = new_s;

    // 共通の長さを探索
    VV<int> len(n,V<int>(n,0));
    rep(i,0,n) {
        string a = s[i];
        rep(j,0,n) {
            if (i == j) continue;
            string b = s[j];
            rrep(k,0,a.size()) {
                if (b.size() < a.size() - k) break;
                string suffix = a.substr(k,a.size()-k);
                string prefix = b.substr(0,a.size()-k);
                dbg(suffix);
                dbg(prefix);
                if (suffix == prefix) {
                    len[i][j] = suffix.size();
                }
            }
        }
    }
#ifdef LOCAL
    rep(i,0,n) {
        rep(j,0,n) {
            cout << s[i] << " " << s[j] << " " << len[i][j] << endl;
        }
    }
#endif

    // 探索
    int inf = 1e9;
    VV<int> dp(1<<n,V<int>(n,inf));
    rep(i,0,n) dp[1<<i][i] = s[i].size();
    rep(i,0,1<<n) { // status
        rep(j,0,n) { // string before
            if (dp[i][j] == inf) continue;
            rep(k,0,n) { // string now
                if ((i>>k)&1) continue;
                dp[i+(1<<k)][k] = min(dp[i+(1<<k)][k], dp[i][j] + (int)s[k].size() - len[j][k]);
            }
        }
    }

    // 結果
    int mi = inf;
    rep(i,0,n) {
        mi = min(mi, dp[(1<<n)-1][i]);
    }
    return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
    V<string> s(n);
    rep(i,0,n) cin >> s[i];
    auto ans = solve(n,s);
    cout << ans << endl;
    }
    return 0;
}