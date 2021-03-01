// キャンディーとクラス旗
// 3年C組では、平成19年11月10日の体育祭で使用する「クラス旗」を、将来のクラス会の時にも使うことにしました。そこで「クラス旗」を保管する生徒を決めるために、先生が先日差し入れてくれた大量のキャンディーを使って次のようなゲームを行うことにしました。

// 各生徒は生徒番号の順に１個ずつキャンディーを取ります。
// 一巡してもキャンディーが残っていたら、最初の生徒番号の人から順々にキャンディーを取り続けます。
// 最後のキャンディーを取った人が「クラス旗」を保管する生徒になります。
// 3年C組のクラスの人数は 39 人です。彼らの生徒番号は 3C01 から 3C39 です。例えば、キャンディーの数が 50 個の場合、クラス全員が１個目のキャンディーを取り終えると、キャンディーの残りは 11 個となります。それを再び生徒番号順に取ると、最後の 1 個は、3C11 の生徒が取ることとなります。すなわち 3C11 の生徒が「クラス旗」を保管する生徒となります。

// キャンディーの個数を入力とし、「クラス旗」を保管する生徒の生徒番号を出力するプログラムを作成してください。

// Input
// 複数のテストケースが与えられます。各テストケースは以下の形式で与えられます。各テストケースとして、キャンディーの個数を表す整数 a (1 ≤ a ≤ 10000) が１行に与えられます。入力の最後(EOF)まで処理してください。

// データセットの数は 20 を超えません。

// Output
// 各テストケースごとに、「クラス旗」を保管する生徒の生徒番号（半角英数字）を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        n--;
        int k = n % 39;
        k++;
        cout << "3C" << setw(2) << setfill('0') << k << endl;
    }
    return 0;
}