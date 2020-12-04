// 泥棒
// 宝物がたくさん収蔵されている博物館に、泥棒が大きな風呂敷を一つだけ持って忍び込みました。盗み出したいものはたくさんありますが、風呂敷が耐えられる重さが限られており、これを超えると風呂敷が破れてしまいます。そこで泥棒は、用意した風呂敷を破らず且つ最も価値が高くなるようなお宝の組み合わせを考えなくてはなりません。

// 風呂敷が耐えられる重さ W、および博物館にある個々のお宝の価値と重さを読み込んで、重さの総和が W を超えない範囲で価値の総和が最大になるときの、お宝の価値総和と重さの総和を出力するプログラムを作成してください。ただし、価値の総和が最大になる組み合わせが複数あるときは、重さの総和が小さいものを出力することとします。

// Input
// 複数のデータセットが与えられます。各データセットは以下のような形式で与えられます。

// W
// N
// v1,w1
// v2,w2
// :
// vN,wN
// １行目に風呂敷の耐えられる重さを表す整数 W (W ≤ 1,000)、２行目にお宝の数 N (1 ≤ N ≤ 1,000) が与えられます。続く N 行に i 番目のお宝の価値を表す整数 vi (0 ≤ vi ≤ 10,000) とその重さを表す整数 wi (0 ≤ wi ≤ W) の組がそれぞれ１行に与えられます。

// W が 0 のとき入力の最後とします。データセットの数は 50 を超えません。

// Output
// 各データセットに対して以下のように出力して下さい。

// Case データセットの番号:
// 風呂敷に入れたお宝の価値総和
// そのときのお宝の重さの総和

// string, utils

#include <bits/stdc++.h>
using namespace std;
vector<int> split_string_to_int(string s, char c) {
    vector<int> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
            left_side = i + 1;
        }
        if (i == s.size() - 1) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i+1-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
        }
    }
    return v;
}

int dp[1010][1010];
pair<int,int> knapsack(int W, int N, vector<int> v, vector<int> w) {
    for (int i = 0; i < 1010; i++) memset(dp[i],0,sizeof(dp[i]));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (j + w[i] <= W) {
                dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
            }
        }
    }
    int miw = 1e9, mxv = 0;
    for (int i = 0; i <= W; i++) {
        if (dp[N][i] > mxv) {
            mxv = dp[N][i];
            miw = i;
        }
    }
    if (mxv == 0) miw = 0;
    return {mxv, miw};
}

int main() {
    int W,N;
    int cnt = 1;
    while (cin >> W) {
        if (W == 0) break;
        cin >> N;
        vector<int> v(N),w(N);
        string s;
        vector<int> tmp;
        for (int i = 0; i < N; i++) {
            cin >> s;
            tmp = split_string_to_int(s,',');
            v[i] = tmp[0];
            w[i] = tmp[1];
        }
        cout << "Case " << cnt++ << ":" << endl;
        pair<int,int> p = knapsack(W,N,v,w);
        cout << p.first << "\n" << p.second << "\n";
    }
    return 0;
}