// Problem B: The Last Ant
// A straight tunnel without branches is crowded with busy ants coming and going. Some ants walk left to right and others right to left. All ants walk at a constant speed of 1 cm/s. When two ants meet, they try to pass each other. However, some sections of the tunnel are narrow and two ants cannot pass each other. When two ants meet at a narrow section, they turn around and start walking in the opposite directions. When an ant reaches either end of the tunnel, it leaves the tunnel.

// The tunnel has an integer length in centimeters. Every narrow section of the tunnel is integer centimeters distant from the both ends. Except for these sections, the tunnel is wide enough for ants to pass each other. All ants start walking at distinct narrow sections. No ants will newly enter the tunnel. Consequently, all the ants in the tunnel will eventually leave it. Your task is to write a program that tells which is the last ant to leave the tunnel and when it will.

// Figure B.1 shows the movements of the ants during the first two seconds in a tunnel 6 centimeters long. Initially, three ants, numbered 1, 2, and 3, start walking at narrow sections, 1, 2, and 5 centimeters distant from the left end, respectively. After 0.5 seconds, the ants 1 and 2 meet at a wide section, and they pass each other. Two seconds after the start, the ants 1 and 3 meet at a narrow section, and they turn around.

// Figure B.1 corresponds to the first dataset of the sample input.


// Figure B.1. Movements of ants
// Input
// The input consists of one or more datasets. Each dataset is formatted as follows.

// n l
// d1 p1
// d2 p2
// ...
// dn pn
// The first line of a dataset contains two integers separated by a space. n (1 ≤ n ≤ 20) represents the number of ants, and l (n + 1 ≤ l ≤ 100) represents the length of the tunnel in centimeters. The following n lines describe the initial states of ants. Each of the lines has two items, di and pi, separated by a space. Ants are given numbers 1 through n. The ant numbered i has the initial direction di and the initial position pi. The initial direction di (1 ≤ i ≤ n) is L (to the left) or R (to the right). The initial position pi (1 ≤ i ≤ n) is an integer specifying the distance from the left end of the tunnel in centimeters. Ants are listed in the left to right order, that is, 1 ≤ p1 < p2 < ... < pn ≤ l - 1.

// The last dataset is followed by a line containing two zeros separated by a space.

// Output
// For each dataset, output how many seconds it will take before all the ants leave the tunnel, and which of the ants will be the last. The last ant is identified by its number. If two ants will leave at the same time, output the number indicating the ant that will leave through the left end of the tunnel.

#include <bits/stdc++.h>
using namespace std;
int n,l;
int maze[110][22];
int p[22], d[22];
int main() {
    while (cin >> n >> l) {
        if (n == 0 && l == 0) break;
        for (int i = 0; i < 110; i++) {
            for (int j = 0; j < 22; j++) {
                maze[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            int pp;
            char dd;
            cin >> dd >> pp;
            p[i] = pp;
            d[i] = (dd=='L'?-1:1);
        }
        int last = 0;
        bool out = 0;
        int left = n;
        int t = 0;
        while (left > 0) {
            t++;
            out = 0;
            for (int i = 0; i < n; i++) {
                if (p[i] > 0 && p[i] < l) {
                    p[i] += d[i];
                    if (p[i] == l) {
                        if (!out) last = i;
                        left--;
                    } else if (p[i] == 0) {
                        last = i;
                        left--;
                        out = 1;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (p[i] > 0 && p[i] < l && p[j] > 0 && p[j] < l) {
                        if (p[i] == p[j]) {
                            d[i] = -d[i];
                            d[j] = -d[j];
                        }
                    }
                }
            }
        }
        cout << t << " " << last + 1 << endl;
    }
}