// 壊れた暗号生成器
// JAG (Japanese Alumni Group) は多くのプログラマで構成される謎の組織であり，この組織の本部がある建物に入るためには毎回ある機械によって生成される暗号文を解かなくてはならない． この暗号文は，'+'，'-'，'['，']' の記号と大文字のアルファベットからなっており，以下の BNF で定義される <Cipher> によって表される．

// <Cipher> ::= <String> | <Cipher><String>
// <String> ::= <Letter> | '['<Cipher>']'
// <Letter> ::= '+'<Letter> | '-'<Letter> |
//              'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L' | 'M' |
//              'N' | 'O' | 'P' | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z'
// ここでそれぞれの記号は以下のような意味を表す．

// +(文字) : その文字の次のアルファベットを表す (ただし 'Z' の次のアルファベットは 'A' であるとする)
// -(文字) : その文字の前のアルファベットを表す (ただし 'A' の前のアルファベットは 'Z' であるとする)
// [(文字列)] : その文字列を左右反転した文字列を表す
// しかしこの暗号文を生成する機械には現在故障が発生しており，暗号文のうちアルファベットの箇所が数文字壊れて読めなくなっている場合がある．読めない文字は仮に '?' と表されている． 調査の結果，壊れた文字の埋め方は，復号後の文字列が，復号後の文字列としてありえる文字列の中で辞書順最小になるようなものであることがわかった． あなたの仕事はこの暗号文を正しく復号することである．

// Input
// 入力は複数のデータセットから構成される． 各データセットは，上記の BNF で定義された暗号文において，一部の大文字のアルファベットが ‘?’ に置き換えられた文字列を含む 1 行からなる． 各文字列の長さは $80$ 以下であると仮定してよい． また各データセットに含まれる '?' の数は $0$ 以上 $3$ 以下であると仮定してよい．

// 入力の終了は '.' の1文字だけを含む行で表される．

// Output
// 各データセットに対して，復号後の文字列が辞書順最小になるように暗号文を復号したときの，復号後の文字列を出力せよ．

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

string Cipher(string s);
string String(string s);
char Letter(string s);

int pos;

string Cipher(string s) {
#ifdef LOCAL
    cerr << "Cipher " << pos << endl;
#endif
    string ret = "";
    while (pos < s.size() && s[pos] != ']') {
        ret += String(s);
    }
#ifdef LOCAL
    cerr << "-> Cipher " << ret << endl;
#endif
    return ret;
}

string String(string s) {
#ifdef LOCAL
    cerr << "String " << pos << endl;
#endif
    if (s[pos] == '[') {
        pos++; // '['
        string ret = Cipher(s);
        pos++; // ']'
        reverse(all(ret));
        return ret;
    }
    string ret = "";
    ret += Letter(s);
    return ret;
}

char Letter(string s) {
#ifdef LOCAL
    cerr << "Letter " << pos << endl;
#endif
    if (s[pos] >= 'A' && s[pos] <= 'Z') {
        return s[pos++];
    }
    if (s[pos] == '?') {
        return s[pos++];
    }
    char op = s[pos++];
    char c = Letter(s);
    if (c == '?') return '?';
    else {
        if (op == '+') c++;
        else c--;
        if (c > 'Z') c -= 26;
        if (c < 'A') c += 26;
        return c;
    }
}

auto solve (string s) -> string {
    pos = 0;
    string ss = Cipher(s);
    dbg(ss);
    for (auto& c: ss) {
        if (c == '?') c = 'A';
    }
    return ss;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    string s;
    while (cin >> s) {
        if (s == ".") break;

        // solve
        auto ans = solve(s);

        // output
        cout << ans << endl;
        
    }
    return 0;
}