// Problem Statement
// We found a dictionary of the Ancient Civilization Mayo (ACM) during excavation of the ruins. After analysis of the dictionary, we revealed they used a language that had not more than 26 letters. So one of us mapped each letter to a different English alphabet and typed all the words in the dictionary into a computer.

// How the words are ordered in the dictionary, especially whether they are ordered lexicographically, is an interesting topic to many people. As a good programmer, you are requested to write a program to judge whether we can consider the words to be sorted in a lexicographical order.

// Note: In a lexicographical order, a word always precedes other words it is a prefix of. For example, ab precedes abc, abde, and so on.

// Input
// The input consists of multiple datasets. Each dataset is formatted as follows:

// n
// string1
// ...
// stringn
// Each dataset consists of n+1 lines. The first line of each dataset contains an integer that indicates n (1≤n≤500). The i-th line of the following n lines contains stringi, which consists of up to 10 English lowercase letters.

// The end of the input is 0, and this should not be processed.

// Output
// Print either yes or no in a line for each dataset, in the order of the input. If all words in the dataset can be considered to be ordered lexicographically, print yes. Otherwise, print no.

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

struct edge {
    int from, to;
    edge(int from = -1, int to = -1): from(from), to(to) {}
};

// aがbより小さいなら，必要な辺を返す
// (ab, a)みたいなのはfalse
// (a, ab)は{-1,-1}
// (aa,ab)は{a,b}
pair<bool, edge> find_edge(string a, string b) {
    // (a, ab), (ab, a)の場合
    int na = a.size(), nb = b.size();
    int min_n = min(na, nb);
    if (a.substr(0,min_n) == b.substr(0,min_n)) return make_pair(na<=nb,edge());

    // (aa,ab)の場合
    rep(i,0,min_n) {
        if (a[i] != b[i]) return make_pair(true, edge(a[i]-'a', b[i]-'a'));
    }
}

auto solve (int n, V<string>& s) -> bool {
    VV<int> G(26);
    V<int> edge_in(26);
    // グラフを構築する
    rep(i,0,n) rep(j,i+1,n) {
        auto p = find_edge(s[i],s[j]);
        if (!p.first) return false;

        auto e = p.second;
        if (e.from < 0) continue;
        
        assert(e.from >= 0 && e.to >= 0);
        G[e.from].push_back(e.to);
        edge_in[e.to]++;
    }

    // グラフがDAGかどうかを判定
    // 結果を返す
    queue<int> q;
    rep(i,0,26) if (edge_in[i] == 0) q.push(i);
    while (!q.empty()) {
        auto tp = q.front(); q.pop();
        if (edge_in[tp] != 0) return false;
        for (auto e:G[tp]) {
            edge_in[e]--;
            if (edge_in[e] == 0) q.push(e);
        }
    }
    rep(i,0,26) if (edge_in[i] != 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n; 
    while(cin >> n) {
        dbg(n);
        if (n == 0) break;
        V<string> s(n);
        rep(i,0,n) cin >> s[i];

        // solve
        auto ans = solve(n,s);

        // output
        cout << (ans?"yes":"no") << endl;
    }
    return 0;
}