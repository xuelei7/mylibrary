// ラムダ式
// [キャプチャリスト](パラメータリスト) mutable 例外仕様 属性 -> 戻り値の型 { 関数の本体 }

// キャプチャリスト
// キャプチャ記法   説明
// [&]              デフォルトで環境にある変数を参照して、ラムダ式のなかで使用する
// [=]	            デフォルトで環境にある変数をコピーして、ラムダ式のなかで使用する
// [&x]	            変数xを参照して、ラムダ式のなかで使用する
// [x]	            変数xをコピーして、ラムダ式のなかで使用する
// [&, x]	        デフォルトで参照キャプチャ、変数xのみコピーして、ラムダ式のなかで使用する
// [=, &x]	        デフォルトでコピーキャプチャ、変数xのみ参照して、ラムダ式のなかで使用する
// [this]	        *thisのメンバを参照して、ラムダ式のなかで使用する
// [this, x]	    *thisのメンバを参照し、変数xのみコピーして、ラムダ式のなかで使用する

