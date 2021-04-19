// Estimating the Flood Risk
// Mr. Boat is the owner of a vast extent of land. As many typhoons have struck Japan this year, he became concerned of flood risk of his estate and he wants to know the average altitude of his land. The land is too vast to measure the altitude at many spots. As no steep slopes are in the estate, he thought that it would be enough to measure the altitudes at only a limited number of sites and then approximate the altitudes of the rest based on them.

// Multiple approximations might be possible based on the same measurement results, in which case he wants to know the worst case, that is, one giving the lowest average altitude.

// Mr. Boat’s estate, which has a rectangular shape, is divided into grid-aligned rectangular areas of the same size. Altitude measurements have been carried out in some of these areas, and the measurement results are now at hand. The altitudes of the remaining areas are to be approximated on the assumption that altitudes of two adjoining areas sharing an edge differ at most 1.

// In the first sample given below, the land is divided into 5 × 4 areas. The altitudes of the areas at (1, 1) and (5, 4) are measured 10 and 3, respectively. In this case, the altitudes of all the areas are uniquely determined on the assumption that altitudes of adjoining areas differ at most 1.

// In the second sample, there are multiple possibilities, among which one that gives the lowest average altitude should be considered.

// In the third sample, no altitude assignments satisfy the assumption on altitude differences.


// Your job is to write a program that approximates the average altitude of his estate. To be precise, the program should compute the total of approximated and measured altitudes of all the mesh-divided areas. If two or more different approximations are possible, the program should compute the total with the severest approximation, that is, one giving the lowest total of the altitudes.

// Input
// The input consists of a single test case of the following format.

// [Math Processing Error] [Math Processing Error] [Math Processing Error]
// [Math Processing Error] [Math Processing Error] [Math Processing Error]
// .
// .
// .
// [Math Processing Error] [Math Processing Error] [Math Processing Error]
// Here, [Math Processing Error], [Math Processing Error], and [Math Processing Error] are integers between [Math Processing Error] and [Math Processing Error], inclusive. [Math Processing Error] and [Math Processing Error] are the numbers of areas in the two sides of the land. [Math Processing Error] is the number of areas where altitudes are measured. The [Math Processing Error]-th line of the following [Math Processing Error] lines contains three integers, [Math Processing Error], [Math Processing Error], and [Math Processing Error] satisfying [Math Processing Error], [Math Processing Error], and [Math Processing Error]. They mean that the altitude of the area at [Math Processing Error] was measured to be [Math Processing Error]. At most one measurement result is given for the same area, i.e., for [Math Processing Error], [Math Processing Error].

// Output
// If all the unmeasured areas can be assigned their altitudes without any conflicts with the measured altitudes assuming that two adjoining areas have the altitude difference of at most 1, output an integer that is the total of the measured or approximated altitudes of all the areas. If more than one such altitude assignment is possible, output the minimum altitude total among the possible assignments.

// If no altitude assignments satisfy the altitude difference assumption, output No.

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

struct S {
    int x, y, z;
    S(int x=0, int y=0, int z=0) : x(x), y(y), z(z) {}
    bool operator >(const S& s) const {
        if (z != s.z) return z > s.z;
        if (x != s.x) return x > s.x;
        return y > s.y;
    }
    bool operator <(const S& s) const {
        if (z != s.z) return z < s.z;
        if (x != s.x) return x < s.x;
        return y < s.y;
    }
};

auto solve (int w, int h, int d, V<S>& s) -> string {
    
    VV<int> maze(h,V<int>(w));
    VV<int> used(h,V<int>(w,0));

    priority_queue<S> pq;
    rep(i,0,d) {
        pq.push(s[i]);
        used[s[i].y][s[i].x] = 1;
        maze[s[i].y][s[i].x] = s[i].z;
    }
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
#ifdef LOCAL
    cerr << tp.x << " " << tp.y << " " << tp.z << endl;
#endif
        int dy[4] = {-1,0,1,0};
        int dx[4] = {0,1,0,-1};
        
        rep(i,0,4) {
            int tx = tp.x + dx[i];
            int ty = tp.y + dy[i];
            int tz = tp.z - 1;
            if (tx < 0 || tx >= w || ty < 0 || ty >= h) continue;
            if (used[ty][tx]) {
                if (abs(maze[ty][tx] - tp.z) > 1) return "No";
            } else {
                maze[ty][tx] = tz;
                used[ty][tx] = 1;
                pq.push(S(tx,ty,tz));
            }
        }
#ifdef LOCAL
    rep(i,0,h) {
        rep(j,0,w) {
            cerr << maze[i][j] << " ";
        }
        cerr << endl;
    }
#endif
    }

    int ans = 0;
    rep(i,0,h) {
        rep(j,0,w) {
            ans += maze[i][j];
        }
    }
    return to_string(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int w,h,d;
    cin >> w >> h >> d;
    V<S> s(d);
    rep(i,0,d) {
        cin >> s[i].x >> s[i].y >> s[i].z;
        s[i].x--;
        s[i].y--;
    }

    // solve
    auto ans = solve(w,h,d,s);

    // output
    cout << ans << endl;
    
    return 0;
}