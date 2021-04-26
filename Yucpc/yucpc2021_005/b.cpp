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
vector<ll> v;
ll ret;

void dfs(string s, int pos) {
    if (pos == s.size()) {
        for (auto e: v) {
            ret += e;
        }
        return;
    }

    for (int i = pos; i < s.size(); i++) {
        ll num;
        stringstream ss(s.substr(pos, i - pos + 1));
        ss >> num;
        v.push_back(num);
        dfs(s, i+1);
        v.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s;
    cin >> s;
    dfs(s, 0);
    cout << ret << endl;
    
    return 0;
}