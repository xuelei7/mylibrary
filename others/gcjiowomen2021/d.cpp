#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

enum Result {
    WIN,
    LOSE,
    DEPEND,
};

struct Status {
    Result result = DEPEND;
    int score = 0;
    char winner;
};

auto solve () -> void {
    string s;
    cin >> s;
    string io = "OI";
    auto dfs = [&] (auto self, int l, int r, int c) -> Status {
#ifdef LOCAL
    cerr << l << " " << r << " " << io[c] << " " << s.substr(l,r-l+1) << endl;
#endif
        // if there is no element
        if (l > r) return (Status){WIN, 1, io[!c]};
        
        // if there is one element
        if (l == r) {
            if (s[l] == io[c]) return (Status){WIN, 1, io[c]};
            else return (Status){WIN, 2, io[!c]};
        }

        // if there is more than two elements
        if (s[l] != s[r]) { // c...!c
            if (s[l] == io[c]) l++;
            else r--;
            return self(self, l, r, !c);
        }
        else if (s[l] != io[c]) { // !c...!c
            // lose
            return (Status){WIN, r - l + 2, io[!c]};
        } else { // c...c
            if (s[l+1] == c || s[r-1] == c) { // cc...c
                // win
                return (Status){WIN, r - l + 1, io[c]};
            } else { // c, !c, ..., !c, c
                Status resultleft, resultright;
                // go left
                int cntl = 0, cntr = 0;
                int tmpl = l;
                while (s[tmpl] != s[tmpl+1] && tmpl+2 <= r) {
                    tmpl += 2;
                    cntl++;
                }
                if (tmpl == r || (s[tmpl] == s[tmpl+1] && s[tmpl] == io[c])) {
                    resultleft = (Status){WIN, r - tmpl + 1, io[c]};
                } else if (s[tmpl] == s[tmpl+1] && s[tmpl] == io[!c]) {
                    resultleft = (Status){LOSE, r - tmpl};
                } else {
                    resultleft = self(self, tmpl, r, !c);
                }
                // go right
                int tmpr = r;
                while (s[tmpr] != s[tmpr-1] && tmpl-2 >= l) {
                    tmpr -= 2;
                    cntr++;
                }
                if (tmpr == l || (s[tmpr] == s[tmpr-1] && s[tmpr] == io[c])) {
                    resultright = (Status){WIN, tmpr - l + 1, io[c]};
                } else if (s[tmpr] == s[tmpr-1] && s[tmpr] == io[!c]) {
                    resultright = (Status){LOSE, tmpr - l, io[c]};
                } else {
                    resultright = self(self, l, tmpr, !c);
                }

                if (resultleft.result == resultright.result) {
                    if (resultleft.result == WIN) { // both win
                        return (Status){WIN, max(resultleft.score, resultright.score), io[c]};
                    } else { // both lose
                        if (cntl == 1 && cntr == 1) return (Status){WIN, min(resultleft.score, resultright.score), io[!c]};
                        return self(self, tmpl-2, tmpr+2, c);
                    }
                } else { // one win, one lose
                    if (resultleft.result == WIN) return resultleft;
                    else return resultright;
                }
            }
        }
    };

    auto ret = dfs(dfs, 0, s.size() - 1, 1);
    cout << ret.winner << " " << ret.score << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,1,t+1) {
        cout << "Case #" << i << ": ";
        solve();
        dbg("-----------");
    }    
    
    return 0;
}