// Problem B: For the Peace
// This is a story of a world somewhere far from the earth. In this world, the land is parted into a number of countries ruled by empires. This world is not very peaceful: they have been involved in army race.

// They are competing in production of missiles in particular. Nevertheless, no countries have started wars for years. Actually they have a reason they can’t get into wars - they have missiles much more than enough to destroy the entire world. Once a war would begin among countries, none of them could remain.

// These missiles have given nothing but scare to people. The competition has caused big financial and psychological pressure to countries. People have been tired. Military have been tired. Even empires have been tired. No one wishes to keep on missile production.

// So empires and diplomats of all countries held meetings quite a few times toward renouncement of missiles and abandon of further production. The meetings were quite difficult as they have different matters. However, they overcame such difficulties and finally came to the agreement of a treaty. The points include:

// Each country will dispose all the missiles of their possession by a certain date.
// The war potential should not be different by greater than a certain amount d among all countries.
// Let us describe more details on the second point. Each missile has its capability, which represents how much it can destroy the target. The war potential of each country is measured simply by the sum of capability over missiles possessed by that country. The treaty requires the difference to be not greater than d between the maximum and minimum potential of all the countries.

// Unfortunately, it is not clear whether this treaty is feasible. Every country is going to dispose their missiles only in the order of time they were produced, from the oldest to the newest. Some missiles have huge capability, and disposal of them may cause unbalance in potential.

// Your task is to write a program to see this feasibility.

// Input
// The input is a sequence of datasets. Each dataset is given in the following format:

// n d
// m1 c1,1 ... c1,m1
// ...
// mn cn,1 ... cn,mn
// The first line contains two positive integers n and d, the number of countries and the tolerated difference of potential (n ≤ 100, d ≤ 1000). Then n lines follow. The i-th line begins with a non-negative integer mi, the number of the missiles possessed by the i-th country. It is followed by a sequence of mi positive integers. The j-th integer ci,j represents the capability of the j-th newest missile of the i-th country (ci,j ≤ 1000). These integers are separated by a single space. Note that the country disposes their missiles in the reverse order of the given sequence.

// The number of missiles is not greater than 10000. Also, you may assume the difference between the maximum and minimum potential does not exceed d in any dataset.

// The input is terminated by a line with two zeros. This line should not be processed.

// Output
// For each dataset, print a single line. If they can dispose all their missiles according to the treaty, print "Yes" (without quotes). Otherwise, print "No".

// Note that the judge is performed in a case-sensitive manner. No extra space or character is allowed.

#include <bits/stdc++.h>
using namespace std;
int n,d;
int m[110];
int c[110][10010];
int p[110];
int now[110];

int main() {
    while (cin >> n >> d) {
        if (n == 0 || d == 0) break;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> m[i];
            sum += m[i];
            for (int j = 1; j <= m[i]; j++) {
                cin >> c[i][j];
                c[i][j] += c[i][j-1];
            }
            p[i] = 0;
            now[i] = 0;
        }
        int mi = 0, mx = 0;
        bool ok = 1;
        while (1) {
            bool update = 0;
            for (int i = 0; i < n; i++) {
                if (p[i] < m[i]) {
                    now[i] = c[i][p[i]+1];
                    if (*max_element(now,now+n) - *min_element(now,now+n) <= d) {
                        update = 1;
                        p[i]++;
                    } else {
                        now[i] = c[i][p[i]];
                    }
                }
            }
            if (!update) break;
        }
        for (int i = 0; i < n; i++) if (p[i] != m[i]) ok = 0;
        cout << (ok? "Yes":"No") << endl;
    }
}