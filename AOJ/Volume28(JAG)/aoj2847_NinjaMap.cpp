// Ninja Map
// Intersections of Crossing Path City are aligned to a grid. There are N east-west streets which are numbered from 1 to N, from north to south. There are also N north-south streets which are numbered from 1 to N, from west to east. Every pair of east-west and north-south streets has an intersection; therefore there are N2 intersections which are numbered from 1 to N2.

// Surprisingly, all of the residents in the city are Ninja. To prevent outsiders from knowing their locations, the numbering of intersections is shuffled.

// You know the connections between the intersections and try to deduce their positions from the information. If there are more than one possible set of positions, you can output any of them.

// Input
// The input consists of a single test case formatted as follows.

// N
// a1 b1
// ...
// a2N2−2N  b2N2−2N
// The first line consists of an integer N (2≤N≤100). The following 2N2−2N lines represent connections between intersections. The (i+1)-th line consists of two integers ai and bi (1≤ai,bi≤N2,ai≠bi), which represent that the ai-th and bi-th intersections are adjacent. More precisely, let's denote by (r,c) the intersection of the r-th east-west street and the c-th north-south street. If the intersection number of (r,c) is ai for some r and c, then the intersection number of either (r−1,c), (r+1,c), (r,c−1) or (r,c+1) must be bi. All inputs of adjacencies are different, i.e., (ai,bi) ≠ (aj,bj) and (ai,bi) ≠ (bj,aj) for all 1≤i<j≤2N2−2N. This means that you are given information of all adjacencies on the grid.

// The input is guaranteed to describe a valid map.

// Output
// Print a possible set of positions of the intersections. More precisely, the output consists of N lines each of which has space-separated N integers. The c-th integer of the r-th line should be the intersection number of (r,c).

// If there are more than one possible set of positions, you can output any of them.

#include <bits/stdc++.h>
using namespace std;

vector<int> v[10010];
int cnt[10010];
int ans[110][110];
bool used[10010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 2*n*n-2*n; i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    
    int bg;
    for (int i = 1; i < n * n; i++) {
        if (cnt[i] == 2) bg = i;
    }

    ans[0][0] = bg;
    ans[1][0] = v[bg][0];
    ans[0][1] = v[bg][1];
    used[bg] = 1;
    used[v[bg][0]] = 1;
    used[v[bg][1]] = 1;
    // first coloum
    for (int i = 2; i < n; i++) {
        bool ok = 0;
        for (int j = 1; j <= n * n; j++) {
            if (used[j]) continue;
            if (cnt[j] <= 3) {
                for (int k = 0; k < cnt[j]; k++) {
                    if (v[j][k] == ans[i-1][0]) {
                        ans[i][0] = j;
                        used[j] = 1;
                        ok = 1;
                        break;
                    }
                }
            }
            if (ok) break;
        }
    }
    // first row
    for (int i = 2; i < n; i++) {
        bool ok = 0;
        for (int j = 1; j <= n * n; j++) {
            if (used[j]) continue;
            if (cnt[j] <= 3) {
                for (int k = 0; k < cnt[j]; k++) {
                    if (v[j][k] == ans[0][i-1]) {
                        ans[0][i] = j;
                        used[j] = 1;
                        ok = 1;
                        break;
                    }
                }
            }
            if (ok) break;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 1; k <= n * n; k++) {
                if (used[k]) continue;
                bool ok[2] = {};
                for (int l = 0; l < cnt[k]; l++) {
                    if (v[k][l] == ans[i-1][j]) ok[0] = 1;
                    if (v[k][l] == ans[i][j-1]) ok[1] = 1;
                }
                if (ok[0] && ok[1]) {
                    ans[i][j] = k;
                    used[k] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j==n-1];
        }
    }
    return 0;
}