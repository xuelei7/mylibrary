// 多角形の面積
// １つの円に内接する２つの多角形の頂点情報を入力とし、それらの面積の大小関係を出力するプログラムを作成してください。

// X 角形の各頂点には反時計回りに 1 から X まで番号が振ってあるものとします（図は、X = 4 の場合の例を示しています）。ただし、与えられる多角形は円の中心を内部に含むものとし、頂点 i の位置に関するデータは、頂点 i から頂点 i+1 まで反時計回りに計った中心角の角度 v (1 ≤ v < 180 の整数) で与えられます。また、出力する大小関係については、第１の多角形の面積が大きい場合は 1 (半角数字)、第２の多角形の面積が大きい場合は 2 (半角数字)、それぞれの面積が等しい場合は 0 (半角数字) と出力してください。


// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。 各データセットは以下の形式で与えられます。

// m
// v1
// v2
// :
// vm−1
// n
// v1
// v2
// :
// vn−1
// １行目に第１の多角形の頂点の数 m (3 ≤ m ≤ 50)、続く m−1 行に第１の多角形の頂点 i の情報 vi (1 ≤ vi < 180) が与えられます。

// 続く行に第２の多角形の頂点の数 n (3 ≤ n ≤ 50)、続く n−1 行に第２の多角形の頂点 i の情報 vi (1 ≤ vi < 180) が与えられます。

// データセットの数は 200 を超えません。

// Output
// データセットごとに大小関係（半角数字）を１行に出力します。

#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
#define EPS 1e-10
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        double areaA = 0;
        double degree = 0;
        for (int i = 0; i < n-1; i++) {
            double k;
            cin >> k;
            degree += k;
            areaA += sin(k/180*PI);
        }
        areaA += sin((360-degree)/180*PI);
        cin >> n;
        degree = 0;
        double areaB = 0;
        for (int i = 0; i < n-1; i++) {
            double k;
            cin >> k;
            degree += k;
            areaB += sin(k/180*PI);
        }
        areaB += sin((360-degree)/180*PI);
        if (abs(areaA-areaB) < EPS) {
            cout << 0 << endl;
        } else if (areaA > areaB) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
    return 0;
}