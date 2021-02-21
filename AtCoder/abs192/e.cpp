#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1e18;
ll n,m,x,y;
vector<pair<ll,pair<ll,ll>>> G[100010];
ll d[100010];

int main() {
    cin >> n >> m >> x >> y;
    for (int i = 0; i < 100010; i++) d[i] = inf;
    for (int i = 0; i < m; i++) {
        ll frm,to,t,k;
        cin >> frm >> to >> t >> k;
        G[frm].push_back({to,{t,k}});
        G[to].push_back({frm,{t,k}});
    }
    d[x] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,x});
    while (!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        if (tp.first < d[tp.second]) continue;
        ll t = tp.first;
        for (int i = 0; i < G[tp.second].size(); i++) {
            auto nxt = G[tp.second][i];
            ll id = nxt.first;
            ll tt = nxt.second.first;
            ll kk = nxt.second.second;
            ll time = t / kk * kk + (t % kk != 0) * kk;
            if (time + tt < d[id]) {
                d[id] = time + tt;
                pq.push({d[id],id});
            }
        }
    }
    // for (int i = 1; i <= n; i++) cout << d[i] << " ";
    // cout << endl;
    if (d[y] == inf) cout << -1 << endl;
    else cout << d[y] << endl;
}