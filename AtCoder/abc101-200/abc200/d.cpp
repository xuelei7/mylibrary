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
    
    ll n;
    cin >> n;
    V<ll> a(n);
    rep(i,0,n) {
        cin >> a[i];
    }

    V<int> track1[210];
    rep(i,0,n) {
        V<int> v;
        rep(j,0,200) {
            if (track1[j].size() == 0) continue;
            int k = (j + a[i]) % 200;
            if (track1[k].size() == 0) v.push_back(j);
            else {
                cout << "Yes" << endl;
                cout << track1[k].size();
                for (auto e: track1[k]) {
                    cout << " " << e+1;
                }
                cout << endl;

                cout << track1[j].size()+1;
                for (auto e: track1[j]) {
                    cout << " " << e+1;
                }
                cout << " " << i+1 << endl;
                return 0;
            }
        }

        for (auto e:v) {
            for (auto ee: track1[e]) {
                track1[(e+a[i])%200].push_back(ee);
            }
            track1[(e+a[i])%200].push_back(i);
        }

        if (track1[a[i]%200].size() == 0) track1[a[i]%200].push_back(i);
        else {
            cout << "Yes" << endl;
            cout << track1[a[i]%200].size();
            for (auto e: track1[a[i]%200]) {
                cout << " " << e+1;
            }
            cout << endl;
            cout << "1 " << i+1 << endl;
            return 0;
        }
    }

    // rep(i,0,200) {
    //     if (track1[i].size() != 0) {
    //         cout << i;
    //         for (auto e: track1[i]) {
    //             cout << " " << e;
    //         }
    //         cout << endl;
    //     }
    // }

    cout << "No" << endl;
    
    return 0;
}