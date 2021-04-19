#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 100010;
const int MAX_V = 20;
int N;
int dep[MAX_N];
int par[MAX_V][MAX_N];

void init() {
    /* find dep and par[0][...] */

    for (int i = 1; i < MAX_V; i++) {
        for (int j = 0; j < N; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
}

int LCA(int u, int v) {
    //to the same height
    for (int i = 19; i >= 0; i--) if (dep[u] - (1 << i) >= dep[v]) u = par[i][u];
    for (int i = 19; i >= 0; i--) if (dep[v] - (1 << i) >= dep[u]) v = par[i][v];
    if (u == v) return u;
    //to one step before LCA
    for (int i = MAX_V-1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}

int main() {
    return 0;
}