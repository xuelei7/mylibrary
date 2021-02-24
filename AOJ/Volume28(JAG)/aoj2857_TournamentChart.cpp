// Tournament Chart
// In 21XX, an annual programming contest, Japan Algorithmist GrandPrix (JAG) has become one of the most popular mind sports events.

// JAG is conducted as a knockout tournament. This year, [Math Processing Error] contestants will compete in JAG. A tournament chart is represented as a string. '[[a-b]-[c-d]]' is an easy example. In this case, there are 4 contestants named a, b, c, and d, and all matches are described as follows:

// Match 1 is the match between a and b.
// Match 2 is the match between c and d.
// Match 3 is the match between [the winner of match 1] and [the winner of match 2].
// More precisely, the tournament chart satisfies the following BNF:

// <winner> ::= <person> | "[" <winner> "-" <winner> "]"
// <person> ::= "a" | "b" | "c" | ... | "z"
// You, the chairperson of JAG, are planning to announce the results of this year's JAG competition. However, you made a mistake and lost the results of all the matches. Fortunately, you found the tournament chart that was printed before all of the matches of the tournament. Of course, it does not contains results at all. Therefore, you asked every contestant for the number of wins in the tournament, and got [Math Processing Error] pieces of information in the form of "The contestant [Math Processing Error] won [Math Processing Error] times".

// Now, your job is to determine whether all of these replies can be true.

// Input
// The input consists of a single test case in the format below.

// [Math Processing Error]
// [Math Processing Error] [Math Processing Error]
// :
// [Math Processing Error] [Math Processing Error]
// [Math Processing Error] represents the tournament chart. [Math Processing Error] satisfies the above BNF. The following [Math Processing Error] lines represent the information of the number of wins. The ([Math Processing Error])-th line consists of a lowercase letter [Math Processing Error] and a non-negative integer [Math Processing Error] ([Math Processing Error]) separated by a space, and this means that the contestant [Math Processing Error] won [Math Processing Error] times. Note that [Math Processing Error] ([Math Processing Error]) means that the number of contestants and it can be identified by string [Math Processing Error]. You can assume that each letter [Math Processing Error] is distinct. It is guaranteed that [Math Processing Error] contains each [Math Processing Error] exactly once and doesn't contain any other lowercase letters.

// Output
// Print 'Yes' in one line if replies are all valid for the tournament chart. Otherwise, print 'No' in one line.

