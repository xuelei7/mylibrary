// Problem B: Magic Slayer
// You are in a fantasy monster-ridden world. You are a slayer fighting against the monsters with magic spells.

// The monsters have hit points for each, which represent their vitality. You can decrease their hit points by your magic spells: each spell gives certain points of damage, by which monsters lose their hit points, to either one monster or all monsters in front of you (depending on the spell). Monsters are defeated when their hit points decrease to less than or equal to zero. On the other hand, each spell may consume a certain amount of your magic power. Since your magic power is limited, you want to defeat monsters using the power as little as possible.

// Write a program for this purpose.

// Input
// The input consists of multiple datasets. Each dataset has the following format:

// N
// HP1
// HP2
// ...
// HPN
// M
// Name1 MP1 Target1 Damage1
// Name2 MP2 Target2 Damage2
// ...
// NameM MPM TargetM DamageM
// N is the number of monsters in front of you (1 ≤ N ≤ 100); HPi is the hit points of the i-th monster (1 ≤ HPi ≤ 100000); M is the number of available magic spells (1 ≤ M ≤ 100); Namej is the name of the j-th spell, consisting of up to 16 uppercase and lowercase letters; MPj is the amount of magic power consumed by the j-th spell (0 ≤ MPj ≤ 99); Targetj is either "Single" or "All", where these indicate the j-th magic gives damage just to a single monster or to all monsters respectively; Damagej is the amount of damage (per monster in case of "All") made by the j-th magic (0 ≤ Damagej ≤ 999999).

// All the numbers in the input are integers. There is at least one spell that gives non-zero damage to monsters.

// The last dataset is followed by a line containing one zero. This line is not a part of any dataset and should not be processed.

// Output
// For each dataset, Print in a line the minimum amount of magic power consumed to defeat all the monsters in the input.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll inf = 1e14;
ll hp[110];
vector<pair<ll,ll>> v[2];
ll dp[2][100010];
int main() {
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> hp[i];
        cin >> m;
        v[0].clear();
        v[1].clear();
        for (int i = 0; i < m; i++) {
            string a,b;
            ll c,d;
            cin >> a >> c >> b >> d;
            bool mode = (b == "All");
            v[mode].push_back({c,d});
        }

        for (int i = 0; i < 100010; i++) {
            for (int j = 0; j < 2; j++) {
                dp[j][i] = inf;
            }
        }

        dp[0][0] = 0;
        dp[1][0] = 0;
        
        for (int mode = 0; mode < 2; mode++) {
            for (int i = 0; i < 100010; i++) {
                for (int j = 0; j < v[mode].size(); j++) {
                    dp[mode][min((ll)i+v[mode][j].second,100000LL)] = min(dp[mode][min((ll)i+v[mode][j].second,100000LL)], dp[mode][i] + v[mode][j].first);
                    dp[mode][min((ll)i+v[mode][j].second,100000LL)] = min(dp[mode][min((ll)i+v[mode][j].second,100000LL)], dp[mode][i] + v[mode][j].first);
                }
            }
            for (int i = 100000; i >= 0; i--) {
                dp[mode][i] = min(dp[mode][i], dp[mode][i+1]);
            }
        }

        ll ans = inf;
        for (int i = 0; i <= 100000; i++) {
            ll mp = dp[1][i];
            for (int j = 0; j < n; j++) {
                mp += dp[0][max(0LL,hp[j]-i)];
            }
            ans = min(ans, mp);
        }
        cout << ans << endl;
    }
    return 0;
}
