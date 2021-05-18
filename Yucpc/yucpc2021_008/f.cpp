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
    
    ll n,d;
    cin >> n >> d;
    V<pair<ll,ll>> a(n);
    rep(i,0,n) {
        cin >> a[i].first >> a[i].second;
    }

    ll na = (n + 1) / 2;
    ll nb = n - na;
    ll ret = 0;
    V<pair<ll,ll>> va, vb;
    rep(i,0,pow(3,na)) {
        int tmp = i;
        pair<ll,ll> p = {};
        rep(j,0,na) {
            int k = tmp % 3;
            tmp /= 3;
            if (k == 0) {
                p.first += a[j].first;
                p.second += a[j].second;
            } else if (k == 1) {
                p.first -= a[j].first;
                p.second -= a[j].second;
            }
        }
        va.push_back(p);
        if (abs(p.first) <= d)
            ret = max(ret, p.second);
    }
    rep(i,0,pow(3,nb)) {
        int tmp = i;
        pair<ll,ll> p = {};
        rep(j,na,n) {
            int k = tmp % 3;
            tmp /= 3;
            if (k == 0) {
                p.first += a[j].first;
                p.second += a[j].second;
            } else if (k == 1) {
                p.first -= a[j].first;
                p.second -= a[j].second;
            }
        }
        vb.push_back(p);
        if (abs(p.first) <= d)
            ret = max(ret, p.second);
    }
    
    sort(all(va));
    reverse(all(va));
    sort(all(vb));

    // merge
    na = va.size(); nb = vb.size();
    deque<ll> dqid, dqval;
    int pos = 0;
    rep(i,0,na) {
        // push_back
        while (pos < nb && vb[pos].first + va[i].first <= d) {
            ll val = vb[pos].second;
            while (!dqval.empty() && dqval.back() <= val) {
                dqval.pop_back();
                dqid.pop_back();
            }
            dqval.push_back(val);
            dqid.push_back(pos);
            pos++;
        }
        // pop_front
        while (!dqid.empty() && vb[dqid.front()].first + va[i].first < -d) {
            dqval.pop_front();
            dqid.pop_front();
        }
        if (!dqval.empty()) {
            ret = max(ret, va[i].second + dqval.front());
        }
    }

    cout << ret << endl;
    return 0;
}