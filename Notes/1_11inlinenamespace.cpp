// インライン名前空間
// inline namespace

namespace my_namespace {
    inline namespace features {
        void f() {}
    }
}

int main()
{
    my_namespace::features::f();
    my_namespace::f();           // features名前空間は省略できる
}