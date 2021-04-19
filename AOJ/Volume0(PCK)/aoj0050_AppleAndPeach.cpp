// りんごと桃
// 福島県は果物の産地としても有名で、その中でも特に桃とりんごは全国でも指折りの生産量を誇っています。ところで、ある販売用の英文パンフレットの印刷原稿を作ったところ、手違いでりんごに関する記述と桃に関する記述を逆に書いてしまいました。

// あなたは、apple と peach を修正する仕事を任されましたが、なにぶん面倒です。１行の英文を入力して、そのなかの apple という文字列を全て peach に、peach という文字列を全てapple に交換した英文を出力するプログラムを作成してください。

// Input
// 英文（半角英数字、空白、記号を含む）が１行に与えられます。入力される文字列の長さは 1000 以下です。

// Output
// apple とpeach という文字列を交換した英文を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string apple = "apple";
    string peach = "peach";
    getline(cin,s);
    for (int i = 0; i + 4 < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            bool isapple = 1;
            bool ispeach = 1;
            for (int j = 0; j < 5; j++) {
                if (s[i+j] != apple[j]) isapple = 0;
                if (s[i+j] != peach[j]) ispeach = 0;
            }
            if (isapple) {
                for (int j = 0; j < 5; j++) s[i+j] = peach[j];
                i+=4;
            } else if (ispeach) {
                for (int j = 0; j < 5; j++) s[i+j] = apple[j];
                i+=4;
            }
        }
    }
    cout << s << endl;
    return 0;
}