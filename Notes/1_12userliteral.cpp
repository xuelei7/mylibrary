// ユーザー定義リテラル(User-defined literals)

// operator"" サフィックス名

// ユーザー定義リテラルは、以下の 4 種類が使用できる。
//    整数リテラル
//    浮動小数点リテラル
//    文字列リテラル（通常の文字列、ワイド文字列、char16_t 文字列、char32_t 文字列）
//    文字リテラル（通常の文字、ワイド文字、char16_t 文字、char32_t 文字）


#include <string>

// アンダースコアで始まらないユーザー定義リテラルのサフィックス名は、標準C++の将来の
// 拡張のために予約されている。
// このため、ユーザー定義リテラルを定義する場合、サフィックス名はアンダースコア _ で
// 始める必要がある。
std::string operator"" _s(const char* str, std::size_t length)
{
    return std::string(str, length);
}

auto x = "hello"_s; // xの型はstd::string