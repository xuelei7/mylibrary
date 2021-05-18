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

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // constexpr char endl = '\n';
    
    int t = 100, n = 100;
    cin >> t >> n;
    rep(i,0,t) {
        dbg(i);
        rep(j,1,n) {
            cout << "M " << j << " " << n << endl;
            int k;
            cin >> k;
            dbg(k);
            if (k == -1) return 0;


            if (k != j) {
                cout << "S " << j << " " << k << endl;
                cin >> k;
                if (k == -1) return 0;
            }
        }
        cout << "D" << endl;
        
        int k;
        cin >> k;
        if (k == -1) return 0;
    }

    return 0;
}