// Problem D: Futon
// The sales department of Japanese Ancient Giant Corp. is visiting a hot spring resort for their recreational trip. For deepening their friendships, they are staying in one large room of a Japanese-style hotel called a ryokan.

// In the ryokan, people sleep in Japanese-style beds called futons. They all have put their futons on the floor just as they like. Now they are ready for sleeping but they have one concern: they don’t like to go into their futons with their legs toward heads — this is regarded as a bad custom in Japanese tradition. However, it is not obvious whether they can follow a good custom. You are requested to write a program answering their question, as a talented programmer.

// Here let's model the situation. The room is considered to be a grid on an xy-plane. As usual, x-axis points toward right and y-axis points toward up. Each futon occupies two adjacent cells. People put their pillows on either of the two cells. Their heads come to the pillows; their foots come to the other cells. If the cell of some person's foot becomes adjacent to the cell of another person's head, regardless their directions, then it is considered as a bad case. Otherwise people are all right.

// Input
// The input is a sequence of datasets. Each dataset is given in the following format:

// n
// x1 y1 dir1
// ...
// xn yn dirn
// n is the number of futons (1 ≤ n ≤ 20,000); (xi, yi) denotes the coordinates of the left-bottom corner of the i-th futon; diri is either 'x' or 'y' and denotes the direction of the i-th futon, where 'x' means the futon is put horizontally and 'y' means vertically. All coordinate values are non-negative integers not greater than 109 .

// It is guaranteed that no two futons in the input overlap each other.

// The input is terminated by a line with a single zero. This is not part of any dataset and thus should not be processed.

// Output
// For each dataset, print "Yes" in a line if it is possible to avoid a bad case, or "No" otherwise.

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

auto solve (int N, V<int>& X, V<int>& Y, V<char>& D) -> string {
    struct P{
        int x,y;
        P(){}
        P(int x, int y) : x(x), y(y) {}
        bool operator < (const P& other) const {
            if (x != other.x) return x < other.x;
            return y < other.y;
        }
    }; 
    map<P, bool> decided;
    set<P> undecided;
    map<P, int> ids;
    
    // put points into undecided set
    rep(i,0,N) {
        P p(X[i], Y[i]);
        undecided.insert(p);
        ids[p] = i;

        p = P(X[i] + (D[i] == 'x'), Y[i] + (D[i] == 'y'));
        undecided.insert(p);
        ids[p] = i;
    }


    int dh[4] = {-1,0,1,0};
    int dw[4] = {0,1,0,-1};

    while (!undecided.empty()) {

        // take out a point and decide
        auto p = *(undecided.begin());
        undecided.erase(p);
        
        bool flg = 1; // head or tail
        decided[p] = flg;
        

        // see all the linked futons
        queue<pair<P,bool>> q;
        q.push({p,flg});

        while (!q.empty()) {
            auto tp = q.front();
            p = tp.first;
            flg = tp.second; // head or tail
            q.pop();
#ifdef LOCAL
    cerr << p.x << " " << p.y << " " << flg << endl;
#endif

            rep(i,0,4) {
                int th = p.y + dh[i];
                int tw = p.x + dw[i];
                P nxtp(tw,th);
                // already decided
                if (decided.count(nxtp)) {
                    // check if they are good
                    // same id
                    if (ids[nxtp] == ids[p]){
                        if (flg != decided[nxtp]) continue;
                        else return "No";
                    }
                    // different id
                    else {
                        if (flg == decided[nxtp]) continue;
                        else return "No";
                    }
                }
                // undecided
                else if (undecided.count(nxtp)) {
                    undecided.erase(nxtp);
                    // same id
                    if (ids[nxtp] == ids[p]) {
                        decided[nxtp] = !flg;
                        q.push({nxtp, !flg});
                    }
                    // different id
                    else {
                        decided[nxtp] = flg;
                        q.push({nxtp, flg});
                    }
                }
                // else not a futon
                // do nothing
            }
        }

    }

    return "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        V<int> X(n), Y(n);
        V<char> D(n);
        rep(i,0,n) {
            cin >> X[i] >> Y[i] >> D[i];
        }
        auto ans = solve(n,X,Y,D);
        cout << ans << endl;
    }
    
    return 0;
}