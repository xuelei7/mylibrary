// 小学生のイクタ君は、ある日おじいさんから数式が書かれた紙をもらった。 どうやらおじいさんは数式の答えの金額だけお小遣いをくれるらしい。 イクタ君はまだ足し算、引き算、掛け算しか習ってなかったので、数式にも足し算と引き算と掛け算しか使われていない。 通常の計算では足し算と引き算より掛け算を先に計算しなければならないのだが、イクタ君は演算子の優先順位についての理解があやふやだったので、とりあえず数式の計算結果が最大になるような都合の良い優先順位を考えることにした。

// +−×の3つの二項演算子と括弧を含む数式が与えられる。 3つの演算子の優先順位を任意に変更して、数式を最大化したときの計算結果を答えよ。

// ただし、以下の点に注意せよ。

// 演算子は必ず左結合である。 (同じ優先順位の演算子は必ず数式の左側から計算する。)
// 異なる演算子が同じ優先順位であってもよい。
// 一つの数式を計算している途中で優先順位を変更してはならない。
// Input
// 入力は以下の形式で与えられる。
// 0〜9の数字と演算子'+','-','*'、括弧'(',')'で構成された数式
// 正確に記述すると入力は以下のBNFで示される形式になっている
// <expr> ::= ( <expr> ) | <number> | <expr> <op> <expr>
// <op> ::= + | - | *
// <number>は非負整数を表す。

// Constraints
// 入力は以下の制約を満たす。

// 数式は200文字以下である。
// どのような優先順位を設定しても、計算の結果やその途中で64bit整数型でoverflowするようなことはない。
// Output
// 数式から得られる最大値を1行で出力せよ。

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef int64_t ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

int pos;
// 数字であるときだけ呼び出すこと
ll get_num(string s) {
    ll ret = 0;
    while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9') {
        ret *= 10;
        ret += s[pos] - '0';
        pos++;
    }
    return ret;
}

// 単純式で，指定のopを計算する
void calc(V<ll>& nums, V<int>& ops, int lv, int lv1, int lv2, int lv3) {
    V<ll> new_nums;
    V<int> new_ops;

    // see numsのiとi+1番目の数字，opsのi番目の記号
    new_nums.push_back(nums[0]);
    rep(i,0,ops.size()) {
        // 計算したい演算子の場合
        if ((ops[i] == 0 && lv1 == lv) ||
            (ops[i] == 1 && lv2 == lv) ||
            (ops[i] == 2 && lv3 == lv)) {
            switch (ops[i]) {
                case 0:
                    new_nums[new_nums.size() - 1] += nums[i+1];
                    break;
                case 1:
                    new_nums[new_nums.size() - 1] -= nums[i+1];
                    break;
                case 2:
                    new_nums[new_nums.size() - 1] *= nums[i+1];
                    break;
            }
        }
        // 違う演算子の場合
        else {
            new_nums.push_back(nums[i+1]);
            new_ops.push_back(ops[i]);
        }
    }

    // 新しい結果を代入する
    nums = new_nums;
    ops = new_ops;
}

// 記号opをop1, op2, op3の順番で処理し，結果を返す関数
// op:
//   0: +
//   1: -
//   2: *
// 初期化すること！
ll process(string s, int op1, int op2, int op3) {

    // (expr op), (expr op), ... op), (expr) + (')' or '')
    // I. 数字と記号を分ける
    V<ll> nums;
    V<int> ops;
    while (1) {
        // 1) 数字を取得
        // かっこが来る場合，式の結果を取得
        if (s[pos] == '(') {
            pos++;  // skip '('
            nums.push_back(process(s,op1,op2,op3));
            pos++;  // skip ')'
        }
        // 数字の場合，数字を取得
        else nums.push_back(get_num(s));


        // 2) 記号を取得 / 終了
        if (pos == s.size() || s[pos] == ')') break;
        if (s[pos] == '+') ops.push_back(0);
        if (s[pos] == '-') ops.push_back(1);
        if (s[pos] == '*') ops.push_back(2);        
        pos++; // skip op
    }


    // II. 単純式を計算する
    calc(nums, ops, 0, op1, op2, op3);
    calc(nums, ops, 1, op1, op2, op3);
    calc(nums, ops, 2, op1, op2, op3);
    assert(nums.size() == 1);

    return nums[0];
}

auto solve (string s) -> ll {
    // Step 1: すべての順番を試し，最大値を取得する
    ll max_val = LLONG_MIN;
    rep(i,0,3) {
        rep(j,0,3) {
            rep(k,0,3) {
                pos = 0;
                ll ret = process(s,i,j,k);
                dbg(ret);
                max_val = max(max_val, ret);
            }
        }
    }

    // Step 2: 結果を返す
    return max_val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    string s;
    cin >> s;

    // solve
    auto ans = solve(s);

    // output
    cout << ans << endl;
    return 0;
}