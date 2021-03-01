#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct LazySegmentTree {

private:
    int n;
    T init_v;
    vector<T> node;
    vector<T> lazy;

public:
    LazySegmentTree(vector<T> a, T _init_v) {

        n = 1;
        init_v = _init_v;

        int sz = a.size();
        while (n < sz) n *= 2;

        node.resize(2 * n, init_v);
        lazy.resize(2 * n, init_v);

        for (int i = 0; i < sz; i++) node[i + n - 1] = a[i];
        for (int i = n - 2; i >= 0; i--) node[i] = node[i * 2 + 1] + node[i * 2 + 2];
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] += lazy[k] / 2;
                lazy[k * 2 + 2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        } else {
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);
            node[k] = node[k * 2 + 1] + node[k * 2 + 2];
        }
    }

    T getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return node[k];
        T lv = getsum(a, b, k * 2 + 1, l, (l + r) / 2);
        T rv = getsum(a, b, k * 2 + 2, (l + r) / 2, r);
        return lv + rv;
    }

};
int main() {
    return 0;
}