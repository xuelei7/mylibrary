// 博士が愛した符号
// 博士 : ピーター君、ついにやったよ。
// ピーター : どうしました、デビッド博士？またくだらない発明ですか？
// 博士 : この表だよ、この表。
// 文字	符号
// （空白）	101
// '	000000
// ,	000011
// -	10010001
// .	010001
// ?	000001
// A	100101
// B	10011010
// 文字	符号
// C	0101
// D	0001
// E	110
// F	01001
// G	10011011
// H	010000
// I	0111
// J	10011000
// 文字	符号
// K	0110
// L	00100
// M	10011001
// N	10011110
// O	00101
// P	111
// Q	10011111
// R	1000
// 文字	符号
// S	00110
// T	00111
// U	10011100
// V	10011101
// W	000010
// X	10010010
// Y	10010011
// Z	10010000

// ピーター : なんですか? この表は。
// 博士 : いいから、言う通りにしてみなさい。まず、お前の名前を紙に書いてごらん。
// ピーター : はい"PETER POTTER" っと。
// 博士 : そうしたら、１文字ずつ、この表の「符号」に置き換えるのだよ。
// ピーター : えーと"P" を「111」にして"E" を「110」して…結構面倒ですね。

// 111 110 00111 110 1000 101 111 00101 00111 00111 110 1000
// になりました。なんだか、バーコードみたいですね。
// 博士 : よろしい。そうしたら、置き換えた文字列を全部つなげて、５文字ごとに区切ってみなさい。
// ピーター : はいはい、つなげて区切ると。

// 11111 00011 11101 00010 11110 01010 01110 01111 10100 0
// こんな感じになりました。けど、最後の「0」だけのやつはどうしますか?
// 博士 : ０を付け加えて５文字にしておいてくれ。
// ピーター : えーと最後が０が1個だけだから０をあと４つ加えてやればいいんですね。できました。
// 11111 00011 11101 00010 11110 01010 01110 01111 10100 00000
// 博士 : 次はこの表を使うのだ。
// 符号	文字
// 00000	A
// 00001	B
// 00010	C
// 00011	D
// 00100	E
// 00101	F
// 00110	G
// 00111	H
// 符号	文字
// 01000	I
// 01001	J
// 01010	K
// 01011	L
// 01100	M
// 01101	N
// 01110	O
// 01111	P
// 符号	文字
// 10000	Q
// 10001	R
// 10010	S
// 10011	T
// 10100	U
// 10101	V
// 10110	W
// 10111	X
// 符号	文字
// 11000	Y
// 11001	Z
// 11010	（空白）
// 11011	.
// 11100	,
// 11101	-
// 11110	'
// 11111	?

// ピーター : これをどう使うんですか…そうか!今度は符号から文字に置き換えるのか!
// 博士 : そうそう。「11111」だったら「?」に、「00011」だったら「D」にとやってゆけばいいんだよ。
// ピーター : これは単純ですね……えーと「?D-C'KOPUA」になりました。でも意味不明ですよ。
// 博士 : 文字数を数えてごらん。
// ピーター : １０文字ですよ。あっ、「PETER POTTER」は１２文字だったのに２文字減っています。
// 博士 : そう、この表を使えば文字を減らすことができるのだよ。じゃあ今度はこの文章で同じことをやっ てごらん。
// PETER PIPER PICKED A PECK OF PICKLED PEPPERS. A PECK OF PICKLED PEPPERS
// PETER PIPER PICKED. IF PETER PIPER PICKED A PECK OF PICKLED PEPPERS, WHERE'S
// THE PECK OF PICKLED PEPPERS PETER PIPER PICKED?
// ピーター : ぎょぎょ、行が分かれていますが、どうするんですか?
// 博士 : 紙の都合で３行になってしまったが、改行文字のかわりに空白がある長い１行だと思っておくれ。
// ピーター : はいはい。行と行の間にあるのは空白だと。しかし面倒だな……。
// 博士 : だったらプログラムにやらせればいいではないか。
// ということで、ピーターの代わりに、読み込んだ文字列を符号に変換し出力するプログラムを作成してください。

// 入力
// 複数のデータセットが与えられます。各データセットに文字列１行（表に含まれる文字からなる）が与えられます。文字列に含まれる文字の数は 1 文字以上 100 文字以下です。

// データセットの数は 200 を超えません。

// 出力
// 各データセットごとに、変換後の文字列を１行に出力してください。

#include <bits/stdc++.h>
using namespace std;
pair<char,string> list1[] = {
{' ',	"101"},
{'\'',	"000000"},
{',',	"000011"},
{'-',	"10010001"},
{'.',	"010001"},
{'?',	"000001"},
{'A',	"100101"},
{'B',	"10011010"},
{'C',	"0101"},
{'D',	"0001"},
{'E',	"110"},
{'F',	"01001"},
{'G',	"10011011"},
{'H',	"010000"},
{'I',	"0111"},
{'J',	"10011000"},
{'K',	"0110"},
{'L',	"00100"},
{'M',	"10011001"},
{'N',	"10011110"},
{'O',	"00101"},
{'P',	"111"},
{'Q',	"10011111"},
{'R',	"1000"},
{'S',	"00110"},
{'T',	"00111"},
{'U',	"10011100"},
{'V',	"10011101"},
{'W',	"000010"},
{'X',	"10010010"},
{'Y',	"10010011"},
{'Z',	"10010000"}
};

pair<string,char> list2[] = {
{"00000",	'A'},
{"00001",	'B'},
{"00010",	'C'},
{"00011",	'D'},
{"00100",	'E'},
{"00101",	'F'},
{"00110",	'G'},
{"00111",	'H'},
{"01000",	'I'},
{"01001",	'J'},
{"01010",	'K'},
{"01011",	'L'},
{"01100",	'M'},
{"01101",	'N'},
{"01110",	'O'},
{"01111",	'P'},
{"10000",	'Q'},
{"10001",	'R'},
{"10010",	'S'},
{"10011",	'T'},
{"10100",	'U'},
{"10101",	'V'},
{"10110",	'W'},
{"10111",	'X'},
{"11000",	'Y'},
{"11001",	'Z'},
{"11010",	' '},
{"11011",	'.'},
{"11100",	','},
{"11101",	'-'},
{"11110",	'\''},
{"11111",	'?'}
};
int main() {
    string s;
    while (getline(cin,s)) {
        string code = "";
        for (auto c: s) {
            for (auto p:list1) {
                if (c == p.first) code += p.second;
            }
        }
        while (code.size() % 5 != 0) {
            code += "0";
        }
        string ret = "";
        for (int i = 0; i < code.size(); i += 5) {
            string str = code.substr(i,5);
            for (auto p:list2) {
                if (str == p.first) ret += p.second;
            }
        }
        cout << ret << endl;
    }
    return 0;
}