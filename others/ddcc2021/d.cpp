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

auto solve (V<int>& b, V<int>& p) -> int {
    // score
    V<int> score(1<<10),need(1<<10),number(1<<10);
    rep(i,0,(1<<10)) {
        rep(j,0,10) {
            if ((i>>j)&1) {
                score[i] += p[j];
                need[i] += b[j];
                number[i]++;
            }    
        }
    }
    
    int ans = 10;
    // status, 残り弾数が可能か
    VV<bool> dp(1<<10, V<bool>(110));
    
    // 点数を返す
    auto shoot = [&](int sa, int sb, int& new_s) -> int {
        
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,10});
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        if (dp[tp.first][tp.second]) continue;
        dp[tp.first][tp.second] = 1;

        int left = tp.second;

        rep(i,0,1<<10) {
            if (i&tp.first) continue;
            if (need[i] > left) continue;
            int s;
            int bonus = shoot(tp.first, i, s);

            // 途中まで撃って，止める場合
            ans = max(ans, left - need[i] + score[s] - score[tp.first]);

            // 最後まで撃つ場合
            int hold = ((1<<10) - 1)^i;
            int freedom_bullet = left - need[i];
            if (freedom_bullet > need[hold] - number[hold]) continue; // 不可能の場合
            pq.push({s,freedom_bullet + bonus});
        }
    }
    // output
    int ans = 0;
    rep(i,0,1<<10) {
        rrep(j,0,110) {
            if (dp[i][j]) {
                ans = max(ans, j + score[i]);
                break;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    string s;
    rep(i,0,3) {
        getline(cin,s);
        for (auto& c: s) {
            if (c == '{' || c == '}' || c == ',') c = ' ';
        }
        stringstream sa(s);
        getline(cin,s);
        for (auto& c: s) {
            if (c == '{' || c == '}' || c == ',') c = ' ';
        }
        stringstream sb(s);
        
        V<int> b(10),p(10);
        rep(i,0,10) sa >> b[i];
        rep(i,0,10) sb >> p[i];
    

        int ans = solve(b,p);
        cout << ans << ",\n"[i==2];
    }

    return 0;
}