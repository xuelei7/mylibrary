// 明示的な型変換演算子のオーバーロード

// 型変換演算子のオーバーロードをする際、operatorキーワードの前に
// explicitを付加することで、その型変換演算子は明示的な型変換が行
// われる文脈でのみ呼び出されるようになる

struct X {
    constexpr explicit operator bool() const
    {
        return true;
    }
};

int main()
{
    constexpr X x {};

  //bool b1 = x;                    // コンパイルエラー : boolへの暗黙変換
                                    // bool型パラメータを持つ関数への引数渡し、
                                    // bool型戻り値を持つ関数からの戻り値も同様

    bool b2 = (bool)x;              // OK : キャストによる明示的な型変換
    bool b3 = static_cast<bool>(x); // OK : キャストによる明示的な型変換
    bool b4 = bool(x);              // OK : 関数スタイルのキャスト
  //bool b5 = x == true;            // コンパイルエラー : bool値との比較は暗黙の型変換
    bool b6 = !x;                   // OK : 否定演算子によるboolへの変換後の反転
    bool b7 = !!x;                  // OK : 否定演算子を2回適用することでboolに型変換
    bool b8 = x && true;            // OK : 論理積演算子によるboolへの型変換

    if (x) {} // OK : if文による条件式のboolへの変換

    bool b9 = x ? true : false;     // OK : 条件演算子によるboolへの型変換

    static_assert(x, "x must be bool");  // OK : 条件式のboolへの型変換
}