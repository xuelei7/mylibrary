// D - LR
// Problem Statement
// JAG Kingdom will hold a contest called ICPC (Interesting Contest for Producing Calculation).

// At the contest, you are given a string composed of ?s and usable characters. You should replace all ?s in the string with the usable characters to make the string valid mathematical expression, before submitting it. The usable characters are L, R, (, ), ,, 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.

// For example, suppose that you are given the string "R(??3,??1?78??1?)?", then you can submit "R(123,L(1678,213))" as an example.

// The submitted string will be scored as follows.

// Let $L$ and $R$ be functions defined by $L(x,y)=x$, $R(x,y)=y$, where $x$ and $y$ are non-negative integers.
// The submitted string will be regarded as a mathematical expression, whose value will be the score. For example, the score of the string "R(123,L(1678,213))" is $R(123,L(1678,213)) = R(123,1678) = 1678$.
// If the string cannot be evaluated as a mathematical expression about the functions $L$ and $R$, the string will be rejected. For example, "R", "R(3)", "R(3,2", "R(3,2,4)" and "LR(3,2)" are all invalid.
// And strings that contain numbers with extra leading zeros, will be rejected. For example, "R(04,18)" is invalid, while "R(0,18)" is valid.
// The winner of the contest will be the person getting the highest score. Your friend Jagger, who is going to join the contest, wants to be the winner. You are asked by Jagger to make the program finding the possible highest score for the input string.

// Input
// The input contains one string in a line, whose length $N$ is between $1$ and $50$, inclusive.

// You can assume that each element in the string is one of L, R, (, ), ,, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, or ?.

// Output
// Display the possible highest score in a line for the given string.

// If it's impossible to get valid strings for the input string, print "invalid" in a line.

