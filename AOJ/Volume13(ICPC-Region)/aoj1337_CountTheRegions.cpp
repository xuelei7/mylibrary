// Problem C: Count the Regions
// There are a number of rectangles on the x-y plane. The four sides of the rectangles are parallel to either the x-axis or the y-axis, and all of the rectangles reside within a range specified later. There are no other constraints on the coordinates of the rectangles.

// The plane is partitioned into regions surrounded by the sides of one or more rectangles. In an example shown in Figure C.1, three rectangles overlap one another, and the plane is partitioned into eight regions.

// Rectangles may overlap in more complex ways. For example, two rectangles may have overlapped sides, they may share their corner points, and/or they may be nested. Figure C.2 illustrates such cases.

// Your job is to write a program that counts the number of the regions on the plane partitioned by the rectangles.

// Input
// The input consists of multiple datasets. Each dataset is formatted as follows.

// n
// l1 t1 r1 b1
// l2 t2 r2 b2
// :
// ln tn rn bn
// A dataset starts with n (1 ≤ n ≤ 50), the number of rectangles on the plane. Each of the following n lines describes a rectangle. The i-th line contains four integers, li, ti, ri, and bi, which are the coordinates of the i-th rectangle; (li, ti) gives the x-y coordinates of the top left corner, and (ri, bi) gives that of the bottom right corner of the rectangle (0 ≤ li < ri ≤ 106, 0 ≤ bi < ti ≤ 106, for 1 ≤ i ≤ n). The four integers are separated by a space.

// The input is terminated by a single zero.

// Output
// For each dataset, output a line containing the number of regions on the plane partitioned by the sides of the rectangles.


// Figure C.1. Three rectangles partition the plane into eight regions. This corresponds to the first dataset of the sample input. The x- and y-axes are shown for illustration purposes only, and therefore they do not partition the plane.


// Figure C.2. Rectangles overlapping in more complex ways. This corresponds to the second dataset.

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

const int MAX_N = 1010;
int N,W,H;
int X1[MAX_N], X2[MAX_N], Y1[MAX_N], Y2[MAX_N];

//x1, x2を座標圧縮し，座標圧縮した際の幅を返す
int compress(int *x1, int *x2, int w) {
    vector<int> xs;

    for (int i = 0; i < N; i++) {
        //keep 1 lines each on two sides nearby
        for (int d = -1; d <= 1; d++) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            xs.push_back(tx1);
            xs.push_back(tx2);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    for (int i = 0; i < N; i++) {
        x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }

    return xs.size();
}

int dh[4] = {0,0,1,-1};
int dw[4] = {1,-1,0,0};

struct Rect {
    int l,t,r,b;
    Rect(){}
    Rect(int l, int t, int r, int b):l(l),t(t),r(r),b(b) {}
};

auto solve (int n, V<Rect>& v) -> int {
    // 座圧
    N = n;
    rep(i,0,n) {
        X1[i] = v[i].l;
        X2[i] = v[i].r;
        Y1[i] = v[i].t;
        Y2[i] = v[i].b;
    }
    W = compress(X1, X2, W);
    H = compress(Y1, Y2, H);

    VV<int> maze(H,V<int>(W, 1));

    int cnt = 1;
    rep(i,0,n) {
        map<int,int> id;
        rep(h,Y2[i],Y1[i]) {
            rep(w,X1[i],X2[i]) {
                if (!id.count(maze[h][w])) {
                    id[maze[h][w]] = ++cnt;
                }
                maze[h][w] = id[maze[h][w]];
            }
        }

        // 番号を振り分け直す
        VV<bool> fld(H,V<bool>(W,0));

        auto go = [&](auto self, int h, int w, int org, int c) -> void {
            maze[h][w] = c;
            fld[h][w] = true;
            rep(i,0,4) {
                int th = h + dh[i];
                int tw = w + dw[i];
                if (th < 0 || th >= H || tw < 0 || tw >= W) continue;
                if (fld[th][tw] || maze[th][tw] != org) continue;
                self(self, th, tw, org, c);
            }
        };

        int tmp = 0;
        rep(h,0,H) {
            rep(w,0,W) {
                if (!fld[h][w]) {
                    tmp++;
                    go(go,h,w,maze[h][w], tmp);
                }
            }
        }
        cnt = tmp;
    }

    // 答え
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        V<Rect> rect(n);
        rep(i,0,n) {
            int l,t,r,b;
            cin >> l >> t >> r >> b;
            rect[i] = Rect(l,t,r,b);
        }
        auto ans = solve(n,rect);
        cout << ans << endl;
    }
    
    return 0;
}