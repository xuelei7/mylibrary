// ABC Gene
// 文字列 ABC で表される遺伝子配列がある。あなたは次の操作を何回か行い、この遺伝子配列を書き換えていくことができる。

// 文字 A，B，C のうち 1 つを選ぶ。これを x とおく。遺伝子配列に含まれるすべての x をそれぞれ ABC へ同時に置き換える。
// A，B，C だけからなる文字列 S が与えられる。遺伝子配列を S に一致させられるか判定せよ。

// Constraints
// 1 ≤ |S| ≤ 5,000
// S は A，B，C だけからなる。
// Input Format
// 入力は以下の形式で標準入力から与えられる。

// S
// Output Format
// 遺伝子配列を S に一致させられるならば Yes を、一致させられないならば No を一行に出力せよ。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') a++;
        else if (s[i] == 'B') b++;
        else c++;
    }
    while (a + b + c > 3) {
        char change = 'x';
        int mi = min({a,b,c});
        if (a < b && a < c) {
            change = 'A';
            b -= a;
            c -= a;
        } else if (b < a && b < c) {
            change = 'B';
            a -= b;
            c -= b;
        } else if (c < a && c < b) {
            change = 'C';
            a -= c;
            b -= c;
        } else break;
        string ss = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 3 <= s.size() && s.substr(i,3) == "ABC") {
                ss += change;
                i += 2;
                cnt++;
            } else {
                ss += s[i];
            }
        }
        if (cnt != mi) break;
        s = ss;
        // cout << s << endl;
    }
    if (s != "ABC") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}