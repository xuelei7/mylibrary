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

auto solve () -> int {
    map<int,int> mp;
    int n;
    cin >> n;
    rep(i,0,n) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int cnt = 1;
    int ans = 0;
    for (auto e: mp) {
        ans += cnt * e.second;
        cnt++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,1,t+1) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    
    return 0;
}