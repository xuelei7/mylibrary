// Problem D: Weather Forecast
// You are the God of Wind.

// By moving a big cloud around, you can decide the weather: it invariably rains under the cloud, and the sun shines everywhere else.

// But you are a benign God: your goal is to give enough rain to every field in the countryside, and sun to markets and festivals. Small humans, in their poor vocabulary, only describe this as “weather forecast”.

// You are in charge of a small country, called Paccimc. This country is constituted of 4 × 4 square areas, denoted by their numbers.


// Your cloud is of size 2 × 2, and may not cross the borders of the country.

// You are given the schedule of markets and festivals in each area for a period of time.

// On the first day of the period, it is raining in the central areas (6-7-10-11), independently of the schedule.

// On each of the following days, you may move your cloud by 1 or 2 squares in one of the four cardinal directions (North, West, South, and East), or leave it in the same position. Diagonal moves are not allowed. All moves occur at the beginning of the day.

// You should not leave an area without rain for a full week (that is, you are allowed at most 6 consecutive days without rain). You don’t have to care about rain on days outside the period you were given: i.e. you can assume it rains on the whole country the day before the period, and the day after it finishes.

// Input
// The input is a sequence of data sets, followed by a terminating line containing only a zero.

// A data set gives the number N of days (no more than 365) in the period on a single line, followed by N lines giving the schedule for markets and festivals. The i-th line gives the schedule for the i-th day. It is composed of 16 numbers, either 0 or 1, 0 standing for a normal day, and 1 a market or festival day. The numbers are separated by one or more spaces.

// Output
// The answer is a 0 or 1 on a single line for each data set, 1 if you can satisfy everybody, 0 if there is no way to do it.

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

bool visited[367][3][3][8][8][8][8];
int dh[4] = {-1,0,1,0};
int dw[4] = {0,1,0,-1};

auto solve (int N, V<bitset<16>>& Vec) -> int {

    if (Vec[0][5] || Vec[0][6] || Vec[0][9] || Vec[0][10]) return 0;

    memset(visited,0,sizeof(visited));    
    struct S{
        int day,h,w,a,b,c,d;
    };
    queue<S> q;
    q.push((S){0,1,1,1,1,1,1});
    while (!q.empty()) {
        auto tp = q.front(); q.pop();
#ifdef LOCAL
    cerr << tp.day << " " << tp.h << " " << tp.w << endl;
    cerr << tp.a << " " << tp.b << " " << tp.c << " " << tp.d << endl;
#endif
        if (tp.day == N-1) return 1;
    
        rep(i,0,4) {
            rep(j,0,3) {
                int tday = tp.day + 1;
                int ta = tp.a + 1;
                int tb = tp.b + 1;
                int tc = tp.c + 1;
                int td = tp.d + 1;
                int th = tp.h + dh[i] * j;
                int tw = tp.w + dw[i] * j;
                if (th < 0 || tw < 0 || th >= 3 || tw >= 3) continue;

                int id = th*4+tw;
                if (id == 0) ta = 0;
                if (id == 2) tb = 0;
                if (id == 8) tc = 0;
                if (id == 10) td = 0;
                
                if (Vec[tday][id]) continue;
                if (Vec[tday][id+1]) continue;
                if (Vec[tday][id+4]) continue;
                if (Vec[tday][id+5]) continue;
                
                if (ta == 7 || tb == 7 || tc == 7 || td == 7) continue;

                if (visited[tday][th][tw][ta][tb][tc][td]) continue;
                visited[tday][th][tw][ta][tb][tc][td] = 1;
                q.push((S){tday,th,tw,ta,tb,tc,td});
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        V<bitset<16>> v(n);
        rep(i,0,n) {
            rep(j,0,16) {
                int bit;
                cin >> bit;
                if (bit) {
                    v[i].set(j);
                }
            }
        }
        auto ans = solve(n,v);
        cout << ans << endl;
    }
    
    return 0;
}