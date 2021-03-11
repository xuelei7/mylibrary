// 問題名 Zero division checker
// 森下さんは困っていました... 姉原さんにプログラムを書いてもらったのですが、そのプログラムがクラッシュするのです。

// 姉原さんに書いてもらったのは、逆ポーランド記法の式を読んで、その計算結果を出力するプログラムで、クラッシュログによると、 0 で割り算をしてしまったのが原因のようです。これは、森下さんが間違った式を入力してしまったからかもしれませんし、もしかしたら、もしかしたら、姉原さんの書いたプログラムにバグがあるのかもしれません。

// 姉原さんの書いたプログラムを読んでみようと思いましたが、姉原さんのプログラムはアセンブリというよくわからないことばで書かれているようで、見ているだけで頭がガンガンしてきます。

// そこで、森下さんはあなたに、式が間違っていないかどうか調べるプログラムを書いてもらうことにしました。式が間違っている、とは、その式に従って計算すると、 0 での割り算をしてしまう可能性のあることをいいます。

// なお、姉原さんの書いたコードはとてもふるいコンピューターで動くもので、加減乗除は整数で行い、結果は 8 bit の符号なし整数として保存されます。 例えば、255+1 は 0 になってしまうし、3/2 は 1 になります。

// あ、姉原さんにはないしょですよ。

// (参考)逆ポーランド記法で表された式を計算する、擬似コード
// s = 空のスタック
// n = 式の要素数
// for i in 1..n:
//   if 式のi番目の要素が整数:
//     sにその整数をプッシュする
//   if 式のi番目の要素が変数:
//     sにその変数の値をプッシュする
//   if 式のi番目の要素が演算子:
//     sから値をポップし、bとする
//     sから値をポップし、aとする
//     if 演算子が'+':
//       r = (a + b) % 256 とする
//     if 演算子が'-':
//       r = (a - b + 256) % 256 とする
//     if 演算子が'*':
//       r = (a * b) % 256 とする
//     if 演算子が'/':
//       r = (a / b) % 256 とする
//     sにrをプッシュする
// sから値をポップし、式の計算結果とする
// Input
// m
// name1 lb1 ub1
// ...
// namem lbm ubm
// n
// e1 e2 ... en
// 0≤m≤100

// 0≤lbi≤ubi≤255

// 1≤namei(1≤i≤m)の長さ≤20

// 1≤n≤100

// m は変数の数、namei, lbi, ubi はそれぞれ変数iの名前、下限、上限を表します。

// n は式に含まれる要素の数を表し、ei は式の i 番目の要素を表します。

// 各変数は式の中に高々1回しか現れません。

// Output
// 式が間違っているときにはerror、間違っていないときにはcorrectと一行で出力してください。

