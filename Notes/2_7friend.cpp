// friend宣言できる対象を拡張

// C++03までのfriend宣言は、直接のクラス型のみを指定できた。
// C++11ではfriend宣言が拡張され、テンプレートパラメータ、
// および型の別名もまたfriend宣言できるようになった。

template <class Derived>
class base {
    // 派生クラスから、baseクラスのprivate機能にアクセスできるようにする
    friend Derived;

    // privateなデフォルトコンストラクタ
    base() {}
};

class derived : public base<derived> {
};
