// H - RLE Replacement
// Problem Statement
// In JAG Kingdom, ICPC (Intentionally Compressible Programming Code) is one of the common programming languages. Programs in this language only contain uppercase English letters and the same letters often appear repeatedly in ICPC programs. Thus, programmers in JAG Kingdom prefer to compress ICPC programs by Run Length Encoding in order to manage very large-scale ICPC programs.

// Run Length Encoding (RLE) is a string compression method such that each maximal sequence of the same letters is encoded by a pair of the letter and the length. For example, the string "RRRRLEEE" is represented as "R4L1E3" in RLE.

// Now, you manage many ICPC programs encoded by RLE. You are developing an editor for ICPC programs encoded by RLE, and now you would like to implement a replacement function. Given three strings [Math Processing Error], [Math Processing Error], and [Math Processing Error] that are encoded by RLE, your task is to implement a function replacing the first occurrence of the substring [Math Processing Error] in [Math Processing Error] with [Math Processing Error], and outputting the edited string encoded by RLE. If [Math Processing Error] does not occur in [Math Processing Error], you must output [Math Processing Error] encoded by RLE without changes.

// Input
// The input consists of three lines.

// [Math Processing Error]
// [Math Processing Error]
// [Math Processing Error]
// The lines represent strings [Math Processing Error], [Math Processing Error], and [Math Processing Error] that are encoded by RLE, respectively. Each of the lines has the following format:

// [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] $
// Each [Math Processing Error] ([Math Processing Error]) is an uppercase English letter (A-Z) and [Math Processing Error] ([Math Processing Error], [Math Processing Error]) is an integer which represents the length of the repetition of [Math Processing Error]. The number [Math Processing Error] of the pairs of a letter and an integer satisfies [Math Processing Error]. A terminal symbol $ indicates the end of a string encoded by RLE. The letters and the integers are separated by a single space. It is guaranteed that [Math Processing Error] holds for any [Math Processing Error].

// Output
// Replace the first occurrence of the substring [Math Processing Error] in [Math Processing Error] with [Math Processing Error] if [Math Processing Error] occurs in [Math Processing Error], and output the string encoded by RLE. The output must have the following format:

// [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error] $
// Here, [Math Processing Error] for [Math Processing Error] and [Math Processing Error] for [Math Processing Error] must hold.

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

auto solve (V<char>& Ac, V<ll>& Al, V<char>& Bc, V<ll>& Bl, V<char>& Cc, V<ll>& Cl) -> string {
    int na = Ac.size(), nb = Bc.size(), nc = Cc.size();

    // Aの中でBを探す，Aにおける始点と終点を記録
    int bg = -1, ed = -1;
    rep(i,0,na) {
        if (i + nb > na) break;
        bool ok = 1;
        
        // 最初のやつ
        if (Ac[i] != Bc[0] || Al[i] < Bl[0]) continue;

        // 真ん中
        rep(j,1,nb-1) {
            if (Ac[i+j] != Bc[j] || Al[i+j] != Bl[j]) {
                ok = 0;
                break;
            }
        }

        // 最後のやつ
        if (Ac[i+nb-1] != Bc[nb-1] || Al[i+nb-1] < Bl[nb-1]) continue;

        if (!ok) continue;

        // okの場合
        bg = i;
        ed = bg + nb;
        dbg(bg);
        dbg(Ac[bg]);
        dbg(Al[bg]);
        break;
    }

    V<char> Rc;
    V<ll> Rl;
    // substringの部分をCで置き換わる
    if (bg != -1) {
        // もともとAのもの
        rep(i,0,bg) {
            Rc.push_back(Ac[i]);
            Rl.push_back(Al[i]);        
        }
        // 最初のやつ
        if (Al[bg] != Bl[0] && nb != 1) {
            Rc.push_back(Ac[bg]);
            Rl.push_back(Al[bg] - Bl[0]);
        }
        // 真ん中
        rep(i,0,nc) {
            Rc.push_back(Cc[i]);
            Rl.push_back(Cl[i]);
        }
        // 最後のやつ
        if (Al[ed-1] != Bl[nb-1]) {
            Rc.push_back(Ac[ed-1]);
            Rl.push_back(Al[ed-1] - Bl[nb-1]);
        }
        // もともとAのもの
        rep(i,ed,na) {
            Rc.push_back(Ac[i]);
            Rl.push_back(Al[i]);
        }
    } else {
        Rc = Ac;
        Rl = Al;
    }

    // 答えのRLE
    V<char> Retc;
    V<ll> Retl;
    char c = '$';
    ll len = 0;
    int nr = Rc.size();
    rep(i,0,nr) {
        if (c != Rc[i]) {
            if (c != '$') {
                Retc.push_back(c);
                Retl.push_back(len);
            }
            c = Rc[i];
            len = Rl[i];
        } else {
            len += Rl[i];
        }
    }
    if (len != 0) {
        Retc.push_back(c);
        Retl.push_back(len);
    }

    // 答え生成
    string ret = "";
    stringstream sout;
    rep(i,0,Retc.size()) {
        sout << Retc[i] << " " << Retl[i] << " ";
    }
    sout << "$";
    return sout.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    auto input = [&](V<char>& c, V<ll>& l) -> void {
        string s;
        getline(cin,s);
        stringstream ss(s);
        char character;
        ll length;
        while (ss >> character >> length) {
            if (character == '$') break;
            c.push_back(character);
            l.push_back(length);
        }
    };

    // input
    V<char> Ac, Bc, Cc;
    V<ll> Al, Bl, Cl;
    input(Ac,Al);
    input(Bc,Bl);
    input(Cc,Cl);
    dbg(Al.size());
    dbg(Bl.size());
    dbg(Cl.size());
    // solve
    auto ans = solve(Ac,Al,Bc,Bl,Cc,Cl);

    // output
    cout << ans << endl;

    return 0;
}