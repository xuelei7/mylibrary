#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
struct LazySegmentTree {
private:
    LL n;
    vector<LL> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<LL> v) {
        LL sz = (LL) v.size();
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, INF);
        lazyFlag.resize(2 * n - 1, false);

        for (LL i = 0; i < sz; i++) node[i + n - 1] = v[i];
        for (LL i = n - 2; i >= 0; i--) node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void lazyEvaluate(LL k, LL l, LL r) {
        if (lazyFlag[k]) {
            node[k] = min(node[k], lazy[k]);
            if (r - l > 1) {
                lazy[k * 2 + 1] = min(lazy[k * 2 + 1], lazy[k]);
                lazy[k * 2 + 2] = min(lazy[k * 2 + 2], lazy[k]);
                lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
            }
            lazyFlag[k] = false;
        }
    }

    void update(LL a, LL b, LL x, LL k = 0, LL l = 0, LL r = -1) {
        if (r < 0) r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = min(lazy[k], x);
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    LL find(LL a, LL b, LL k = 0, LL l = 0, LL r = -1) {
        if (r < 0) r = n;
        lazyEvaluate(k, l, r);
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return node[k];
        LL vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        LL vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};
int main() {
    return 0;
}