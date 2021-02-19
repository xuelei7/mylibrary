// Problem B: Stylish
// Stylish is a programming language whose syntax comprises names, that are sequences of Latin alphabet letters, three types of grouping symbols, periods ('.'), and newlines. Grouping symbols, namely round brackets ('(' and ')'), curly brackets ('{' and '}'), and square brackets ('[' and ']'), must match and be nested properly. Unlike most other programming languages, Stylish uses periods instead of whitespaces for the purpose of term separation. The following is an example of a Stylish program.

// 1 ( Welcome .to
// 2 ......... Stylish )
// 3 { Stylish .is
// 4 .....[.( a. programming . language .fun .to. learn )
// 5 .......]
// 6 ..... Maybe .[
// 7 ....... It. will .be.an. official . ICPC . language
// 8 .......]
// 9 .....}
// As you see in the example, a Stylish program is indented by periods. The amount of indentation of a line is the number of leading periods of it.

// Your mission is to visit Stylish masters, learn their indentation styles, and become the youngest Stylish master. An indentation style for well-indented Stylish programs is defined by a triple of integers, (R, C, S), satisfying 1 ≤ R, C, S ≤ 20. R, C and S are amounts of indentation introduced by an open round bracket, an open curly bracket, and an open square bracket, respectively.

// In a well-indented program, the amount of indentation of a line is given by R(ro − rc) + C(co − cc) + S(so − sc), where ro, co, and so are the numbers of occurrences of open round, curly, and square brackets in all preceding lines, respectively, and rc, cc, and sc are those of close brackets. The first line has no indentation in any well-indented program.

// The above example is formatted in the indentation style (R, C, S) = (9, 5, 2). The only grouping symbol occurring in the first line of the above program is an open round bracket. Therefore the amount of indentation for the second line is 9 · (1 − 0) + 5 · (0 − 0) + 2 ·(0 − 0) = 9. The first four lines contain two open round brackets, one open curly bracket, one open square bracket, two close round brackets, but no close curly nor square bracket. Therefore the amount of indentation for the fifth line is 9 · (2 − 2) + 5 · (1 − 0) + 2 · (1 − 0) = 7.

// Stylish masters write only well-indented Stylish programs. Every master has his/her own indentation style.

// Write a program that imitates indentation styles of Stylish masters.

// Input
// The input consists of multiple datasets. The first line of a dataset contains two integers p (1 ≤ p ≤ 10) and q (1 ≤ q ≤ 10). The next p lines form a well-indented program P written by a Stylish master and the following q lines form another program Q. You may assume that every line of both programs has at least one character and at most 80 characters. Also, you may assume that no line of Q starts with a period.

// The last dataset is followed by a line containing two zeros.

// Output
// Apply the indentation style of P to Q and output the appropriate amount of indentation for each line of Q. The amounts must be output in a line in the order of corresponding lines of Q and they must be separated by a single space. The last one should not be followed by trailing spaces. If the appropriate amount of indentation of a line of Q cannot be determined uniquely through analysis of P, then output -1 for that line.

