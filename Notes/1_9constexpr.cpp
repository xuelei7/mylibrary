// constexpr: constant expression (定数式)
// コンパイル時に値が決定する定数、
// コンパイル時に実行される関数、
// コンパイル時にリテラルとして振る舞うクラス
// を定義できる

// constexpr変数は、書き換えることができない定数
constexpr int num = 42;


// constexpr関数もまた、
//    その内部で変数の書き換えはできず
//    戻り値の型をvoidにすることもできない
//    変数の書き換えをせずに、計算した結果を返す必要がある
//    return文ひとつのみで処理を行わなければならない

constexpr int min(int a, int b)
{
    // 条件分岐には条件演算子?:を使用する
    return a < b ? a : b;
}

constexpr int factorial(int n)
{
    // ループには再帰を使用する
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main()
{
  constexpr int min_val = min(2, 3);
  static_assert(min_val == 2, "result must be 2");

  constexpr int factorial_val = factorial(5);
  static_assert(factorial_val == 120, "result muse be 120");
}