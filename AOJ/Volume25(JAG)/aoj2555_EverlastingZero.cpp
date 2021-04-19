// A - Everlasting Zero
// Problem Statement
// You are very absorbed in a famous role-playing game (RPG), "Everlasting -Zero-". An RPG is a game in which players assume the roles of characters in a fictional setting. While you play the game, you can forget your "real life" and become a different person.

// To play the game more effectively, you have to understand two notions, a skill point and a special command. A character can boost up by accumulating his experience points. When a character boosts up, he can gain skill points.

// You can arbitrarily allocate the skill points to the character's skills to enhance the character's abilities. If skill points of each skill meets some conditions simultaneously (e.g., the skill points of some skills are are greater than or equal to the threshold values and those of others are less than or equal to the values) , the character learns a special command. One important thing is that once a character learned the command, he will never forget it. And once skill points are allocated to the character, you cannot revoke the allocation. In addition, the initial values of each skill is 0.

// The system is so complicated that it is difficult for ordinary players to know whether a character can learn all the special commands or not. Luckily, in the "real" world, you are a great programmer, so you decided to write a program to tell whether a character can learn all the special commnads or not. If it turns out to be feasible, you will be more absorbed in the game and become happy.

// Input
// The input is formatted as follows.

// M N
// K1
// s1,1 cond1,1 t1,1
// s1,2 cond1,2 t1,2
// ...
// s1,K1 cond1,K1 t1,K1
// K2
// ...
// KM
// sM,1 condM,1 tM,1
// sM,2 condM,2 tM,2
// ...
// sM,KM condM,KM tM,KM
// The first line of the input contains two integers (M, N), where M is the number of special commands (1≤M≤100), N is the number of skills (1≤N≤100). All special commands and skills are numbered from 1.

// Then M set of conditions follows. The first line of a condition set contains a single integer Ki (0≤Ki≤100), where Ki is the number of conditions to learn the i-th command. The following Ki lines describe the conditions on the skill values. si,j is an integer to identify the skill required to learn the command. condi,j is given by string "<=" or ">=". If condi,j is "<=", the skill point of si,j-th skill must be less than or equal to the threshold value ti,j (0≤ti,j≤100). Otherwise, i.e. if condi,j is ">=", the skill point of si,j must be greater than or equal to ti,j.

// Output
// Output "Yes" (without quotes) if a character can learn all the special commands in given conditions, otherwise "No" (without quotes).

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

// cond:
//    <= : 0
//    >= : 1
auto solve (int n, int m, V<int>& k, VV<int>&s, VV<bool>& cond, VV<int>&t) -> bool {
    VV<pair<int,int>> skill(m);
    int inf = 110;
    // 自身が不可能の場合
    rep(i,0,m) {
        V<pair<int,int>> sk(n,{0,inf});
        rep(j,0,k[i]) {
            pair<int,int> range;
            if (cond[i][j]) range = {t[i][j],inf};
            else range = {0,t[i][j]};
            if (range.first > sk[s[i][j]].second ||
                range.second < sk[s[i][j]].first) return 0;
            else {
                sk[s[i][j]].first = max(sk[s[i][j]].first, range.first);
                sk[s[i][j]].second = min(sk[s[i][j]].second, range.second);
            }
        }
        skill[i] = sk;
    }
    
    // m回とる
    V<bool> used(m,0);
    rep(take,0,m) {
        // i番目のcommandを取得可能かを見る
        // iより前に取得しないといけないものがあれば，iを取得しない
        rep(i,0,m) {
            bool learni = 1;
            if (used[i]) continue;
            rep(j,0,m) {
                if (used[j]) continue;
                if (i == j) continue;

                // bがaより前ならtrue
                // TODO: 時間短縮
                auto previous = [&](int a, int b) -> bool {
                    rep(i,0,n) {
                        auto rangea = skill[a][i];
                        auto rangeb = skill[b][i];
                        if (rangeb.second < rangea.first) return true;
                    }
                    return false;
                };
                if (previous(i,j)) {
                    learni = 0;
                    break;
                }
            }

            // 前に来るものがなければとる
            if (learni) {
                used[i] = 1;
                break;
            }
        }
    }

    rep(i,0,m) if (!used[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n,m;
    cin >> m >> n;
    V<int> k(m);
    VV<int> s(m),t(m);
    VV<bool> cond(m);
    rep(i,0,m) {
        cin >> k[i];
        V<int> ts(k[i]), tt(k[i]);
        V<bool> tc(k[i]);
        rep(j,0,k[i]) {
            string comp;
            cin >> ts[j] >> comp >> tt[j];
            ts[j]--; // スキルを0インデックスにする
            tc[j] = (comp == ">=");
        }
        s[i] = ts;
        t[i] = tt;
        cond[i] = tc;
    }

    // solve
    auto ans = solve(n,m,k,s,cond,t);

    // output
    cout << (ans?"Yes":"No") << endl;
    
    return 0;
}