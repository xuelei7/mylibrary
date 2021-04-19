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

int ad(string& a, string b) {
    int ret = 0;
    if (b.size() > a.size()) {
        a = b;
        return 0;
    }
    if (b.size() == a.size()) {
        if (a < b) {
            a = b;
            return 0;
        } else {
            a = b + '0';
            return 1;
        }
    }

    int n = a.size(), m = b.size();
    
    int sizeup = 0;
    rep(i,0,m) {
        if (a[i] == b[i]) continue;
        if (a[i] > b[i]) { // size goes up
            sizeup = 1;
            break;
        }
        if (b[i] > a[i]) { // make b the same size as a by adding 0s
            while (b.size() < a.size()) {
                b.push_back('0');
                ret++;
            }
            a = b;
            return ret;
        }
    }

    // substr(a,0,b.size()) == b
    if (!sizeup) {
        bool all9 = 1;
        rep(i,m,n) {
            if (a[i] != '9') {
                all9 = 0;
                break;
            }
        }
        if (all9) {
            sizeup = 1;
        } else { // make b the same size as a and add 1
            rep(i,m,n) {
                b.push_back(a[i]);
                ret++;
            }
            b[b.size() - 1]++;
            bool up = (b[b.size() - 1] > '9');
            int pos = b.size() - 1;
            while (up) {
                b[pos] -= 10;
                pos--;
                b[pos]++;
                up = (b[pos] > '9');
            }

            a = b;
            return ret;
        }
    }

    // sizeup
    assert(sizeup == 1);
    while (b.size() <= a.size()) {
        b.push_back('0');
        ret++;
    }
    
    a = b;
    return ret;
}

auto solve () -> int {
    int n;
    cin >> n;
    V<string> v(n);
    rep(i,0,n) cin >> v[i];

    int ans = 0;
    string pre = v[0];

    rep(i,1,n) {
        ans += ad(pre, v[i]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,0,t) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    
    return 0;
}