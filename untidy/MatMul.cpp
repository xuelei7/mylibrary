#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll M;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) {
        B[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

//F_1 = 0, F_2 = 1
int main() {
    ll n;
    cin >> n >> M;
    mat A(2, vec(2));
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;
    A = pow(A, n-1);
    cout << A[1][0] << endl;
    return 0;
}