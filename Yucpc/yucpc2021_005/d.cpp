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
    string s;
    cin >> n >> s;

    stack<char> stk;
    rep(i,0,n) {
        if (s[i] == ')' && !stk.empty() && stk.top() == '(') {
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }
    int a = 0, b = 0;
    while (!stk.empty() && stk.top() == '(') {
        b++;
        stk.pop();
    }
    while (!stk.empty() && stk.top() == ')') {
        a++;
        stk.pop();
    }
    rep(i,0,a) {
        cout << "(";
    }
    cout << s;
    rep(i,0,b) {
        cout << ")";
    }
    cout << endl;
    return 0;
}