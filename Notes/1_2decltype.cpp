// decltype: 型推論

// 使用例
template<typename T, typename U>
auto add(const T& lhs, const U& rhs)
-> decltype(lhs + rhs);               // add の戻り値型は lhs + rhs の式の型

struct S {

    using U = decltype(add('a', 'b'));    // S::U は int 型の別名

} s;

decltype(s)::U l{};                     // l は S::U 型（つまり int 型）

int main() {
    // 使用例
    int i = 0;
    decltype(i) j = 0;                      // j は int 型
    decltype(i)* p = &i;                    // p は int* 型
    decltype((i)) k = i;                    // k は int& 型（変数名 i の周りの余分な丸括弧に注意）

    return 0;
}