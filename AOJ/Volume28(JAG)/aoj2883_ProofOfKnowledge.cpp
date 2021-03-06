// 知識の証明
// あなたが住んでいる集合住宅の入口のドアには，パスワード式のロックがかけられている．このパスワードはちょうど 4 桁の 0 から 9 の範囲の数字で構成されており，あなたはいつも，集合住宅の管理人から伝えられたパスワード P を使って，このドアのロックを解除している．

// ある日，あなたは集合住宅の住民全員が，自分と同じパスワード P を使っているのかどうか気になり，同じ集合住宅に住む友人に尋ねることにした．あなたとあなたの友人は，自分のパスワードを互いに伝えあうことで，同じパスワードを使っているのかどうか確かめ合うことができる．しかしながら，パスワードがそれぞれの住民に個別に割り当てられている可能性を考えると，この方法は好ましくない．自分のパスワードを知っているのは自分だけであるべきで，他人に伝えるべきではないからである．

// この事態を防ぐために，あなたとあなたの友人は，自分のパスワードをハッシュ関数に入力し，得られたハッシュ値を互いに伝えあうことにした．ここで使用するハッシュ関数の計算式 S は小文字のアルファベット 'a', 'b', 'c', 'd' と記号 '[', ']', '+', '*', '^' からなり，以下のBNFで定義される <Hash> によって表される．

// <Hash> ::= <Letter> | '['<Op><Hash><Hash>']' <Op> ::= '+' | '*' | '^' <Letter> ::= 'a' | 'b' | 'c' | 'd'
// ここで 'a', 'b', 'c', 'd' はそれぞれ 4 桁のパスワードの先頭から 1 桁目，2 桁目，3 桁目，4 桁目の数字を表す．'+', '*', '^' は演算子であり，以下のような意味を表す．

// '+' : 続く 2 つの <Hash> を二進数で表したときの論理和を取る
// '*' : 続く 2 つの <Hash> を二進数で表したときの論理積を取る
// '^' : 続く 2 つの <Hash> を二進数で表したときの排他的論理和を取る
// ここで，論理和，論理積，排他的論理和の真理値表はそれぞれ以下のようになる．

// A	B	[+AB]
// 0	0	0
// 1	0	1
// 0	1	1
// 1	1	1
// A	B	[*AB]
// 0	0	0
// 1	0	0
// 0	1	0
// 1	1	1
// A	B	[^AB]
// 0	0	0
// 1	0	1
// 0	1	1
// 1	1	0
// 例として，ハッシュ関数 [+c[+a[^bd]]] にパスワード 0404 を入力すると，ハッシュ値として 0 が得られる．同じハッシュ値が得られるパスワードとして 0000, 0101, 0202, 0303, 0505, 0606, 0707, 0808, 0909 がある．

// あなたのパスワード P をハッシュ関数 S に入力した結果を出力せよ．また，ハッシュ値からパスワードを一意に特定可能なハッシュ関数の使用を防ぐため，あなたのパスワードと同じハッシュ値になるパスワードの数も出力せよ．

// Input
// 入力は最大で 50 個のデータセットから構成される．各データセットは次の形式で表される．

// S
// P
// 各データセットの1行目は，ハッシュ関数の計算式 S である．各データセットの2行目は，4 桁の 0 から 9 の範囲の数字で構成されるパスワード P である．ハッシュ関数 S の長さは 80 以下であると仮定してよい．

// 入力の終了は '.' の1文字だけを含む行で表される．

// Output
// 各データセットについて，P を S に入力して得られるハッシュ値と，P と同じハッシュ値が得られるパスワードの数を空白区切りで出力せよ．

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

const int MAXN = 0;
const int MAXM = 0;

string generate_enc(int k) {
    string ret = "";
    rep(i,0,5) {
        ret = (char)(k % 10 + '0') + ret;
        k /= 10;
    }
    return ret;
}

auto solve(string s, string p) -> int {
    
    // put decoded number into passwd
    // return the end position
    auto decode = [&](auto self, string enc, int pos, int& passwd) -> int {
        dbg(pos);
        // if only character
        assert(pos<s.size());
        if (s[pos] >= 'a' && s[pos] <= 'd') {
            passwd = enc[s[pos] - 'a'] - '0';
            return pos + 1;
        }

        // "["
        pos++;

        // op
        assert(pos < s.size());
        char op = s[pos];
        pos++;

        // numbers
        int left, right;
        pos = self(self,enc,pos,left);
        pos = self(self,enc,pos,right);

        // "]"
        pos++;

        // calc passwd
        if (op == '+') passwd = left | right;
        if (op == '*') passwd = left & right;
        if (op == '^') passwd = left ^ right;        

        return pos;
    };
    
    // try every number & count good combinations
    int ret = 0;
    int correct; decode(decode,p,0,correct);
    rep(i,0,10000) {
        int tmp; decode(decode,generate_enc(i),0,tmp);
        if (tmp == correct) ret++;
    }
    
    cout << correct << " " << ret << endl;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    string s, p;
    while (cin >> s) {
        if (s == ".") break;
        cin >> p;
        
        // solve
        auto ans = solve(s,p);
    }

    return 0;
}