// Problem Statement
// Let's consider operations on monochrome images that consist of hexagonal pixels, each of which is colored in either black or white. Because of the shape of pixels, each of them has exactly six neighbors (e.g. pixels that share an edge with it.)

// "Filtering" is an operation to determine the color of a pixel from the colors of itself and its six neighbors. Examples of filterings are shown below.

// Example 1: Color a pixel in white when all of its neighboring pixels are white. Otherwise the color will not change.



// Performing this operation on all the pixels simultaneously results in "noise canceling," which removes isolated black pixels.

// Example 2: Color a pixel in white when its all neighboring pixels are black. Otherwise the color will not change.



// Performing this operation on all the pixels simultaneously results in "edge detection," which leaves only the edges of filled areas.

// Example 3: Color a pixel with the color of the pixel just below it, ignoring any other neighbors.



// Performing this operation on all the pixels simultaneously results in "shifting up" the whole image by one pixel.

// Applying some filter, such as "noise canceling" and "edge detection," twice to any image yields the exactly same result as if they were applied only once. We call such filters idempotent. The "shifting up" filter is not idempotent since every repeated application shifts the image up by one pixel.

// Your task is to determine whether the given filter is idempotent or not.

// Input
// The input consists of multiple datasets. The number of dataset is less than $100$. Each dataset is a string representing a filter and has the following format (without spaces between digits).

//  $c_0c_1\cdots{}c_{127}$
// $c_i$ is either '0' (represents black) or '1' (represents white), which indicates the output of the filter for a pixel when the binary representation of the pixel and its neighboring six pixels is $i$. The mapping from the pixels to the bits is as following:



// and the binary representation $i$ is defined as $i = \sum_{j=0}^6{\mathit{bit}_j \times 2^j}$, where $\mathit{bit}_j$ is $0$ or $1$ if the corresponding pixel is in black or white, respectively. Note that the filter is applied on the center pixel, denoted as bit 3.

// The input ends with a line that contains only a single "#".

// Output
// For each dataset, print "yes" in a line if the given filter is idempotent, or "no" otherwise (quotes are for clarity).

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

int dh[7] = { 1,1,0,-1,-1, 0,0};
int dw[7] = {-1,0,1, 1, 0,-1,0};
string s;
int h[19] = {0,0,0,1,1,1,1,2,2,2,2,2,3,3,3,3,4,4,4};
int w[19] = {2,3,4,1,2,3,4,0,1,2,3,4,0,1,2,3,0,1,2};
int id[5][5] = {
    {-1,-1, 0, 1, 2},
    {-1, 3, 4, 5, 6},
    { 7, 8, 9,10,11},
    {12,13,14,15,-1},
    {16,17,18,-1,-1}
};

int filter (int hh, int ww, bitset<19> status) {
    V<int> order = {6,4,1,0,2,5,3};
    int tmp = 0;
    rep(k,0,7) {
        tmp += (status[id[hh+dh[k]][ww+dw[k]]] << order[k]);
    }
    return s[tmp] - '0';
};

auto solve () -> string {
    
    rep(i,0,(1<<19)) {
        bitset<19> bit(i);

        // 一回目
        bitset<19> bit1(0);
        rep(j,0,7) {
            int th = 2 + dh[j];
            int tw = 2 + dw[j];
            int ret = filter(th, tw, bit);
            if (ret) bit1.set(id[th][tw]);
            else bit1.reset(id[th][tw]);
        }

        int before = bit1[id[2][2]];

        // 二回目
        int after = filter(2,2,bit1);

        if (before != after) return "no";
    }
    return "yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    while (1) {
        // input
        cin >> s;
        if (s == "#") break;

        // solve
        auto ans = solve();

        // output
        cout << ans << endl;
        
    }

    return 0;
}