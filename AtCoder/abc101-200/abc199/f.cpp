#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

typedef vector<ll> vec;
typedef vector<vec> mat;

ll M = 1e9+7;

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


ll mod = 1e9+7;
long long mp(long long a, long long b) {
    long long res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}

ll rev2, revm;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    rev2 = mp(2,mod-2);


    ll n,m,k;
    cin >> n >> m >> k;
    revm = mp(m, mod-2);

    V<ll> a(n);
    rep(i,0,n) cin >> a[i];
    V<ll> x(m), y(m);

    mat maze(n, vec(n));

    rep(i,0,m) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        maze[x[i]][y[i]] = 1;
        maze[y[i]][x[i]] = 1;
    }

    V<ll> cnt(n);
    rep(i,0,m) {
        cnt[x[i]]++;
        cnt[y[i]]++;
    }
    mat A(n, vec(n,0));
    rep(i,0,n) {
        rep(j,0,n) {
            if (maze[i][j] == 1) {
                A[i][j] = rev2 * revm % mod;
            }
        }
    }
    rep(i,0,n) {
        // cnt/2m
        A[i][i] = ((cnt[i] * revm) % mod * rev2) % mod;
        A[i][i] %= mod;
        // (m-cnt)/m
        A[i][i] += ((m-cnt[i]) * revm) % mod;
        A[i][i] %= mod;
    }

    // rep(i,0,n) {
    //     rep(j,0,n) {
    //         cout << setw(10) << A[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    mat B = pow(A, k);
    vec ret(n);

    rep(i,0,n) {
        rep(j,0,n) {
            ret[i] += B[i][j] * a[j] % mod;
            ret[i] %= mod;
        }
    }
    rep(i,0,n) {
        cout << ret[i] << endl;
    }
    return 0;
}