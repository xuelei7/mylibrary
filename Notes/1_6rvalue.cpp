// 右辺値参照・ムーブセマンティクス
#include <string>
#include <utility>

struct Foo{} ;
int f() { return 0 ; }

int main()
{
    // 右辺値と左辺値
    int i = 0;

    i;      // 名前付きオブジェクトは左辺値
    0;      // リテラル値は右辺値

    Foo foo ;

    foo;      // 名前付きオブジェクトは左辺値
    Foo();  // コンストラクタの戻り値は右辺値

    f();    // 関数の戻り値は右辺値



    // 右辺値参照と左辺値参照
    int x = 0;

    // lvalue reference
    int& lvalue_ref_1 = x;              // OK
    int& lvalue_ref_2 = 0;              // Error 右辺値を左辺値参照で束縛している

    // rvalue reference
    int&& rvalue_ref_1 = x;             // Error 左辺値を右辺値参照で束縛している
    int&& rvalue_ref_2 = 0;             // OK

    // const lvalue reference
    const int& const_lvalue_ref_1 = x;    // OK
    const int& const_lvalue_ref_2 = 0;    // OK constな左辺値参照は右辺値を束縛できる



    // ムーブ move
    std::string str = "Hello, world!";
    // 何も起こらない
    std::move(str);
    // 実際に y に x がムーブされる
    std::string y = std::move(str);



    // ムーブセマンティクス
    // ムーブセマンティクスが必要とされる場面として、コピーに高いコストがかかる場合をあげる。

    // ムーブコンストラクタ・ムーブ代入演算子
    class large_class {
    private:
        char* ptr ;
    public:
        // ムーブコンストラクタ
        large_class(large_class&& r)
        {
            // ポインタの挿げ替え
            ptr = r.ptr;
            // 元のオブジェクトはnullptrに
            r.ptr = nullptr;
        }
        // ムーブ代入演算子
        large_class& operator=(large_class&& r)
        {
            // 既存バッファの破棄
            delete [] ptr;
            // ポインタの挿げ替え
            ptr = r.ptr;
            // 元のオブジェクトはnullptrに
            r.ptr = nullptr;
            return *this;
        }
    };
}