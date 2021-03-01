// Problem A: Membership Management
// Peter is a senior manager of Agile Change Management (ACM) Inc., where each employee is a member of one or more task groups. Since ACM is agile, task groups are often reorganized and their members frequently change, so membership management is his constant headache.

// Peter updates the membership information whenever any changes occur: for instance, the following line written by him means that Carol and Alice are the members of the Design Group.

// design:carol,alice.
// The name preceding the colon is the group name and the names following it specify its members.

// A smaller task group may be included in a larger one. So, a group name can appear as a member of another group, for instance, as follows.

// development:alice,bob,design,eve.
// Simply unfolding the design above gives the following membership specification, which is equivalent to the original.

// development:alice,bob,carol,alice,eve.
// In this case, however, alice occurs twice. After removing one of the duplicates, we have the following more concise specification.

// development:alice,bob,carol,eve.
// Your mission in this problem is to write a program that, given group specifications, identifies group members.

// Note that Peter's specifications can include deeply nested groups. In the following, for instance, the group one contains a single member dave.

// one:another.
// another:yetanother.
// yetanother:dave.
// Input
// The input is a sequence of datasets, each being in the following format.

// n
// group1:member1,1,...,member1,m1.
// .
// .
// .
// groupi:memberi,1,...,memberi,mi.
// .
// .
// .
// groupn:membern,1,...,membern,mn.
// The first line contains n, which represents the number of groups and is a positive integer no more than 100. Each of the following n lines contains the membership information of a group: groupi (1 ≤ i ≤ n) is the name of the i-th task group and is followed by a colon (:) and then the list of its mi member s that are delimited by a comma (,) and terminated by a period (.).

// Those group names are mutually different. Each mi (1 ≤ i ≤ n) is between 1 and 10, inclusive. A member is another group name if it is one of group1, group2,..., or groupn. Otherwise it is an employee name.

// There are no circular (or recursive) definitions of group(s). You may assume that mi member names of a group are mutually different.

// Each group or employee name is a non-empty character string of length between 1 and 15, inclusive, and consists of lowercase letters.

// The end of the input is indicated by a line containing a zero.

// Output
// For each dataset, output the number of employees included in the first group of the dataset, that is group1, in a line. No extra characters should occur in the output.

#include <bits/stdc++.h>
using namespace std;
int n;
string v[120][11];
string name[120];
map<string,int> np;
int sz[120];
set<string> st;
string s[110];
int main() {
    while (cin >> n) {
        if (n == 0) break;
        st.clear();
        np.clear();
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            name[i] = "";
            int p = 0;
            while (s[i][p] != ':') name[i] += s[i][p++];
            np[name[i]] = i;
            // cout << s[i] << endl << name[i] << endl;
        }
        queue<int> q;
        q.push(0);
        bool ok[110] = {};
        while (!q.empty()) {
            int i = q.front();
            q.pop();

            sz[i] = 0;
            v[i][0] = "";
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == ':' || s[i][j] == ',' || s[i][j] == '.') {
                    // cout << v[i][sz[i]] << " ";
                    sz[i]++;
                    v[i][sz[i]] = "";
                } else v[i][sz[i]] += s[i][j];
            }
            // cout << endl;

            for (int ii = 1; ii < sz[i]; ii++) {
                if (!np.count(v[i][ii])) {
                    st.insert(v[i][ii]);
                    // cout << v[i][ii] << endl;
                } else {
                    int id = np[v[i][ii]];
                    if (!ok[id]) {
                        q.push(np[v[i][ii]]);
                        ok[id] = 1;
                    }
                }
            }
        }
        cout << st.size() << endl;
    }
}