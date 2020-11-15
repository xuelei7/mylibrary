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