// 一様初期化 uniform initialization
#include <iostream>
struct X {
    X(int) {}
};

int main()
{
    // 従来のコンストラクタ呼び出し
    X x1(0);
    X x2 = 0;

    // 一様初期化構文によるコンストラクタ呼び出し
    X x3 {0};
    X x4 = {0};

}