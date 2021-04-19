// BMI
// 肥満は多くの成人病の原因として挙げられています。過去においては、一部の例外を除けば、高校生には無縁なものでした。しかし、過度の受験勉強等のために運動不足となり、あるいはストレスによる過食症となることが、非現実的なこととはいえなくなっています。高校生にとっても十分関心を持たねばならない問題になるかもしれません。

// そこで、あなたは、保健室の先生の助手となって、生徒のデータから肥満の疑いのある生徒を探し出すプログラムを作成することになりました。

// 方法は BMI (Body Mass Index) という数値を算出する方法です。BMIは次の式で与えられます。



// BMI = 22 が標準的で、25 以上だと肥満の疑いがあります。

// 各々の生徒の体重、身長の情報から BMI を算出し、25 以上の生徒の学籍番号を出力するプログラムを作成してください。

// 入力
// 入力は以下の形式で与えられます。

// s1,w1,h1
// s2,w2,h2
// ...
// ...
// si (1 ≤ si ≤ 2,000)、wi (1 ≤ wi ≤ 200)、hi (1.0 ≤ hi ≤ 2.0) はそれぞれ、i 番目の生徒の学籍番号（整数）、体重（実数）、身長（実数）を表します。

// 生徒の数は 50 を超えません。

// 出力
// BMI が 25 以上の生徒の学籍番号を、入力された順番にそれぞれ１行に出力します。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.size(); i++) if (s[i] == ',') s[i] = ' ';
        stringstream ss(s);
        int num;
        double w,h;
        ss >> num >> w >> h;
        if (w / h / h >= 25.0) cout << num << endl;
    }
    return 0;
}