// from
// aoj0003
bool isRightTriangle(int a, int b, int c) {
    if (b > a) {
        int k = b;
        b = a;
        a = k;
    }
    if (c > a) {
        int k = c;
        c = a;
        a = k;
    }
    return a * a == b * b + c * c;
}