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
    deque<char> dq;
    bool f = 1;
    for (auto c:s) {
        if (c == 'R') {
            f = !f;
        } else {
            if (f) {
                if (!dq.empty() && dq.back() == c) dq.pop_back();
                else dq.push_back(c);
            } else {
                if (!dq.empty() && dq.front() == c) dq.pop_front();
                else dq.push_front(c);
            }
        }
    }
    
    while (!dq.empty()) {
        if (f) {
            cout << dq.front();
            dq.pop_front();
        } else {
            cout << dq.back();
            dq.pop_back();
        }
    }
    cout << endl;
    return 0;
}