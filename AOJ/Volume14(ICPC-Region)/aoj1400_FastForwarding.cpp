// Fast Forwarding
// Mr. Anderson frequently rents video tapes of his favorite classic films. Watching the films so many times, he has learned the precise start times of his favorite scenes in all such films. He now wants to find how to wind the tape to watch his favorite scene as quickly as possible on his video player.

// When the [play] button is pressed, the film starts at the normal playback speed. The video player has two buttons to control the playback speed: The [3x] button triples the speed, while the [1/3x] button reduces the speed to one third. These speed control buttons, however, do not take effect on the instance they are pressed. Exactly one second after playback starts and every second thereafter, the states of these speed control buttons are checked. If the [3x] button is pressed on the timing of the check, the playback speed becomes three times the current speed. If the [1/3x] button is pressed, the playback speed becomes one third of the current speed, unless it is already the normal speed.

// For instance, assume that his favorite scene starts at 19 seconds from the start of the film. When the [3x] button is on at one second and at two seconds after the playback starts, and the [1/3x] button is on at three seconds and at five seconds after the start, the desired scene can be watched in the normal speed five seconds after starting the playback, as depicted in the following chart.


// Your task is to compute the shortest possible time period after the playback starts until the desired scene starts. The playback of the scene, of course, should be in the normal speed.

// Input
// The input consists of a single test case of the following format.

// [Math Processing Error]
// The given single integer [Math Processing Error] ([Math Processing Error]) is the start time of the target scene.

// Output
// Print an integer that is the minimum possible time in seconds before he can start watching the target scene in the normal speed.

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

auto solve (ll n) -> ll {
    ll ret = n - 1;

    // 実際に進める時間は[1~n]
    n--;

    // 最速が3のfastest乗の場合
    rep(fastest, 1, 50) {
        ll ans = 0; // この場合の時間

        ll sum = 0;
        ll ad = 3;
        rep(i,0,fastest-1) {
            sum += ad * 2; // 左と右
            ans += 2;
            ad *= 3;
        }
        sum += ad; // 真ん中
        ans++;
        if (sum > n) break; // 区間を越えたら終了
        // 真ん中をできるだけ再生する
        ll left = n - sum;
        rep(i,0,fastest+1) {
            assert(ad != 0);
            ans += left / ad;
            left %= ad;
            ad /= 3;
        }
        ans += left;
        dbg(ans);
        ret = min(ret, ans);
    }
    return ret + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    ll n;
    cin >> n;

    // solve
    auto ans = solve(n);

    // output
    cout << ans << endl;
    
    return 0;
}