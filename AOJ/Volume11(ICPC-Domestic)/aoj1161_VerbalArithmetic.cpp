// Problem C: 覆面算
// 覆面算を考えよう．

// このパズルでは，たとえば以下のような十進表現の非負整数の足し算を扱う．

//     905 +  125 = 1030
// 覆面算では等式の中の全ての数字はアルファベットの文字で隠されている． たとえば，上で示した等式を答の一つに持つ問題には次のものがある．

//     ACM + IBM = ICPC

// このパズルを解くということは，与えられた覆面算において 各文字が隠している数字を見つけることである．

// パズルの規則は以下のとおりである．

// 整数の各桁は10種類の数字'0'〜'9'で表されるが，すべての数字は アルファベット文字'A'〜'Z'で隠されている．
// 等式の複数箇所に現れる同一のアルファベット文字は，同じ数字を隠している． また，同じ数字はすべて，同じアルファベット文字で隠されている． すなわち，等式中の異なるアルファベット文字は異なる数字を表している．
// ゼロが'0'という一文字で表される場合を除いて， 最上位の桁の数字は0になってはいけない． つまり，"00"や"0123"などの表現は許されない．
// 上の覆面算における可能な数字の割り当ては， 表に示す通り4種類ある．

// Mask	A	B	C	I	M	P
// Case 1	9	2	0	1	5	3
// Case 2	9	3	0	1	5	4
// Case 3	9	6	0	1	5	7
// Case 4	9	7	0	1	5	8
// このパズルを解くプログラムを作成せよ．

// Input
// 入力は複数のデータセットからなる． 入力の終わりはゼロをひとつだけ含む行で表される．

// データセットの個数は100以下である． 各データセットは次の形式で表される．

// N
// STRING 1
// STRING 2
// ...
// STRING N
// データセットの最初の行は，等式に現れる整数の数 N を表している．

// それに続く N 行はそれぞれ，'A' 〜 'Z'というアルファベット大文字から成る1個の文字列を含む． これらのアルファベット文字が隠された数字を表している．

// 各データセットが表しているのは次の等式である．

// STRING 1 + STRING 2 + ... + STRING N -1 = STRING N
// N は 3 以上 12以下の整数， 各STRING i の長さは 1 以上 8 以下である． 各データセットに現れるアルファベット文字の種類は 1以上10以下である．

// Output
// 等式を満たすような数字の割り当てが何通りあるかを， 各データセットに対してそれぞれ1行で出力しなさい．

// それ以外の余計な文字を出力してはいけない．

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

int n;
V<string> s;
V<int> mp(26);
V<bool> used(10);

int dfs(int keta, int id, int sum) {
#ifdef LOCAL
    cout << "keta: " << keta << ", id: " << id << ", sum: " << sum << endl;
    rep(i,0,26) {
        if (mp[i] != -1) cout << (char)(i+'A') << "-" << mp[i] << " ";
    }
    cout << endl;
#endif
    if (keta == s[n-1].size() && id == 0) {
#ifdef LOCAL
    cout << (sum == 0 ? "OK" : "NG") << endl;
#endif
        return sum == 0;
    }

    int sz = s[id].size();
    int k = sz - keta - 1; // 現在の文字列において，見ている桁id
    // 和に来たら
    if (id == n - 1) {
        // 決められている場合
        if (mp[s[id][k] - 'A'] != -1) {
            if (sz >= 2 && k == 0 && mp[s[id][k] - 'A'] == 0) return 0;
            if (sum % 10 == mp[s[id][k] - 'A']) {
                return dfs(keta+1, 0, sum / 10);
            } else {
                return 0;
            }
        }

        // 決められていない場合
        if (!used[sum % 10]) {
            mp[s[id][k] - 'A'] = sum % 10;
            if (sum % 10 == 0 && sz >= 2 && k == 0 && mp[s[id][k] - 'A'] == 0) {
                mp[s[id][k] - 'A'] = -1;
                return 0;
            }
            used[sum % 10] = 1;
            int ans = dfs(keta+1, 0, sum / 10);
            mp[s[id][k] - 'A'] = -1;
            used[sum % 10] = 0;
            return ans;
        } else {
            return 0;
        }
    }
    
    // n-1より前の数字について
    
    if (k < 0) { // keta より短い数字
        return dfs(keta, id+1, sum);        
    }

    // ketaに数字があり
    // 決められていない場合
    if (mp[s[id][k] - 'A'] == -1) {
        int ans = 0;
        rep(i,0,10) {
            if (sz >= 2 && keta == sz - 1 && i == 0) continue;
            if (used[i]) continue;
            mp[s[id][k] - 'A'] = i;
            used[i] = 1;
            ans += dfs(keta, id + 1, sum + i);
            mp[s[id][k] - 'A'] = -1;
            used[i] = 0;
        }
        return ans;
    }
    // 決められている場合
    else {
        if (sz >= 2 && k == 0 && mp[s[id][k] - 'A'] == 0) return 0;
        return dfs(keta, id+1, sum + mp[s[id][k] - 'A']);
    }
}

int solve () {
    rep(i,0,26) mp[i] = -1;
    rep(i,0,10) used[i] = 0;
    rep(i,0,n-1) if (s[i].size() > s[n-1].size()) return 0;
    return dfs(0,0,0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    while (cin >> n) {
        if (n == 0) break;
        s.clear();
        s.resize(n);
        rep(i,0,n) cin >> s[i];

        // solve
        auto ans = solve();

        // output
        cout << ans << endl;
    }
    return 0;
}