// from
// aoj0005
long long GCD(long long a, long long b) {
    if (a > b) {
        long long k = b;
        b = a;
        a = k;
    }
    if (b % a == 0) return a;
    return GCD(b % a, a);
}
long long LCM(long long a, long long b) {
    return a / GCD(a,b) * b;
}

// from
// aoj0009, aoj0044, aoj0053, aoj0056, aoj0150, aoj0165
// aoj1232, aoj1276
// get all the primes in the vector that is less than MAXN
vector<int> getPrimeList() {
    const int MAXN = 1000000;
    bool isprime[MAXN];
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    vector<int> v;
    for (int i = 2; i < MAXN; i++) if (isprime[i]) v.push_back(i);
    return v;
}
// from
// aoj0056
vector<bool> getPrimeList() {
    const int MAXN = 1000000;
    vector<bool> isprime(MAXN);
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    return isprime;
}

// from aoj0019
// 階乗
long long factorial(long long n) {
    long long ans = 1;
    for (long long i = 2LL; i <= n; i++) ans *= i;
    return ans;
}

// from aoj0045
int rounding(double n) {
    int intn = n * 2;
    return (intn + 1) / 2;
}

// from
// aoj0062
// calculate combination
// check if the question asked to mod!!!
const int MAXN = /*set here*/;
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

// menu
// long long GCD(long long a, long long b)
// long long LCM(long long a, long long b)
// vector<int> getPrimeList()
// vector<bool> getPrimeList()
// long long factorial(long long n) (階乗)
// int rounding(double n) (四捨五入)
// long long combination(long long n, long long k)
