// Problem Statement
// In the headquarter building of ICPC (International Company of Plugs & Connectors), there are M light bulbs and they are controlled by N switches. Each light bulb can be turned on or off by exactly one switch. Each switch may control multiple light bulbs. When you operate a switch, all the light bulbs controlled by the switch change their states. You lost the table that recorded the correspondence between the switches and the light bulbs, and want to restore it.

// You decided to restore the correspondence by the following procedure.

// At first, every switch is off and every light bulb is off.
// You operate some switches represented by S1.
// You check the states of the light bulbs represented by B1.
// You operate some switches represented by S2.
// You check the states of the light bulbs represented by B2.
// ...
// You operate some switches represented by SQ.
// You check the states of the light bulbs represented by BQ.
// After you operate some switches and check the states of the light bulbs, the states of the switches and the light bulbs are kept for next operations.

// Can you restore the correspondence between the switches and the light bulbs using the information about the switches you have operated and the states of the light bulbs you have checked?

// Input
// The input consists of multiple datasets. The number of dataset is no more than 50 and the file size is no more than 10MB. Each dataset is formatted as follows.

// N M Q
// S1 B1
// :
// :
// SQ BQ
// The first line of each dataset contains three integers N (1≤N≤36), M (1≤M≤1,000), Q (0≤Q≤1,000), which denote the number of switches, the number of light bulbs and the number of operations respectively. The following Q lines describe the information about the switches you have operated and the states of the light bulbs you have checked. The i-th of them contains two strings Si and Bi of lengths N and M respectively. Each Si denotes the set of the switches you have operated: Sij is either 0 or 1, which denotes the j-th switch is not operated or operated respectively. Each Bi denotes the states of the light bulbs: Bij is either 0 or 1, which denotes the j-th light bulb is off or on respectively.

// You can assume that there exists a correspondence between the switches and the light bulbs which is consistent with the given information.

// The end of input is indicated by a line containing three zeros.

// Output
// For each dataset, output the correspondence between the switches and the light bulbs consisting of M numbers written in base-36. In the base-36 system for this problem, the values 0-9 and 10-35 are represented by the characters '0'-'9' and 'A'-'Z' respectively. The i-th character of the correspondence means the number of the switch controlling the i-th light bulb. If you cannot determine which switch controls the i-th light bulb, output '?' as the i-th character instead of the number of a switch.

#include <bits/stdc++.h>
using namespace std;
int n,m,q;

string s[1010], b[1010];

void solve() {
    if (n == 1) {
        for (int i = 0; i < m; i++) cout << 0;
        cout << endl;
        return;
    }
    if (q == 0) {
        for (int i = 0; i < m; i++) cout << '?';
        cout << endl;
        return;
    }
    for (int i = 0; i < q; i++) cin >> s[i] >> b[i];
    for (int i = 1; i < q; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                s[i][j] = (s[i-1][j]=='1'?'0':'1');
            } else {
                s[i][j] = (s[i-1][j]=='1'?'1':'0');
            }
        }
    }
    bool possible[1010][40] = {{}};
    int sz[1010] = {};
    for (int i = 0; i < m; i++) {
        // flag if switch is not for this bulb
        bool check[40] = {};
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < q; k++) {
                if (s[k][j] != b[k][i]) check[j] = 1;
            }
        }
        for (int k = 0; k < n; k++) {
            if (!check[k]) {
                possible[i][k] = 1;
                sz[i]++;
            }
        }
    }
    int ans[1010] = {};
    for (int bulb = 0; bulb < m; bulb++) {
        int swt = 0;
        for (int i = 0; i < n; i++) {
            if (possible[bulb][i]) swt = i;
        }
        if (sz[bulb] == 1)
        ans[bulb] = swt+1;
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == 0) cout << '?';
        else if (ans[i] <= 10) cout << ans[i]-1;
        else cout << (char)(ans[i]-11+'A');
    }
    cout << endl;
}



int main() {
    while (cin >> n >> m >> q) {
        if (n == 0 && m == 0 && q == 0) break;
        solve();
    }
}