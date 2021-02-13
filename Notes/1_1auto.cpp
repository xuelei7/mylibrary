// auto: 型推論
#include <iostream>
#include <memory>
#include <initializer_list>

// 名前空間スコープでの変数宣言
auto v = { 1, 7, 3, 2, 0, 5, 0, 8, }; 

int main() {
    auto i = 0;        // i は int 型
    const auto l = 0L;                  // l は const long 型
    auto& r = i;                        // r は int& 型
    auto s = "";                        // s は const char* 型
    auto p = std::make_pair(1, 'c');    // p は std::pair<int, char> 型
    auto q = std::make_shared<int>(42); // q は std::shared_ptr<int> 型
    auto z = { 1.0, 2.0, 3.0, };        // z は std::initializer_list<double> 型
    
    auto f = []{};     // f は 引数を取らずに値を返さない operator() を持つユニークなクロージャ型

    return 0;
}
