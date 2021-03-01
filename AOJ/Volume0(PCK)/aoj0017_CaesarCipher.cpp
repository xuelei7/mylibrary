// Caesar Cipher
// In cryptography, Caesar cipher is one of the simplest and most widely known encryption method. Caesar cipher is a type of substitution cipher in which each letter in the text is replaced by a letter some fixed number of positions down the alphabet. For example, with a shift of 1, 'a' would be replaced by 'b', 'b' would become 'c', 'y' would become 'z', 'z' would become 'a', and so on. In that case, a text:

// this is a pen
// is would become:

// uijt jt b qfo
// Write a program which reads a text encrypted by Caesar Chipher and prints the corresponding decoded text. The number of shift is secret and it depends on datasets, but you can assume that the decoded text includes any of the following words: "the", "this", or "that".

// Input
// Input consists of several datasets. Each dataset consists of texts in a line. Input ends with EOF. The text consists of lower-case letters, periods, space, and end-of-lines. Only the letters have been encrypted. A line consists of at most 80 characters.

// You may assume that you can create one decoded text which includes any of "the", "this", or "that" from the given input text.

// The number of datasets is less than or equal to 20.

// Output
// Print decoded texts in a line.

// Sample Input
// xlmw mw xli tmgxyvi xlex m xsso mr xli xvmt.
// Output for the Sample Input
// this is the picture that i took in the trip.

// to string

#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string s, char c) {
    vector<string> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            v.push_back(s.substr(left_side, i-left_side));
            left_side = i+1;
        }
        if (i == s.size() - 1) {
            v.push_back(s.substr(left_side, i-left_side+1));
        }
    }
    return v;
}
int main() {
    string s;
    while (getline(cin,s)) {
        string str[26];
        bool ok = false;
        for (int i = 0; i < 26; i++) {
            str[i] = s;
            for (int j = 0; j < s.size(); j++) {
                if (str[i][j] == ' ' || str[i][j] == '.') continue;
                str[i][j] = (s[j] - 'a' + i) % 26 + 'a';
            }
            vector<string> v = split_string(str[i].substr(0,str[i].size()-1),' ');
            for (int j = 0; j < v.size(); j++) {
                if (v[j] == "this" || v[j] == "that" || v[j] == "the") {
                    cout << str[i] << endl;
                    ok = 1;
                    break;
                }
            }
            if (ok) break;
        }

    }
    return 0;
}