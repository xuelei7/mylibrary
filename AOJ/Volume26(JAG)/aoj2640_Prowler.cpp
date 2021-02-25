// A さんと B 君は，N × M の長方形のマス目状の地域に住んでいる．各マス目は道か壁か家のどれかである．この地域は，道が複雑で入り組んでいるので痴漢被害がよく起こることで有名であるため，この地域と外部との境界は全て壁で囲まれており，隔離されている．

// B 君はなんとなく気が向いたので，A さんの家を眺めに行くことにした．しかし，不幸なことにB 君は明らかに怪しい顔をしているので，A さんの家に行く途中に少しでも痴漢の疑いがあるような行動を取ったらすぐに捕まってしまうだろう．特に，右手を壁から離して歩くことは絶対にやってはならない．B 君は，一瞬たりとも右手を離すことなく，A さんの家に辿り着くことが出来るだろうか？

// B 君はつねに上下左右いずれかの方向を向いていて，B 君の右手が届く範囲はB 君の向いている方向に対して正面，斜め右前，右，斜め右後ろの4 マスのみである．B 君は，次のいずれかの行動を繰り返す．ただし，これらを同時に行うことは出来ない．

// 前方に壁がない場合，1 マス進む．
// 向いている方向を90 度右に変える．
// 向いている方向を90 度左に変える．
// 右手が接するマスを変える．ただし，この時にB 君は右手を離すことが出来ないので，変更前のマスと変更後のマスの間には共通した点を持っていなくてはならない．
// Input
// 入力は以下の形式で与えられる．

// N M
// S1
// S2
// :
// SN
// Si (1 ≤ i ≤ N) は， M 文字の文字列で各文字は次を表す．

// "^"，"v"，"<"，">" は B 君の最初の位置と最初に向いている方向（上下左右の向き）を表す．
// "." は，何もないマスである．B 君は，このマスの上を移動することができる．
// "#" は，壁を表す．壁の上を移動することは出来ない．
// "G" は A さんの家の位置を表す．B 君は，A さんの家にたどり着くまで移動を繰り返す．
// Constraints
// 1 ≤ N ≤ 50
// 1 ≤ M ≤ 50
// 入力には，文字 "^"，"v"，"<"，">" のうちいずれかが必ず一つのみ現れる．
// 同様に，入力には，文字 "G" が必ず一つのみ現れる．
// 初期状態では，B 君が向いている方向から右の壁にB 君の右手が接している．
// Output
// 一度も右手を離さずにA さんの家に辿り着くことが出来る場合には，A さんの家にたどり着くまでに通った異なるマスの数の最小値を出力せよ．A さんの家に辿り着くことが出来ない場合には，-1 を出力せよ．
