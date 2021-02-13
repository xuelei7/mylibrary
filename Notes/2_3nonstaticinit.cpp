// 非静的メンバ変数の初期化

// 非静的メンバ変数の定義時に、=演算子もしくは{ }波カッコ初期化子による
// コンストラクタ構文で、初期化式を記述できる。

#include <string>
struct Person {
  int id = 3;
  std::string name = "Alice";
  std::string description { "Hello everyone." };
};
