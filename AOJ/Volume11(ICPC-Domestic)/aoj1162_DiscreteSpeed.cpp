// Problem D: 離散的速度
// 摩擦のない国での自動車旅行を考える． この国の自動車にはエンジンがない． ある速さで動き出したら，その速さをずっと維持する（摩擦がないから）． 道路上の固定設備として加減速装置が設置してあって， ここを通る時に速さを1だけ増やしたり，減らしたりすることができる． 速さを変えないことも可能である． このような世界で，出発地から目的地まで最短の時間で移動するルートを決定するプログラムを書くことがあなたの仕事である．

// この国には複数の都市があり，それらの間を結ぶ道路網が整備されている． 加減速装置はそれぞれの都市に設置してある． 上に述べたとおり，ある都市に速さv で到着した場合，その都市から次の都市に移動する時の速さはv - 1，v ，v + 1 のいずれかである． 出発地を出た直後の道路を走る速さは1に限られる． 同様に目的地に到着する直前の道路を走る速さも1でなければならない．

// 出発地と目的地（それぞれ都市である）が与えられる． いくつかの都市を経由しながら目的地に到達する最善のルートを求めることが問題である． ある都市に到着した直後に，今来たばかりの道路を引き返すことはできない（Uターン禁止）． この制限を除けば，経路の選び方は自由である． 同じ都市や同じ道路を何度も通ってよいし，出発地や目的地を途中で通過してもかまわない．

// 都市と都市を結ぶ道路のそれぞれに対して，その距離と制限速度が与えられる． その道路を走る時の速さは制限速度以下でなければならない． 道路を通り抜ける所要時間は，距離÷速さである． 都市の通過や加減速に要する時間は無視する．

// Input
// 入力は複数のデータセットから構成される． 各データセットの形式は次に示すとおりである．

// n m
// s g
// x 1 y 1 d 1 c 1
// ...
// xm ym dm cm
// データセットの中の入力項目は，すべて非負の整数である． 行中の入力項目の区切りは空白1個である．

// 最初の行は，道路網の大きさを規定する． n は，都市の数である． 2以上30以下と仮定してよい． m は，都市間道路の本数である． 道路の本数が0のこともある．

// 2行目は，実現したい旅行の記述である． s は，出発地の都市番号である． g は，目的地の都市番号である． s はg と等しくない． この二つを含めて，データセット中に現れる都市番号は1以上n 以下と仮定してよい．

// これに続くm 行が都市間道路の記述である． xi とyi が両端の都市番号， di がその道路に沿った距離である（1 ≤ i ≤ m ）． 距離は1以上100以下と仮定してよい． ci は道路の制限速度である． 制限速度は1以上30以下と仮定してよい．

// ある二つの都市を直接結ぶ道路が2本以上存在することはない． 1本の道路の両端が同じ都市であることはない． それぞれの道路は，どちら向きの移動にも使うことができる．

// 最後のデータセットの直後に，空白で区切られた二つのゼロからなる行がある．

// Output
// 入力の各データセットに対して，以下に規定する結果を一つの行として出力しなさい． 出力行の中に，結果を表す文字以外のもの（たとえば空白）が含まれていてはならない．

// 目的地に到達できる場合は，最も所要時間の短いルートを選んだ時の所要時間を出力すること． 答には，0.001を越える誤差があってはいけない． この条件を守る限り，小数点以下に何個の数字を出力してもよい．

// 目的地に到達できない場合は，unreachableと出力すること． unreachableの文字はすべて小文字であることに注意．
