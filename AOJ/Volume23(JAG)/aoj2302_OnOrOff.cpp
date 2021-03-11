// On or Off
// Saving electricity is very important!

// You are in the office represented as R×C grid that consists of walls and rooms. It is guaranteed that, for any pair of rooms in the office, there exists exactly one route between the two rooms. It takes 1 unit of time for you to move to the next room (that is, the grid adjacent to the current room). Rooms are so dark that you need to switch on a light when you enter a room. When you leave the room, you can either leave the light on, or of course you can switch off the light. Each room keeps consuming electric power while the light is on.

// Today you have a lot of tasks across the office. Tasks are given as a list of coordinates, and they need to be done in the specified order. To save electricity, you want to finish all the tasks with the minimal amount of electric power.

// The problem is not so easy though, because you will consume electricity not only when light is on, but also when you switch on/off the light. Luckily, you know the cost of power consumption per unit time and also the cost to switch on/off the light for all the rooms in the office. Besides, you are so smart that you don't need any time to do the tasks themselves. So please figure out the optimal strategy to minimize the amount of electric power consumed.

// After you finished all the tasks, please DO NOT leave the light on at any room. It's obviously wasting!

// Input
// The first line of the input contains three positive integers R (0<R≤50), C (0<C≤50) and M (2≤M≤1000). The following R lines, which contain C characters each, describe the layout of the office. '.' describes a room and '#' describes a wall.

// This is followed by three matrices with R rows, C columns each. Every elements of the matrices are positive integers. The (r,c) element in the first matrix describes the power consumption per unit of time for the room at the coordinate (r,c). The (r,c) element in the second matrix and the third matrix describe the cost to turn on the light and the cost to turn off the light, respectively, in the room at the coordinate (r,c).

// Each of the last M lines contains two positive integers, which describe the coodinates of the room for you to do the task.

// Note that you cannot do the i-th task if any of the j-th task (0≤j≤i) is left undone.

// Output
// Print one integer that describes the minimal amount of electric power consumed when you finished all the tasks.

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

int dh[4] = {-1,0,1,0};
int dw[4] = {0,1,0,-1};

auto solve (int H, int W, int M, VV<char>& maze, V<int>& t, V<int>& on, V<int>& off, V<pair<int,int>>& mission) -> int {
    dbg("here");
    auto getid = [&](int h, int w) {
        return h * W + w;
    };
    
    // i -> jのとき，次に行くマスを記録
    VV<int> nxt(H*W, V<int>(H*W));
    rep(i,0,H) {
        rep(j,0,W) {
            int parent = getid(i,j);
            queue<int> q;
            V<bool> used(H*W);
            q.push(parent);
            used[parent] = 1;
            nxt[parent][parent] = parent;

            while (!q.empty()) {
                auto now = q.front(); q.pop();
                int h = now / W;
                int w = now % W;
                rep(k,0,4) {
                    int th = h + dh[k];
                    int tw = w + dw[k];
                    if (th < 0 || th >= H || tw < 0 || tw >= W) continue;
                    if (maze[th][tw] == '#') continue;
                    int tid = getid(th,tw);
                    if (used[tid]) continue;
                    used[tid] = 1;
                    nxt[tid][parent] = now;
                    q.push(tid);               
                }
            }

        }
    }
dbg("here1");
    // ルートを確定する
    VV<int> rec(H*W);
    int time = 0;
    rep(i,0,M-1) {
        int id = getid(mission[i].first, mission[i].second);
        int nxtid = getid(mission[i+1].first, mission[i+1].second);
        while (id != nxtid) {
            rec[id].push_back(time++);
            id = nxt[id][nxtid];
        }
    }
    rec[getid(mission[M-1].first, mission[M-1].second)].push_back(time);

dbg("here2");
    // result
    int ans = 0;
    rep(i,0,H*W) {
        if (rec[i].size() == 0) continue;
        ans += on[i];
        ans += off[i];
        rep(j,1,rec[i].size()) {
            int ad = (rec[i][j] - rec[i][j-1]) * t[i];
            ans += min(on[i] + off[i], ad);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int r,c,m;
    cin >> r >> c >> m;
    VV<char> maze(r,V<char>(c));
    V<int> t(r*c);
    V<int> on(r*c);
    V<int> off(r*c);
    rep(i,0,r) {
        rep(j,0,c) {
            cin >> maze[i][j];
        }
    }
    rep(i,0,r) {
        rep(j,0,c) {
            cin >> t[i*c+j];
        }
    }
    rep(i,0,r) {
        rep(j,0,c) {
            cin >> on[i*c+j];
        }
    }
    rep(i,0,r) {
        rep(j,0,c) {
            cin >> off[i*c+j];
        }
    }

    V<pair<int,int>> mission(m);
    rep(i,0,m) {
        cin >> mission[i].first >> mission[i].second;
    }

    auto ans = solve(r,c,m,maze,t,on,off,mission);

    cout << ans << endl;
    
    return 0;
}