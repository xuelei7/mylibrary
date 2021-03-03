// Parentheses
// Dave loves strings consisting only of '(' and ')'. Especially, he is interested in balanced strings. Any balanced strings can be constructed using the following rules:

// A string "()" is balanced.
// Concatenation of two balanced strings are balanced.
// If $T$ is a balanced string, concatenation of '(', $T$, and ')' in this order is balanced. For example, "()()" and "(()())" are balanced strings. ")(" and ")()(()" are not balanced strings.
// Dave has a string consisting only of '(' and ')'. It satises the followings:

// You can make it balanced by swapping adjacent characters exactly $A$ times.
// For any non-negative integer $B$ ($B < A$), you cannot make it balanced by $B$ swaps of adjacent characters.
// It is the shortest of all strings satisfying the above conditions.
// Your task is to compute Dave's string. If there are multiple candidates, output the minimum in lexicographic order. As is the case with ASCII, '(' is less than ')'.

// Input
// The input consists of a single test case, which contains an integer $A$ ($1 \leq A \leq 10^9$).

// Output
// Output Dave's string in one line. If there are multiple candidates, output the minimum in lexicographic order.

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

auto solve (ll n) -> string {
    ll length;
    ll left;
    for (ll i = 0; i < 100000LL; i++) {
        ll base = (i + 1) * i / 2;
        if (base >= n) {
            length = i;
            left = base - n;
            break;
        }
    }

    string ans = "";
    rep(i,0,length) ans += ')';
    rep(i,0,length) ans += '(';
    
    // )|)))...))|(((((...
    int lft = 1;
    length--;
    while (left) {
        ll change = min(left,length);
        
        // 長さchangeの)を全部右に一個移動
        lft += length - change;
        swap(ans[lft],ans[lft+change]);

        left -= change;
        lft += 2;
        dbg(ans);
        dbg(left);
    }
    return ans;
}
// ))((
// ))()((
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    ll n;
    cin >> n;

    // solve
    auto ans = solve(n);

    // output
    cout << ans << endl;
    
    return 0;
}