// from
// aoj0002
int digitnum(int k) {
    if (k == 0) return 1;
    int cnt = 0;
    while (k > 0) {
        k /= 10;
        cnt++;
    }
    return cnt;
}