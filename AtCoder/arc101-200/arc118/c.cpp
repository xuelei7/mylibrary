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
    const int MAXN = 10000;
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
    
    int n;
    cin >> n;
    V<int> v = getPrimeList();

    int pos = 3;
    V<int> ans;
    ans.push_back(2*3);
    ans.push_back(2*5);
    ans.push_back(3*5);
    ans.push_back(2*3*5);
    
    // add elements
    while (1) {
        int sz = ans.size();
        bool change = 0;
        rep(i,0,sz) {
            if (ans[i] * v[pos] <= 10000) {
                ans.push_back(ans[i] * v[pos]);
                change = 1;
            }
        }
        if (!change) break;
        pos++;
    }

    // add amount of each element
    int sz = ans.size();
    rep(i,0,sz) {
        V<int> vv;
        rep(j,0,v.size()) {
            if (ans[i] % v[j] == 0) vv.push_back(v[j]);
        }

        auto dfs = [&](auto self, int k, int num) -> void {
            if (k == vv.size()) {
                if (num != ans[i])
                    ans.push_back(num);
                return;
            }

            while (num <= 10000) {
                self(self, k+1, num);
                num *= vv[k];
            }
            return;
        };

        dfs(dfs,0,ans[i]);
    }
    // cout << ans.size() << endl;
    rep(i,0,n) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}