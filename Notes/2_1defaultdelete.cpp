// 関数のdefault／delete宣言

class X {
public:
  // 暗黙定義される挙動をする、
  // 仮想関数のデストラクタを定義する
  virtual ~X() = default;

  // 暗黙定義されるデフォルトの挙動をする、
  // インライン関数のコピーコンストラクタを定義する
  inline X(const X&) = default;
};

class Y {
public:
  // コピーは禁止するが、ムーブは許可する
  Y(const Y&) = delete;
  Y& operator=(const Y&) = delete;

  // 特殊メンバ関数を明示的に定義もしくはdeleteした場合、
  // それ以外の特殊メンバ関数は明示的に定義もしくはdefault宣言しなければ
  // 暗黙定義されない
  Y(Y&&) = default;
  Y() = default;
  Y& operator=(Y&&) = default;
};