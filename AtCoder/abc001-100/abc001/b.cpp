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
    
    int m;
    cin >> m;
    if (m < 100) {
        cout << "00" << endl;
    } else if (m <= 5000) {
        if (m < 1000) {
            cout << "0" << m / 100 << endl;
        } else {
            cout << m / 100 << endl;
        }
    } else if (m <= 30000) {
        cout << m / 1000 + 50 << endl;
    } else if (m <= 70000) {
        cout << (m / 1000 - 30) / 5 + 80 << endl;
    } else {
        cout << 89 << endl;
    }
    
    return 0;
}