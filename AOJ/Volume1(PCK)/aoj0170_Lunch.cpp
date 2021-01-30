// ランチ
// お昼に食べるお弁当を作るために、お店で食べ物を買いました。お店では、食べ物を入れるのに細長い袋しかもらえなかったので、すべての食べ物を縦に積んで袋に入れる必要があります。袋が倒れにくいように、できるだけ重い物を下にして詰めたいのですが、食べ物の中にはやわらかい物もあって、上に重い物を乗せるとつぶれてしまいます。

// そこで、食べ物の情報を入力とし、全ての食べ物がつぶれず、かつ全体の重心が最も低くなるような積み方を出力するプログラムを作成してください。それぞれの食べ物ごとに、名前 f、重さ w、上に載せて耐えられる重さ s が指定されます。 「全ての食べ物がつぶれない」というのは、下から順に、（f1、f2、... 、fn）と n 個の食べ物を積んだ時、すべての f について、

// sfi≥wfi+1+wfi+2+ ... +wfn

// であることを意味します。また、全体の重心 G は、

// G=(1×wf1+2×wf2+ ... +n×wfn) / (wf1+wf2+ ... +wfn)

// とします。ただし、解はちょうど1つだけ存在するものとします。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。各データセットは以下の形式で与えられます。

// n
// f1 w1 s1
// f2 w2 s2
// :
// fn wn sn
// １行目に食べ物の個数 n (1 ≤ n ≤ 10)、続く n 行に i 番目の食べ物の名前 fi (20 文字以内の半角英文字列)、重さ wi (1 ≤ wi ≤ 1000)、耐えられる重さ si (1 ≤ si ≤ 1000) が空白区切りで与えられます。

// データセットの数は 20 を超えません。

// Output
// データセットごとに、次の形式で食べ物の名前を下から積み上げる順に出力します。

// 1 行目: 1 番下の食べ物の名前（半角英文字列）
// 2 行目: 下から2 番目の食べ物の名前
// ：
// n 行目: 1 番上の食べ物の名前

#include <bits/stdc++.h>
using namespace std;

int n;
string f[11];
int w[11], s[11];

struct Food {
    string name;
    int w, s;
    Food(){}
    Food(string name, int w, int s): name(name),w(w),s(s) {}
    bool operator < (const Food& f) const {
        if (w != f.w) return w < f.w;
        else if (s != f.s) return s < f.s;
        return name < f.name;
    }
};

void solve() {
    vector<Food> v;
    for (int i = 0; i < n; i++) {
        string name;
        int w,s;
        cin >> name >> w >> s;
        v.push_back(Food(name,w,s));
    }
    sort(v.begin(),v.end());
    vector<Food> ans(n);
    int g = 1000000;
    do {
        bool ok = 1;
        int tg = 0;
        int sum = v[n-1].w;
        for (int i = n-2; i >= 0; i--) {
            if (sum > v[i].s) ok = 0;
            sum += v[i].w;
        }
        if (!ok) continue;
        for (int i = 0; i < n; i++) {
            tg += (i+1) * v[i].w;
        }
        if (tg < g) {
            g = tg;
            for (int i = 0; i < n; i++) ans[i] = v[i];
        }
    } while (next_permutation(v.begin(),v.end()));
    for (int i = 0; i < n; i++) {
        cout << ans[i].name << endl;
    }
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        solve();
    }
    return 0;
}