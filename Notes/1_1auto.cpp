// auto: 型推論
#include <iostream>
#include <memory>
#include <initializer_list>

// 名前空間スコープでの変数宣言
auto v = { 1, 7, 3, 2, 0, 5, 0, 8, }; 

std::unique_ptr<int> create_unique_ptr(int i)
{
    // new 式の型名指定部
    return std::unique_ptr<int>(i != 0 ? new auto(i) : nullptr);  // new auto(i) は int* 型
}

int main() {
    auto i = 0;        // i は int 型
    const auto l = 0L;                  // l は const long 型
    auto& r = i;                        // r は int& 型
    auto s = "";                        // s は const char* 型
    auto p = std::make_pair(1, 'c');    // p は std::pair<int, char> 型
    auto q = std::make_shared<int>(42); // q は std::shared_ptr<int> 型
    auto z = { 1.0, 2.0, 3.0, };        // z は std::initializer_list<double> 型
    auto f = []{};     // f は 引数を取らずに値を返さない operator() を持つユニークなクロージャ型


    // CV修飾（const、volatile）やポインタ・参照修飾（*、&、&&）も可能
    const auto& cri = i;        // cri は const int& 型
    const auto* cpi = &i;       // cpi は const int* 型


    // for 文の初期化文での変数宣言
    for (auto it = v.begin(), e = v.end(); it != e; ++it) {    // it と e は const int* 型
        // if 文の条件部での変数宣言
        if (auto ptr = create_unique_ptr(*it)) {               // ptr は std::unique_ptr<int> 型
            std::cout << *ptr << ", ";
        } else {
            std::cout << "null, ";
        }
    }

    std::cout << std::endl;

    // 範囲 for 文の宣言部
    for (auto&& elem : { 2, 3, 7, }) {                            // elem は const int& 型
        std::cout << elem << ", ";
    }

    std::cout << std::endl;

    return 0;
}
