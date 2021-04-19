// Problem C: One-Dimensional Cellular Automaton
// There is a one-dimensional cellular automaton consisting of N cells. Cells are numbered from 0 to N − 1.

// Each cell has a state represented as a non-negative integer less than M. The states of cells evolve through discrete time steps. We denote the state of the i-th cell at time t as S(i, t). The state at time t + 1 is defined by the equation

// S(i, t + 1) = (A × S(i − 1, t) + B × S(i, t) + C × S(i + 1, t)) mod M,         (1)

// where A, B and C are non-negative integer constants. For i < 0 or N ≤ i, we define S(i, t) = 0.

// Given an automaton definition and initial states of cells, your mission is to write a program that computes the states of the cells at a specified time T.

// Input
// The input is a sequence of datasets. Each dataset is formatted as follows.

// N M A B C T
// S(0, 0) S(1, 0) ... S(N − 1, 0)
// The first line of a dataset consists of six integers, namely N, M, A, B, C and T. N is the number of cells. M is the modulus in the equation (1). A, B and C are coefficients in the equation (1). Finally, T is the time for which you should compute the states.

// You may assume that 0 < N ≤ 50, 0 < M ≤ 1000, 0 ≤ A, B, C < M and 0 ≤ T ≤ 109.

// The second line consists of N integers, each of which is non-negative and less than M. They represent the states of the cells at time zero.

// A line containing six zeros indicates the end of the input.

// Output
// For each dataset, output a line that contains the states of the cells at time T. The format of the output is as follows.

// S(0, T) S(1, T) ... S(N − 1, T)

// Each state must be represented as an integer and the integers must be separated by a space.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
int mod,n;
mat A(55,vec(55));
mat mul(mat a, mat b) {
    mat c(55,vec(55));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
mat mul(mat m, int t) {
    if (t == 0) {
        mat ret(55, vec(55));
        for (int i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
    }
    mat ret = mul(m,t/2);
    ret = mul(ret,ret);
    // cout << "mul " << t/2*2 << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << ret[i][j] << " \n"[j == n - 1];
    //     }
    // }
    if (t&1) ret = mul(ret,m);
    // cout << "mul " << t << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << ret[i][j] << " \n"[j == n - 1];
    //     }
    // }
    return ret;
}
vec mul(mat m, vec v) {
    vec ret(55);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            ret[i] += m[i][k] * v[k];
            ret[i] %= mod;
        }
    }
    return ret;
}
int main() {
    ll m,a,b,c,t;
    vec v(55);
    while (cin >> n >> m >> a >> b >> c >> t) {
        if (n == 0) break;
        mod = m;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i-1>=0) A[i][i-1] = a;
            A[i][i] = b;
            if (i+1<n) A[i][i+1] = c;
        }
        A = mul(A,t);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << A[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        v = mul(A,v);
        for (int i = 0; i < n; i++) {
            cout << v[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}