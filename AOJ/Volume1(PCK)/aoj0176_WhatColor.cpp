// 何色？
// ウェブデザイナーを目指す太郎君はただいま修行中。事務所の先輩から「このページの背景色は#ffe085で」と、ウェブデザイン特有の色番号で指示されるのですが、それがどんな色かパッと思い浮かべることができません。

// この色番号は光の三原色である赤、緑、青それぞれの強さを表わしています。具体的には2 桁の 16 進数を3 つ組み合わせたもので、色番号を“#RGB”とするとき、R は赤の強さ、G は緑の強さ、は青の強さを表します。それぞれ 00 から ff までの値になります。

// 色番号にまだ不慣れな太郎君のために、色番号を入力とし、色の表の中からもっとも近い色の名前 を出力するプログラムを作成してください。使用する色の表は以下の通りです。

//  	色の名前	赤の強さ	緑の強さ	青の強さ
// black	00	00	00
// blue	00	00	ff
// lime	00	ff	00
// aqua	00	ff	ff
// red	ff	00	00
// fuchsia	ff	00	ff
// yellow	ff	ff	00
// white	ff	ff	ff


// 「もっとも近い色」とは、以下のように定義します。与えられた色番号での赤、緑、青の強さをそれぞれ R、G、B とし、表の k 番目の色の赤、緑、青の強さをそれぞれ Rk、Gk、Bk とするとき、次の式で計算する dk の値が最も小さい色がもっとも近い色とします。




// なお、dk の値が同じになる色が複数存在する場合は表の中でより上にある色がもっとも近い色になり ます。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。各データセットとして、色番号を表す文字列が、#RGB 形式で１行に与えられます。

// データセットの数は 1000 を超えません。

// Output
// データセット毎に最も近い色の名前を１行に出力します。

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

ll ff = (1<<8)-1;

struct Color {
    string name;
    ll r,g,b;
} color[8] = {
    "black",0,0,0,
    "blue",0,0,ff,
    "lime",0,ff,0,
    "aqua",0,ff,ff,
    "red",ff,0,0,
    "fuchsia",ff,0,ff,
    "yellow",ff,ff,0,
    "white",ff,ff,ff
};

ll f16(char c) {
    if (c >= 'a') {
        return c - 'a' + 10;
    } else {
        return c - '0';
    }
}

auto solve (string s) -> string {
    string ret;
    ll mi = 1e18;
    ll r = f16(s[1]) * 16 + f16(s[2]);
    ll g = f16(s[3]) * 16 + f16(s[4]);
    ll b = f16(s[5]) * 16 + f16(s[6]);
    dbg(ff);
    for (auto e : color) {
        ll dist = (r - e.r) * (r - e.r) + (g - e.g) * (g - e.g) + (b - e.b) * (b - e.b);
    dbg(e.name);
    dbg(dist);
        if (dist < mi) {
            mi = dist;
            ret = e.name;
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    string s;
    while (cin >> s) {
        if (s == "0") break;
        cout << solve(s) << endl;
    }
    
    return 0;
}