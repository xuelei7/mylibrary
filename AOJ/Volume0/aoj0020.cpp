// Capitalize
// Write a program which replace all the lower-case letters of a given text with the corresponding captital letters.

// Input
// A text including lower-case letters, periods, and space is given in a line. The number of characters in the text is less than or equal to 200.

// Output
// Print the converted text.

// Sample Input
// this is a pen.
// Output for the Sample Input
// THIS IS A PEN.

// to string

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '.' && s[i] != ' ') s[i] = toupper(s[i]);
    }
    cout << s << endl;
    return 0;
}