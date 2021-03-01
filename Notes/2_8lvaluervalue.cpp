// メンバ関数の左辺値／右辺値修飾

// 違う修飾を使い分けることができる

#include <iostream>

struct X {
    int f() &       // *thisが非constな左辺値である場合に呼び出される
    { return 1; }

    int f() const & // *thisがconstな左辺値である場合に呼び出される
    { return 2; }

    int f() &&      // *thisが右辺値である場合に呼び出される
    { return 3; }
};

int main()
{
    X x;
    const X cx;

    std::cout << x.f() << std::endl;   // 1
    std::cout << cx.f() << std::endl;  // 2
    std::cout << X().f() << std::endl; // 3
}