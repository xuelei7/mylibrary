// Weight

// 祖母が天秤を使っています。天秤は、二つの皿の両方に同じ目方のものを載せると釣合い、そうでない場合には、重い方に傾きます。10 個の分銅の重さは、軽い順に 1g, 2g, 4g, 8g, 16g, 32g, 64g, 128g, 256g, 512g です。

// 祖母は、「1kg くらいまでグラム単位で量れるのよ。」と言います。「じゃあ、試しに、ここにあるジュースの重さを量ってよ」と言ってみると、祖母は左の皿にジュースを、右の皿に 8g と64g と128g の分銅を載せて釣合わせてから、「分銅の目方の合計は 200g だから、ジュースの目方は 200g ね。どう、正しいでしょう？」と答えました。

// 左の皿に載せる品物の重さを与えるので、天秤で与えられた重みの品物と釣合わせるときに、右の皿に載せる分銅を軽い順に出力するプログラムを作成して下さい。ただし、量るべき品物の重さは、すべての分銅の重さの合計 (=1023g) 以下とします。

// Input
// 複数のデータセットが与えられます。各データセットに、左の皿に載せる品物の重さが１行に与えられます。入力の最後まで処理して下さい。データセットの数は 50 を超えません。

// Output
// 各データセットに対して、右の皿に載せる分銅（昇順）を１つの空白で区切って、１行に出力して下さい。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> v;
        for (int i = 0; i < 10; i++) {
            if ((n >> i) & 1) v.push_back(1 << i);
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " \n"[i == v.size()-1];
        }
    }
    return 0;
}