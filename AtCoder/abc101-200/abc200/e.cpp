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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    ll n,k;
    cin >> n >> k;

    ll before_cnt = 0;
    rep(sum,3,n*3+1) {
        ll free = sum - 3;
        ll posibility = 0;
        if (sum - 2 * n > 0) {
            
        }
        if (before_cnt + posibility < k) {
            before_cnt += posibility;
            continue;
        }
        rep(i,1,sum-2+1) {
            ll free1 = sum - i - 2;
            ll sum1 = sum - i;
            ll posibility1 = 0;
            if (sum1 - 1 <= n) {
                posibility1 = sum1 - 1;
            } else if (sum1 <= 2 * n) {
                posibility1 = 2 * n - sum1 + 1;
            }
            if (before_cnt + posibility1 < k) {
                before_cnt += posibility1;
                continue;
            }
            ll left = k - before_cnt;
            cout << sum << " " << i << " " << left << " " << sum - i - left << endl;
            return 0;
        }
    }
    
    return 0;
}