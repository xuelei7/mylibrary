// Carpenters' Language
// International Carpenters Professionals Company (ICPC) is a top construction company with a lot of expert carpenters. What makes ICPC a top company is their original language.

// The syntax of the language is simply given in CFG as follows:

// S -> SS | (S) | )S( | ε
// In other words, a right parenthesis can be closed by a left parenthesis and a left parenthesis can be closed by a right parenthesis in this language.

// Alex, a grad student mastering linguistics, decided to study ICPC's language. As a first step of the study, he needs to judge whether a text is well-formed in the language or not. Then, he asked you, a great programmer, to write a program for the judgement.

// Alex's request is as follows: You have an empty string S in the beginning, and construct longer string by inserting a sequence of '(' or ')' into the string. You will receive q queries, each of which consists of three elements (p,c,n), where p is the position to insert, n is the number of characters to insert and c is either '(' or ')', the character to insert. For each query, your program should insert c repeated by n times into the p-th position of S from the beginning. Also it should output, after performing each insert operation, "Yes" if S is in the language and "No" if S is not in the language.

// Please help Alex to support his study, otherwise he will fail to graduate the college.

// Input
// The first line contains one integer q (1≤q≤105) indicating the number of queries, follows q lines of three elements, pi, ci, ni, separated by a single space (1≤i≤q, ci='('or')', 0≤pi≤ length of S before i-th query, 1≤n≤220). It is guaranteed that all the queries in the input are valid.

// Output
// For each query, output "Yes" if S is in the language and "No" if S is not in the language.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
void solve() {
    ll n,p;
    char c;
    cin >> p >> c >> n;
    if (c == ')') k += n;
    else k -= n;
    cout << (k == 0? "Yes":"No") << endl;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}