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
    
    V<bool> v(24*60/5);
    
    int n;
    cin >> n;
    rep(i,0,n) {
        int a,b,c,d;
        scanf("%02d%02d-%02d%02d", &a, &b, &c, &d);
        a = a * 60 + b;
        b = c * 60 + d;
        while (a % 5 != 0) a--;
        while (b % 5 != 0) b++;
        a /= 5;
        b /= 5;
        rep(i,a,b) {
            v[i] = 1;
        }
    }

    int pre = -1;
    rep(i,0,24*60/5) {
        if (v[i]) {
            if (pre == -1) {
                pre = i;
            }
        } else {
            if (pre != -1) {
                int t = pre * 5;
                int h = t / 60;
                int m = t % 60;

                int e = i * 5;
                printf("%02d%02d-%02d%02d\n",h,m,e/60,e%60);
                pre = -1;
            }
        }
    }
    if (pre != -1) {
        int t = pre * 5;
        int h = t / 60;
        int m = t % 60;

        int e = 24*60;
        printf("%02d%02d-%02d%02d\n",h,m,e/60,e%60);
    }
    return 0;
}