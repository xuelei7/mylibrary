// 委譲コンストラクタ (delegating constructors)

// コンストラクタから、同じクラスの他のコンストラクタに処理を委譲する機能

class X {
  int i_;
public:
  X(int i) : i_(i) {} // (1) : int型のパラメータを受け取るコンストラクタ

  X() : X(42) {}      // (2) : デフォルトコンストラクタ。
                      //       (1)のコンストラクタに初期値を渡して初期化処理を委譲する
};