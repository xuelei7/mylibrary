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
    
    string s;
    cin >> s;
    int a[4];
    rep(i,0,4) a[i] = s[i] - '0';

    rep(op1,0,2) {
        int num1 = a[0] + a[1] * (op1? 1:-1);
        rep(op2,0,2) {
            int num2 = num1 + a[2] * (op2? 1:-1);
            rep(op3,0,2) {
                int num3 = num2 + a[3] * (op3? 1:-1);
                if (num3 == 7) {
                    cout << a[0];
                    cout << (op1? '+':'-');
                    cout << a[1];
                    cout << (op2? '+':'-');
                    cout << a[2];
                    cout << (op3? '+':'-');
                    cout << a[3];
                    cout << "=7" << endl;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}