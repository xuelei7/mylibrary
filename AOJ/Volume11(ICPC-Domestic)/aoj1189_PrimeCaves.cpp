// 素数洞穴
// 砂漠の中の巨大な崖の中腹に，石窟寺院が残されているのを国際調査隊が発見しました．垂直にそびえ立つ崖のちょうど真ん中あたりに，無数の洞穴が縦横にきれいに並んでおり，それぞれの中に仏像が残されていたのです．さらにすごいことに，いくつかの洞穴には仏教の教典が隠されていました．千年以上も前に書かれたと見られる教典の価値は，それこそ計り知れません．

// 調査隊の隊長は，できるだけ多くの教典を持ち帰ることを決めました．ただ，洞穴は崖の中ほどにあるため，簡単には入れません．唯一の方法は，あなたの体をヘリコプターで吊るして1つの洞穴に入って調査をし，その洞穴から縄を使ってすぐ下にある3つの洞穴(直下の洞穴か，直下の洞穴の右または左に隣り合う洞穴)のどれかに降りるということを繰り返して降りてくるというものです．最後の洞穴からは長い縄を使って地面に降りることができます．

// 一度に何個かの洞穴を調査できるとは言うものの，どの洞穴を調査すればよいのでしょうか? そんな折，数学者のメンバーが予備調査の結果から教典が隠された洞穴にはある規則性があることを見つけました．彼によれば(1)洞穴には，中央のものに1番，そこから図D-1のように外向きに渦を巻くように番号を付けると，(2)教典が隠されているのは図中丸で囲まれているような素数番目の洞穴(以降素数洞穴と呼びます)に他ならない，というのです．次回からはあなたが最初の洞穴に入ったら，素数洞穴を最も多く調査するように降りてくることができるでしょう．



// 図D-1: 洞穴の番号と素数洞穴
// 洞穴の総数と最初に入る洞穴の番号が与えられたときに，素数洞穴をできるだけ多く調査できる降下経路を見つけるプログラムを作ってください．

// Input
// 入力は複数のデータセットからなる．1つのデータセットは整数 m (1 ≤ m ≤ 106)と n (1 ≤ n ≤ m)を空白で区切った1行である．m は洞穴の総数を表し，n は最初に入る洞穴の番号を表す．最後のデータセットの次の行には2つのゼロが書かれている．

// Output
// 各データセットについて，洞穴 n から始めて，最も多く素数洞穴を調査する経路について，素数洞穴の個数と経路上最後に通過した素数洞穴の番号を空白で区切って1行に出力せよ．ただし最初に入る洞穴nも経路上の洞穴に含める．最も多くの素数洞穴を調査する経路が複数ある場合は，最後に通過した素数洞穴の番号が最も大きい経路について出力せよ．素数洞穴を調査する経路が1つもない場合には"0 0"を(引用符を除いて)出力せよ．

