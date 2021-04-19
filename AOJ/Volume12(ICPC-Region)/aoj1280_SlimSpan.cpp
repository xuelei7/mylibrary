// Problem F: Slim Span
// Given an undirected weighted graph G, you should find one of spanning trees specified as follows.

// The graph G is an ordered pair (V, E), where V is a set of vertices {v1, v2, ... , vn} and E is a set of undirected edges {e1, e2, ... , em}. Each edge e ∈ E has its weight w(e).

// A spanning tree T is a tree (a connected subgraph without cycles) which connects all the n vertices with n - 1 edges. The slimness of a spanning tree T is defined as the difference between the largest weight and the smallest weight among the n - 1 edges of T.


// Figure 5: A graph G and the weights of the edges

// For example, a graph G in Figure 5(a) has four vertices {v1, v2, v3, v4} and five undirected edges {e1, e2, e3, e4, e5}. The weights of the edges are w(e1) = 3, w(e2) = 5, w(e3) = 6, w(e4) = 6, w(e5) = 7 as shown in Figure 5(b).


// Figure 6: Examples of the spanning trees of G

// There are several spanning trees for G. Four of them are depicted in Figure 6(a)-(d). The spanning tree Ta in Figure 6(a) has three edges whose weights are 3, 6 and 7. The largest weight is 7 and the smallest weight is 3 so that the slimness of the tree Ta is 4. The slimnesses of spanning trees Tb , Tc and Td shown in Figure 6(b), (c) and (d) are 3, 2 and 1, respectively. You can easily see the slimness of any other spanning tree is greater than or equal to 1, thus the spanning tree Td in Figure 6(d) is one of the slimmest spanning trees whose slimness is 1.

// Your job is to write a program that computes the smallest slimness.

// Input
// The input consists of multiple datasets, followed by a line containing two zeros separated by a space. Each dataset has the following format.

// n     m
// a1  b1  w1
//   .
//   .
//   .
// am  bm  wm
// Every input item in a dataset is a non-negative integer. Items in a line are separated by a space.

// n is the number of the vertices and m the number of the edges. You can assume 2 ≤ n ≤ 100 and 0 ≤ m ≤ n(n - 1)/2. ak and bk (k = 1, ... , m) are positive integers less than or equal to n, which represent the two vertices vak and vbk connected by the kth edge ek. wk is a positive integer less than or equal to 10000, which indicates the weight of ek . You can assume that the graph G = (V, E) is simple, that is, there are no self-loops (that connect the same vertex) nor parallel edges (that are two or more edges whose both ends are the same two vertices).

// Output
// For each dataset, if the graph has spanning trees, the smallest slimness among them should be printed. Otherwise, -1 should be printed. An output should not contain extra characters.

#include <bits/stdc++.h>
using namespace std;
int d[110][110];
bool used[110];
int n,m;
void dfs(int k, int f, int t) {
    used[k] = 1;
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        if (d[k][i] < f || d[k][i] > t) continue;
        dfs(i,f,t);
    }
}

bool ok(int f, int t) {
    memset(used,0,sizeof(used));
    dfs(1,f,t);
    for (int i = 1; i <= n; i++) if (!used[i]) return 0;
    // cout << "ok " << f << " " << t << endl;
    return 1;
}

bool ok(int k) {
    for (int i = 1; i <= 10000; i++) {
        if (ok(i,i+k)) return 1;
    }
    return 0;
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            d[a][b] = c;
            d[b][a] = c;
        }
        int l = 0, r = 100000;
        while (l < r) {
            int mid = (l + r) / 2;
            if (ok(mid)) r = mid;
            else l = mid + 1;
        }
        if (r == 100000) cout << -1 << endl;
        else cout << r << endl;
    }
    return 0;
}