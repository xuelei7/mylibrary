// Parentheses
// Dave loves strings consisting only of '(' and ')'. Especially, he is interested in balanced strings. Any balanced strings can be constructed using the following rules:

// A string "()" is balanced.
// Concatenation of two balanced strings are balanced.
// If $T$ is a balanced string, concatenation of '(', $T$, and ')' in this order is balanced. For example, "()()" and "(()())" are balanced strings. ")(" and ")()(()" are not balanced strings.
// Dave has a string consisting only of '(' and ')'. It satises the followings:

// You can make it balanced by swapping adjacent characters exactly $A$ times.
// For any non-negative integer $B$ ($B < A$), you cannot make it balanced by $B$ swaps of adjacent characters.
// It is the shortest of all strings satisfying the above conditions.
// Your task is to compute Dave's string. If there are multiple candidates, output the minimum in lexicographic order. As is the case with ASCII, '(' is less than ')'.

// Input
// The input consists of a single test case, which contains an integer $A$ ($1 \leq A \leq 10^9$).

// Output
// Output Dave's string in one line. If there are multiple candidates, output the minimum in lexicographic order.

