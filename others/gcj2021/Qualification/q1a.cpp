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

auto solve (int n, V<int>& v) -> int {
    int ans = 0;
    rep(i,0,n-1) {
        int pos = i;
        rep(j,i+1,n) {
            if (v[j] < v[pos]) {
                pos = j;
            }
        }
        ans += pos - i + 1;
        reverse(v.begin() + i, v.begin() + pos + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(test_case,1,t+1) {
        int n;
        cin >> n;
        V<int> v(n);
        rep(i,0,n) cin >> v[i];
        cout << "Case #" << test_case << ": " << solve(n,v) << endl;
    }
    
    return 0;
}