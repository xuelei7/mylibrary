// M and A
// The CEO of the company named S is planning M&A with another company named T. M&A is an abbreviation for "Mergers and Acquisitions". The CEO wants to keep the original company name S through the M&A on the plea that both company names are mixed into a new one.

// The CEO insists that the mixed company name after the M&A is produced as follows.

// Let s be an arbitrary subsequence of S, and t be an arbitrary subsequence of T. The new company name must be a string of the same length to S obtained by alternatively lining up the characters in s and t. More formally, s0+t0+s1+t1+... or t0+s0+t1+s1+... can be used as the company name after M&A. Here, sk denotes the k-th (0-based) character of string s. Please note that the lengths of s and t will be different if the length of S is odd. In this case, the company name after M&A is obtained by s0+t0+...+t|S|/2+s|S|/2+1 or t0+s0+...+s|S|/2+t|S|/2+1 (|S| denotes the length of S and "/" denotes integer division).

// A subsequence of a string is a string which is obtained by erasing zero or more characters from the original string. For example, the strings "abe", "abcde" and "" (the empty string) are all subsequences of the string "abcde".

// You are a programmer employed by the acquiring company. You are assigned a task to write a program that determines whether it is possible to make S, which is the original company name, by mixing the two company names.

// Input
// The input consists of a single test case. The test case consists of two lines.

// The first line contains a string S which denotes the name of the company that you belong to. The second line contains a string T which denotes the name of the target company of the planned M&A. The two names S and T are non-empty and of the same length no longer than 1,000 characters, and all the characters used in the names are lowercase English letters.

// Output
// Print "Yes" in a line if it is possible to make original company name by combining S and T. Otherwise, print "No" in a line.

