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

struct P{
    int x, y, r, id;
    P(int x=0, int y=0, int r=0, int id=0) : x(x), y(y), r(r), id(id) {}
    bool operator <(const P& other) const {
        return r < other.r;
    }
};

struct S{
    int a,b,c,d,id;
    S(int a=0, int b=0, int c=0, int d=0, int id=0) :a(a),b(b),c(c),d(d),id(id) {}
};

struct Point {
    int x, y;
    Point(int x=0, int y=0) : x(x),y(y) {}
    bool operator <(const Point& other) const {
        if (y != other.y) return y < other.y;
        return x < other.x;
    }
};

auto solve (int n, V<P>& v) -> V<S> {
    // 面積が小さいほうから見る
    sort(all(v));

    V<S> ret(n);
    set<Point> st;

    // version 1: (x,y), (x+1,y+1)
    rep(i,0,n) {
        ret[i] = S(v[i].x,v[i].y,v[i].x+1,v[i].y+1,v[i].id);
        st.insert(Point(v[i].x,v[i].y));
    }

    // version 2: 横だけに伸ばす
    // => cをできるだけ大きくする
    rep(i,0,n) {
        int c = ret[i].c;
        int d = ret[i].d;
        while (!st.count(Point(c,d-1)) && c < 10000) {
            if (c - ret[i].a >= v[ret[i].id].r) break;
            c++;
        }
        ret[i].c = c;
    }

    // version 3: 下に伸ばす
    set<int> sty;
    rep(i,0,n) {
        sty.insert(v[i].y);
    }
    rep(i,0,n) {
        int d = ret[i].d;
        int id = ret[i].id;
        while (!sty.count(d) && d < 10000) {
            if ((ret[i].c - ret[i].a) * (d + 1 - ret[i].b) >= v[id].r) break;
            d++;
        }
        ret[i].d = d;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n;
    cin >> n;
    V<P> v(n);
    rep(i,0,n) {
        cin >> v[i].x >> v[i].y >> v[i].r;
        v[i].id = i;
    }

    // solve
    auto ans = solve(n, v);

    // output
    V<int> a(n),b(n),c(n),d(n);
    rep(i,0,n) {
        a[ans[i].id] = ans[i].a;
        b[ans[i].id] = ans[i].b;
        c[ans[i].id] = ans[i].c;
        d[ans[i].id] = ans[i].d;
    }
    double avg = 0; // 統計
    rep(i,0,n) {
        cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
#ifdef LOCAL
    cerr << i << ", correct: " << v[i].r;
    int area = (c[i] - a[i]) * (d[i] - b[i]);
    cerr << ", actual: " << area;
    cerr << ", error: " << v[i].r - area;
    cerr << ", rate: " << (double)(area)*100.0 / (double)v[i].r << endl;
#endif
        avg += (double)(c[i]-a[i]) * (double)(d[i]-b[i]) * 100.0 / (double)v[i].r / n;
    }
    dbg(avg);
    return 0;
}