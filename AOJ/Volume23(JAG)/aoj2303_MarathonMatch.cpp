// Marathon Match
// N people run a marathon. There are M resting places on the way. For each resting place, the i-th runner takes a break with probability Pi percent. When the i-th runner takes a break, he gets rest for Ti time.

// The i-th runner runs at constant speed Vi, and the distance of the marathon is L.

// You are requested to compute the probability for each runner to win the first place. If a runner arrives at the goal with another person at the same time, they are not considered to win the first place.

// Input
// A dataset is given in the following format:

// N M L
// P1 T1 V1
// P2 T2 V2
// …
// PN TN VN
// The first line of a dataset contains three integers N (1≤N≤100), M (0≤M≤50) and L (1≤L≤100,000). N is the number of runners. M is the number of resting places. L is the distance of the marathon.

// Each of the following N lines contains three integers Pi (0≤Pi≤100), Ti (0≤Ti≤100) and Vi (0≤Vi≤100) describing the i-th runner. Pi is the probability to take a break. Ti is the time of resting. Vi is the speed.

// Output
// For each runner, you should answer the probability of winning. The i-th line in the output should be the probability that the i-th runner wins the marathon. Each number in the output should not contain an error greater than 10−5.

#include <bits/stdc++.h>
using namespace std;
int n,m;
double l, p[110], v[110], t[110];
double tt[110][55];
double probability[110][55];
const int MAXN = 55;
long long kai[MAXN+1];
long long inv[MAXN+1];
long long mod = 1e9+7;
long long mp(long long a, long long b) {
    long long res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}
/* do this first */
void init() {
    kai[0] = 1;
    for (long long i = 1; i <= MAXN; i++) kai[i] = kai[i - 1] * i % mod;
    inv[MAXN] = mp(kai[MAXN], mod-2);
    for (long long i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % mod;
}
long long combination(long long n, long long k) {
    if (n < k) return 0;
    return (kai[n] * inv[k]) % mod * inv[n - k] % mod;
}
double eps = 1e-10;
int main() {
    init();
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) cin >> p[i] >> t[i] >> v[i];
    // calc time
    for (int i = 0; i < n; i++) {
        tt[i][0] = l / v[i];
        for (int j = 1; j <= m; j++) {
            tt[i][j] = tt[i][j-1] + t[i];
        }
        // for (int j = 0; j <= m; j++) {
        //     cout << tt[i][j] << " ";
        // }
        // cout << endl;
    }
    // calc probability
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            probability[i][0] = 1;
            continue;
        }
        if (p[i] == 100) {
            probability[i][m] = 1;
            continue;
        }
        probability[i][0] = 1;
        for (int j = 0; j < m; j++) {
            probability[i][0] *= (100 - p[i]) / 100;
        }
        for (int j = 1; j <= m; j++) {
            probability[i][j] = probability[i][j-1] * p[i] / (100 - p[i]);
        }
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < j; k++) {
                probability[i][j] *= (double)(m-k) / (double)(k+1);
            }
            // cout << fixed << setprecision(20) << probability[i][j] << " ";
        }
        // cout << endl;
    }
    // calc ans
    // probability for ith person to win
    for (int i = 0; i < n; i++) {
        double ans = 0;
        // probability for ith person to win when he gets j times to rest
        for (int j = 0; j <= m; j++) {
            double ta = tt[i][j];
            double prob = 1;
            // when i compares to person k
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                double sum = 0;
                // when person k takes q times of rest
                for (int q = 0; q <= m; q++) {
                    double tb = tt[k][q];
                    if (ta < tb) {
                        sum += probability[k][q];
                    }
                }
                prob *= sum;
            }
            ans += prob * probability[i][j];
        }
        cout << fixed << setprecision(20) << ans << endl;
    }
    return 0;
}