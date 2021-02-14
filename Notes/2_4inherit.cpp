// 継承コンストラクタ(inheriting constructors)
// 基底クラスで定義したコンストラクタ群を、派生クラスでそのまま使用できるようにするための糖衣構文

#include <string>

struct Base1 {
    Base1() {}
    Base1(int) {}
};

struct Base2 {
    Base2() {}
    Base2(const std::string&) {}
};

struct Derived : Base1, Base2 {
    // Base1とBase2のコンストラクタを、Derivedで暗黙的に宣言する
    using Base1::Base1;
    using Base2::Base2;

    // Derived(), Derived(int), Derived(const std::string&)が暗黙宣言される

    // 一部のコンストラクタを明示的に宣言することも可能
    Derived(const std::string& s) : Base2::Base2(s) {}
};

int main()
{
    Derived d1(3);       // OK
    Derived d2("hello"); // OK
}