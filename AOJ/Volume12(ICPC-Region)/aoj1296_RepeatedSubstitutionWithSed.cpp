// Problem B: Repeated Substitution with Sed
// Do you know "sed," a tool provided with Unix? Its most popular use is to substitute every occurrence of a string contained in the input string (actually each input line) with another string β. More precisely, it proceeds as follows.

// Within the input string, every non-overlapping (but possibly adjacent) occurrences of α are marked. If there is more than one possibility for non-overlapping matching, the leftmost one is chosen.
// Each of the marked occurrences is substituted with β to obtain the output string; other parts of the input string remain intact.
// For example, when α is "aa" and β is "bca", an input string "aaxaaa" will produce "bcaxbcaa", but not "aaxbcaa" nor "bcaxabca". Further application of the same substitution to the string "bcaxbcaa" will result in "bcaxbcbca", but this is another substitution, which is counted as the second one.

// In this problem, a set of substitution pairs (αi, βi) (i = 1, 2, ... , n), an initial string γ, and a final string δ are given, and you must investigate how to produce δ from γ with a minimum number of substitutions. A single substitution (αi, βi) here means simultaneously substituting all the non-overlapping occurrences of αi, in the sense described above, with βi.

// You may use a specific substitution (αi, βi ) multiple times, including zero times.

// Input
// The input consists of multiple datasets, each in the following format.

// n
// α1 β1
// α2 β2
// .
// .
// .
// αn βn
// γ
// δ
// n is a positive integer indicating the number of pairs. αi and βi are separated by a single space. You may assume that 1 ≤ |αi| < |βi| ≤ 10 for any i (|s| means the length of the string s), αi ≠ αj for any i ≠ j, n ≤ 10 and 1 ≤ |γ| < |δ| ≤ 10. All the strings consist solely of lowercase letters. The end of the input is indicated by a line containing a single zero.

// Output
// For each dataset, output the minimum number of substitutions to obtain δ from γ. If δ cannot be produced from γ with the given set of substitutions, output -1.

#include <bits/stdc++.h>
using namespace std;
map<string,int> d;
int n;
string s,g;
string f[11],t[11];
int main() {
    while (cin >> n) {
        if (n == 0) break;
        d.clear();
        for (int i = 0; i < n; i++) cin >> f[i] >> t[i];
        cin >> s >> g;
        d[s] = 0;
        queue<string> pq;
        pq.push(s);
        while (!pq.empty()) {
            string str = pq.front();
            pq.pop();
            
            for (int j = 0; j < n; j++) {
                string ss = "";
                for (int i = 0; i < str.size(); i++) {
                    if (i + f[j].size() - 1 < str.size() && str.substr(i,f[j].size()) == f[j]) {
                        ss = ss + t[j];
                        i += f[j].size() - 1;
                    } else {
                        ss += str[i];
                    }
                }
                if (ss.size() > g.size()) continue;
                if (!d.count(ss)) {
                    d[ss] = d[str] + 1;
                    pq.push(ss);
                }
            }
        }
        if (!d.count(g)) cout << -1 << endl;
        else cout << d[g] << endl;
    }
}