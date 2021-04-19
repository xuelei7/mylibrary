// 本の索引
// 本の最後には索引が設けられています。本の中から抽出された「語句」と「ページ番号」の組を読み取り、本の索引として「語句」とその語句が表れる「ページ番号のリスト」を出力するプログラムを作成してください。

// Input
// 空白で区切られた語句とページ番号の組が、複数行にわたって与えられます。1 つの語句の長さは 30 文字以内で、ページ番号は 1,000 以下です。入力に含まれる語句とページ番号の組は 100 以下で、1 つの語句は同じページ番号に複数回現れません。

// Output
// 語句とページ番号の列の組を、語句のアルファベット順に出力してください。語句とページ番号の列をそれぞれ１行に出力してください。ページ番号は小さい順(昇順)とし空白で区切ってください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    vector<pair<string,int>> v;
    while (cin >> s >> n) {
        v.push_back({s,n});
    }
    sort(v.begin(),v.end());
    s = "";
    vector<int> tmp;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first != s) {
            s = v[i].first;
            for (int j = 0; j < tmp.size(); j++) {
                cout << tmp[j] << " \n"[j == tmp.size() - 1];
            }
            cout << s << endl;
            tmp.clear();
            tmp.push_back(v[i].second);
        } else tmp.push_back(v[i].second);
    }
    for (int j = 0; j < tmp.size(); j++) {
        cout << tmp[j] << " \n"[j == tmp.size() - 1];
    }
    return 0;
}