// 問題名 Zero division checker
// 森下さんは困っていました... 姉原さんにプログラムを書いてもらったのですが、そのプログラムがクラッシュするのです。

// 姉原さんに書いてもらったのは、逆ポーランド記法の式を読んで、その計算結果を出力するプログラムで、クラッシュログによると、 0 で割り算をしてしまったのが原因のようです。これは、森下さんが間違った式を入力してしまったからかもしれませんし、もしかしたら、もしかしたら、姉原さんの書いたプログラムにバグがあるのかもしれません。

// 姉原さんの書いたプログラムを読んでみようと思いましたが、姉原さんのプログラムはアセンブリというよくわからないことばで書かれているようで、見ているだけで頭がガンガンしてきます。

// そこで、森下さんはあなたに、式が間違っていないかどうか調べるプログラムを書いてもらうことにしました。式が間違っている、とは、その式に従って計算すると、 0 での割り算をしてしまう可能性のあることをいいます。

// なお、姉原さんの書いたコードはとてもふるいコンピューターで動くもので、加減乗除は整数で行い、結果は 8 bit の符号なし整数として保存されます。 例えば、255+1 は 0 になってしまうし、3/2 は 1 になります。

// あ、姉原さんにはないしょですよ。

// (参考)逆ポーランド記法で表された式を計算する、擬似コード
// s = 空のスタック
// n = 式の要素数
// for i in 1..n:
//   if 式のi番目の要素が整数:
//     sにその整数をプッシュする
//   if 式のi番目の要素が変数:
//     sにその変数の値をプッシュする
//   if 式のi番目の要素が演算子:
//     sから値をポップし、bとする
//     sから値をポップし、aとする
//     if 演算子が'+':
//       r = (a + b) % 256 とする
//     if 演算子が'-':
//       r = (a - b + 256) % 256 とする
//     if 演算子が'*':
//       r = (a * b) % 256 とする
//     if 演算子が'/':
//       r = (a / b) % 256 とする
//     sにrをプッシュする
// sから値をポップし、式の計算結果とする
// Input
// m
// name1 lb1 ub1
// ...
// namem lbm ubm
// n
// e1 e2 ... en
// 0≤m≤100

// 0≤lbi≤ubi≤255

// 1≤namei(1≤i≤m)の長さ≤20

// 1≤n≤100

// m は変数の数、namei, lbi, ubi はそれぞれ変数iの名前、下限、上限を表します。

// n は式に含まれる要素の数を表し、ei は式の i 番目の要素を表します。

// 各変数は式の中に高々1回しか現れません。

// Output
// 式が間違っているときにはerror、間違っていないときにはcorrectと一行で出力してください。

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
    
    int m;
    cin >> m;

    map<string,int> id;
    V<pair<int,int>> range(m);
    rep(i,0,m) {
        string name;
        int lb, ub;
        cin >> name >> lb >> ub;
        id[name] = i;
        range[i] = {lb,ub};
    }

    int n;
    cin >> n;
    stack<bitset<256>> s;

    auto isint = [](string e) -> bool {
        rep(i,0,e.size()) {
            if (e[i] < '0' || e[i] > '9') return false;
        }
        return true;
    };

    auto isvar = [](string e) -> bool {
        if (e != "+" && e != "-" && e != "*" && e != "/") {
            if (e[0] < '0' || e[0] > '9') return true;
        }
        return false;
    };

    rep(i,0,n) {
        string e;
        cin >> e;
        if (isint(e)) {
            bitset<256> bs;
            bs.set(stoi(e));
            s.push(bs);
        }
        else if (isvar(e)) {
            bitset<256> bs;
            rep(j,range[id[e]].first, range[id[e]].second+1) {
                bs.set(j);
            }
            s.push(bs);
        } else {
            bitset<256> a,b,r;
            b = s.top(); s.pop();
            a = s.top(); s.pop();
            if (e == "+") {
                rep(aa,0,256) {
                    if (!a[aa]) continue;
                    rep(bb,0,256) {
                        if (!b[bb]) continue;
                        r.set((aa+bb)%256);
                    }
                }
            }
            else if (e == "-") {
                rep(aa,0,256) {
                    if (!a[aa]) continue;
                    rep(bb,0,256) {
                        if (!b[bb]) continue;
                        r.set((aa-bb+256)%256);
                    }
                }
            }
            else if (e == "*") {
                rep(aa,0,256) {
                    if (!a[aa]) continue;
                    rep(bb,0,256) {
                        if (!b[bb]) continue;
                        r.set((aa*bb)%256);
                    }
                }
            }
            else if (e == "/") {
                if (b[0]) {
                    cout << "error" << endl;
                    return 0;
                }
                rep(aa,0,256) {
                    if (!a[aa]) continue;
                    rep(bb,0,256) {
                        if (!b[bb]) continue;
                        r.set(aa/bb);
                    }
                }
            }
            s.push(r);
        }
    }
    cout << "correct" << endl;
    return 0;
}