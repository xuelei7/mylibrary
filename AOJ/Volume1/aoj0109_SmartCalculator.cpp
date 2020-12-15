// スマート計算機
// 式を入力すると、その値を計算して出力するプログラムを作成してください。

// 式は数値、演算記号、かっこからなり、= で終わります。
// 演算記号は +, -, *, / の4つで、それぞれ、加算、減算、乗算、除算を表します。
// 四則演算の優先順位は通常の計算と同じとします。すなわち乗算・除算は加算・減算よりも優先され、 同じ優先順位なら左から計算が行われます。
// 0での割り算は発生しないものとします。
// 演算はすべて整数で行い、小数点以下切捨てとします。
// 入力される式の長さは 100 文字以内で、計算途中の値が　-1 × 109　より小さくなることはなく 109　を超えません。
// Input
// 複数のデータセットが与えられます。最初にデータセットの数 n (n ≤ 50) が与えられます。続いて n 行の数式（空白を含まない文字列）が与えられます。

// Output
// 各データセットについて、計算結果を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

string s;
int i;
int Expression();
int Term();
int Factor();
int No(int old);

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        i = 0;
        cout << Expression() << endl;
    }
    return 0;
}
int Expression() {
    int res = Term();
    while (1) {
        if (s[i] == '+') {
            i++;
            res += Term();
        } else if (s[i] == '-') {
            i++;
            res -= Term();
        } else break;
    }
    return res;
}
int Term() {
    int res = Factor();
    while (1) {
        if (s[i] == '*') {
            i++;
            res *= Factor();
        } else if (s[i] == '/') {
            i++;
            res /= Factor();
        } else break;
    }
    return res;
}
int Factor() {
    int res = 0;
    if (s[i] == '(') {
        i++;
        res = Expression();
        i++;
    } else {
        res = No(i);
    }
    return res;
}
int No(int old) {
    while (isdigit(s[i])) i++;
    // cout << old << " " << i << " " << stoi(s.substr(old,i-old)) << endl;
    return stoi(s.substr(old,i-old));
}