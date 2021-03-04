// Problem D: ちょろちょろロボット
// ロボットを使ったゲームをしよう． ロボットが 1 台，マス目状に区切られた長方形の盤面上に置かれている（図 D-1）． ロボットは，最初北西隅にあるスタート地点のマスに東方向を向いて配置されている． ゲームの目的は，ロボットを南東隅にあるゴールのマスまで誘導することである．



// 図 D-1: 盤面の例
// ロボットは，次の 5 種類の命令を実行することができる．

// 「直進 (Straight)」:
// 現在の進行方向のまま，次のマスに前進する．
// 「右折 (Right)」:
// 進行方向を 90 度右に変えて，次のマスに前進する．
// 「反転 (Back)」:
// 進行方向を 180 度変えて，次のマスに前進する．
// 「左折 (Left)」:
// 進行方向を 90 度左に変えて，次のマスに前進する．
// 「停止 (Halt)」:
// 現在のマスで止まって，ゲームを終了する．
// 各マスには，上述の命令のいずれかが割り当てられている（例：図 D-2）． 代わりに実行すべき別の命令をプレイヤーが与えない限り， ロボットは，現在いるマスの命令を実行する． プレイヤーが明示的に命令を与える際は，その都度， 命令の種類に応じたコストを支払う必要がある．



// 図 D-2: 各マスに割り当てられた命令の例
// ロボットは，同じ場所を何度も訪れることが許されている． 一方で，ロボットが盤面外に前進するような命令を実行した場合や， ゴールに着く前に停止命令を実行した場合は，失格となる．

// あなたの仕事は， ロボットをスタート地点からゴール地点に誘導するために必要な最小コストを求めるプログラムを書くことである．

// Input
// 入力は，複数のデータセットからなり， 入力の終わりはスペースで区切られたゼロ 2 つからなる行である． 各データセットは，次の形式をしている．

// w h
// s(1,1) ... s(1,w)
// s(2,1) ... s(2,w)
// ...
// s(h,1) ... s(h,w)
// c0 c1 c2 c3
// h と w は，それぞれ盤面の行および列の数を示す整数であり， 2 ≤ h ≤ 30, 2 ≤ w ≤ 30 と仮定してよい． 続く h 行はそれぞれ，スペースで区切られた w 個の文字から構成されており， 文字 s(i, j) は， i 行 j 列目に位置するマスに割り当てられた命令を示す． その意味は，以下の通り．

// 0: 「直進」命令
// 1: 「右折」命令
// 2: 「反転」命令
// 3: 「左折」命令
// 4: 「停止」命令
// ゴールのマス目には，「停止」命令が割り当てられているが， 他のマス目にも「停止」命令が割り当てられていることがあるので，注意せよ．

// データセットの最後の行は，スペースで区切られた c0, c1, c2, c3 の 4 つの整数値を含んでおり， それぞれ，「直進」，「右折」，「反転」，「左折」命令を与える際に， プレイヤーが支払うべきコストを示している． プレイヤーが「停止」命令を与えることはできない． また， c0, c1, c2, c3 の値は， 1 以上 9 以下と仮定してよい．

// Output
// 各データセットについて，ロボットをゴールに誘導するために必要な最小コストを求め， 十進数の整数としてそれぞれ 1 行に出力しなさい． 出力行には他の文字があってはならない．
