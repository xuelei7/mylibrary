// うるう年
// 西暦 a 年から b 年までの間にあるすべてのうるう年を出力するプログラムを作成してください。

// うるう年の条件は、次のとおりとします。ただし、0 < a ≤ b < 3,000 とします。与えられた期間にうるう年がない場合には "NA"と出力してください。

// 西暦年が 4 で割り切れる年であること。
// ただし、100 で割り切れる年はうるう年としない。
// しかし、400 で割り切れる年はうるう年である。
// Input
// 複数のデータセットが与えられます。各データセットの形式は以下のとおりです：

// a b
// a, b がともに 0 のとき入力の終了とします。データセットの数は 50 を超えません。

// Output
// データセットごとに、西暦または NA を出力してください。

// データセットの間に１つの空行を入れてください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    vector<pair<int,int>> p;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        p.push_back({a,b});
    }
    for (int i = 0; i < p.size(); i++) {
        a = p[i].first, b = p[i].second;
        vector<int> v;
        for (int i = a; i <= b; i++) {
            if (i % 400 == 0) v.push_back(i);
            else if (i % 100 == 0) ;
            else if (i % 4 == 0) v.push_back(i);
        }
        if (v.size() == 0) cout << "NA" << endl;
        else {
            for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
        }
        if (i != p.size() - 1)
            cout << endl;
    }
    return 0;
}