// 分割統治
// 太郎さんと花子さんと次郎さんは3人で JAG 王国を統治している．JAG 王国には N 個の街が存在し，いくつかの街は双方向の道路で繋がっている．どの街からも別のすべての街へ 1 本以上の道路を経由して必ず辿り着くことができる．

// ある日太郎さんと花子さんはとうとう仲違いを起こしてしまい，3 人で街を分担して統治することに決めた．しかし，あまりにも仲が悪くなりすぎてしまったため，太郎さんが統治している街と花子さんが統治している街が 1 本の道路で直接繋がっていることすら嫌がっている．そこで，以下の条件を満たすように統治する街を分担することにした．

// 太郎さんが統治する街と花子さんが統治する街からなる任意のペアは，直接道路で繋がっていない．これは太郎さんと花子さんの仲がめちゃくちゃ悪いからである．
// 同じ人に統治されている街同士も直接道路で繋がっていない．これは，そんな中でも他者の統治下の経由を義務付けることで外交を促すためである．
// 太郎さんの統治する街の総数と花子さんが統治する街の総数は同じでなければならない．これは総数を等しくしないと太郎さんと花子さんの仲がさらにめちゃくちゃ悪くなりそうだからである．ここで，次郎さんはとても心が広いので，次郎さんが統治する街の総数はいくつでもよい．
// 以上の条件を満たすような分担であれば，3 人は納得して統治することができ，たとえ誰かの統治する街が 0 個であっても文句はない．このとき，太郎さんが統治する街の総数 (=花子さんが統治する街の総数) としてあり得る数をすべて列挙するプログラムを作成せよ．

// Input
// 入力は複数のデータセットからなる． データセットの数は最大で 50 である． 各データセットは，次の形式で表される．

// N M
// u1 v1
// ...
// uM vM
// 1 行目は 2 つの整数 N (2 ≤ N ≤ 103) と M (1 ≤ M ≤ 103) からなり，それぞれ街の数と道路の数を表す．続く M 行のうち i 行目は 2 つの整数 ui と vi (1 ≤ ui < vi ≤ N) からなり，i 番目の道路が街 ui と 街 vi を双方向に繋いでいることを表す．ここで，どの街からも別のすべての街へ 1 本以上の道路を経由して必ず辿り着くことができることが保証される．また，同じ街のペアを結ぶ道路が複数与えられることはない．すなわち，すべての 1 ≤ i < j ≤ M について (ui, vi) ≠ (uj, vj) を満たす．

// 入力の終わりは 2 つのゼロからなる行で表される．

// Output
// 各データセットについて，太郎さんが統治する街の総数として考えられる数が K 通りあるとき，まず 1 行目に K を出力し，その後，あり得る総数を 1 行に 1 つずつ昇順で出力せよ．

