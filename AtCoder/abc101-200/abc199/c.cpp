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
    
    int n;
    cin >> n;
    string str;
    cin >> str;
    string s[2] = {str.substr(0,n), str.substr(n,n)};
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a,b;
            cin >> a >> b;
            a--; b--;
            if (b < n) {
                swap(s[0][a], s[0][b]);
            } else if (a >= n) {
                swap(s[1][a-n], s[1][b-n]);
            } else {
                swap(s[0][a], s[1][b-n]);
            }
        } else {
            int a,b;
            cin >> a >> b;
            swap(s[0], s[1]);
        }
    }
    cout << s[0] << s[1] << endl;
    return 0;
}