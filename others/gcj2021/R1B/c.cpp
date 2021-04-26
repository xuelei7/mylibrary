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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // constexpr char endl = '\n';
    
    int t,n,b,p;
    cin >> t >> n >> b >> p;
    while (t--) {
        // cout << "Case" << endl;
        int l = 0, r = n/2;
        int left_tower = n;
        V<int> cnt(n);
        // first 1/4
        rep(i,0,n/2) {
            rep(j,0,b/2) {
                int k;
                cin >> k;
                if (k == -1) return 0;
                cout << i+1 << endl;
                cnt[i]++;
            }
        }

        rep(i,0,n*b-(n/2)*(b/2)) {
            int k;
            cin >> k;
            if (k == -1) return 0;
            if (k >= 5) {
                cout << l+1 << endl;
                cnt[l]++;
                while (cnt[l] == b) l++;
            } else {
                r = -1;
                rep(j,n/2,n) {
                    if (cnt[j] < b/2) {
                        r = j;
                        break;
                    }
                }
                int mi = 1e9;
                if (r == -1) {
                    rrep(j,0,n) {
                        if (cnt[j] < mi) {
                            mi = cnt[j];
                            r = j;
                        }
                    }
                }
                cout << r+1 << endl;
                cnt[r]++;
            }
        }
    }
    int judge;
    cin >> judge;
    return judge;
}