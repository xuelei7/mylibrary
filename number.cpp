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
// aoj0009
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

// from aoj0019
long long factorial(long long n) {
    long long ans = 1;
    for (long long i = 2LL; i <= n; i++) ans *= i;
    return ans;
}