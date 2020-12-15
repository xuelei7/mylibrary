// English Sentence
// Your task is to write a program which reads a text and prints two words. The first one is the word which is arise most frequently in the text. The second one is the word which has the maximum number of letters.

// The text includes only alphabetical characters and spaces. A word is a sequence of letters which is separated by the spaces.

// Input
// A text is given in a line. You can assume the following conditions:

// The number of letters in the text is less than or equal to 1000.
// The number of letters in a word is less than or equal to 32.
// There is only one word which is arise most frequently in given text.
// There is only one word which has the maximum number of letters in given text.
// Output
// The two words separated by a space.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    map<string,int> mp;
    int mxcnt = 0;
    int mx = 0;
    string mode = "";
    string longest = "";
    while (cin >> s) {
        mp[s]++;
        if (mp[s] > mx) {
            mx = mp[s];
            mode = s;
        }
        if (s.size() > mxcnt) {
            mxcnt = s.size();
            longest = s;
        }
    }
    cout << mode << " " << longest << "\n";
    return 0;
}