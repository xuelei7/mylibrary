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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int a,b;
    cin >> a >> b;
    char ca;
    int cb;

    if (b * 10 < 25*6) {
        cout << "C 0" << endl;
        return 0;
    }
    a *= 10;
    if (a < 1125) cout << "N";
    else if (a < 3375) cout << "NNE";
    else if (a < 5625) cout << "NE";
    else if (a < 7875) cout << "ENE";
    else if (a < 10125) cout << "E";
    else if (a < 12375) cout << "ESE";
    else if (a < 14625) cout << "SE";
    else if (a < 16875) cout << "SSE";
    else if (a < 19125) cout << "S";
    else if (a < 21375) cout << "SSW";
    else if (a < 23625) cout << "SW";
    else if (a < 25875) cout << "WSW";
    else if (a < 28125) cout << "W";
    else if (a < 30375) cout << "WNW";
    else if (a < 32625) cout << "NW";
    else if (a < 34875) cout << "NNW";
    else cout << "N";

    cout << " ";
    
    b *= 10;
    if (b < 25*6) cout << 0;
    else if (b < 155*6) cout << 1;
    else if (b < 335*6) cout << 2;
    else if (b < 545*6) cout << 3;
    else if (b < 795*6) cout << 4;
    else if (b < 1075*6) cout << 5;
    else if (b < 1385*6) cout << 6;
    else if (b < 1715*6) cout << 7;
    else if (b < 2075*6) cout << 8;
    else if (b < 2445*6) cout << 9;
    else if (b < 2845*6) cout << 10;
    else if (b < 3265*6) cout << 11;
    else cout << 12;
    cout << endl;

    return 0;
}