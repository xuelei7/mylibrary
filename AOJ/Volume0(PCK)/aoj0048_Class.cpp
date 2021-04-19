// 階級
// ボクシングは体重によって階級が分けられています。体重を読み込んで、その階級を出力するプログラムを作成してください。階級と体重の関係は以下の表のとおりとします。

// 階級	体重（kg）
// light fly	48.00kg 以下
// fly	48.00kg 超 51.00kg 以下
// bantam	51.00kg 超 54.00kg 以下
// feather	54.00kg 超 57.00kg 以下
// light	57.00kg 超 60.00kg 以下
// light welter	60.00kg 超 64.00kg 以下
// welter	64.00kg 超 69.00 kg 以下
// light middle	69.00kg 超 75.00 kg 以下
// middle	75.00kg 超 81.00 kg 以下
// light heavy	81.00kg 超 91.00 kg 以下
// heavy	91.00kg 超

// Input
// 入力は複数のデータセットからなります。各データセットとして、体重を表す１つの実数 w (40 ≤ w ≤ 150) が１行に与えられます。データセットの数は 50 を超えません。

// Output
// データセットごとに、対応する階級を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

int main() {
    double n;
    while (cin >> n) {
        if (n <= 48.0) cout << "light fly" << endl;
        else if (n <= 51.0) cout << "fly" << endl;
        else if (n <= 54.0) cout << "bantam" << endl;
        else if (n <= 57.0) cout << "feather" << endl;
        else if (n <= 60.0) cout << "light" << endl;
        else if (n <= 64.0) cout << "light welter" << endl;
        else if (n <= 69.0) cout << "welter" << endl;
        else if (n <= 75.0) cout << "light middle" << endl;
        else if (n <= 81.0) cout << "middle" << endl;
        else if (n <= 91.0) cout << "light heavy" << endl;
        else cout << "heavy" << endl;
    }
    return 0;
}