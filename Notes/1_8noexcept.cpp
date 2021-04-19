// noexcept
// 例外を送出する可能性がある関数にはnoexcept(false)を指定し、
// 例外を送出する可能性がない関数にはnoexcept(true)もしくはnoexceptを指定する

// noexceptは、代表的には以下の2つの用途で使用できる：

// 1. パフォーマンス向上
//   例外を送出しないという保証があることで、コンパイラは例外送出によるスタック
//   巻き戻しのためのスタックを確保する必要がなくなる

// 2. 例外を決して送出しない強い例外安全性の保証(No-throw guarantee)


struct X {
    int f() const noexcept; // noexcept例外仕様, f()は例外を創出しない

    // 外側はnoexcept例外仕様、内側はnoexcept演算子。
    // メンバ関数関数f()が例外を送出しない場合、関数g()もまた例外を送出しない
    int g() const noexcept(noexcept(f()))
    { return f(); }
};