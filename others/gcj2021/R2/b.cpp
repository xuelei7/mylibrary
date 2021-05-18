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
vector<int> getPrimeList() {
    const int MAXN = 1000010;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    V<int> v = getPrimeList();

    int t;
    cin >> t;
    rep(i,0,t) {
        int n;
        cin >> n;

        int edge = n;
        for (auto p: v) {
            if (p * p > n) break;
            if (n % p == 0) {
                edge = p;
                break;
            }
        }
        int cnt = 1;
        while (n >= edge * 3) {
            n -= edge;
            edge *= 2;
            cnt++;
        }
        cout << "Case #" << i+1 << ": " << cnt << endl;
    }
    
    return 0;
}