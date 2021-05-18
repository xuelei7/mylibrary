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
    
    int a,b;
    cin >> a >> b;
    queue<pair<int,int>> q;
    q.push({0,a});
    while (!q.empty()) {
        auto tp = q.front(); q.pop();
        if (tp.second == b) {
            cout << tp.first << endl;
            return 0;
        }
        q.push({tp.first+1, tp.second+1});
        q.push({tp.first+1, tp.second-1});
        q.push({tp.first+1, tp.second+5});
        q.push({tp.first+1, tp.second-5});
        q.push({tp.first+1, tp.second+10});
        q.push({tp.first+1, tp.second-10});
    }
    
    return 0;
}