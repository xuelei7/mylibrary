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

bool solve(int n, int q) {
    bool ret = 0;
    V<int> v(3);
    
    // 初期構築
    cout << "1 2 3" << endl;
#ifdef LOCAL
    cerr << "Me: 1 2 3" << endl;
#endif
    int mid;
    cin >> mid;
#ifdef LOCAL
    cerr << "J: " << mid << endl;
#endif
    if (mid == 1) {
        v = {2,1,3};
    } else if (mid == 2) {
        v = {1,2,3};
    } else {
        v = {1,3,2};
    }

    int cnt = 2;
    int now = 4;
    while (now <= n && cnt <= q) {
        int bg = 0, num = now;
        while (cnt <= q) {
            
            while (num < 3 && bg - 1 >= 0) {
                num++;
                bg--;
            }

            while (num < 3) {
                num++;
            }

            int b1 = (num + 2) / 3; // block 1のサイズ
            int b2 = (num - b1 + 1) / 2; // block 2のサイズ
            int b3 = num - b1 - b2; // block 3のサイズ
            int p1 = bg + b1 - 1; // ポイント1のpos
            int p2 = p1 + b2; // ポイント2のpos

            // query
            cout << v[p1] << " " << v[p2] << " " << now << endl;
#ifdef LOCAL
            cerr << "Me: " << v[p1] << " " << v[p2] << " " << now << endl;
#endif
            cnt++;
            // mid
            int mid;
            cin >> mid;
#ifdef LOCAL
    cerr << "J: " << mid << endl;
#endif
            if (mid == v[p1]) { // 左ブロックにある
                num = b1;
            } else if (mid == now) { // 中央ブロックにある
                num = b2;
                bg = p1 + 1;
            } else { // 右ブロックにある
                num = b3;
                bg = p2 + 1;
            }
#ifdef LOCAL
    cerr << "bg: " << bg << ", num: " << num << endl;
#endif
            if (num == 1) break;
        }

        // 数字を入れる
#ifdef LOCAL
    cerr << "Me: bg=" << bg << endl;
#endif
        V<int> new_v(now);
        rep(i,0,bg) {
            new_v[i] = v[i];
        }
        new_v[bg] = now;
        rep(i,bg+1,now) {
            new_v[i] = v[i-1];
        }

        v = new_v;
#ifdef LOCAL
    cerr << "new_v: " << endl;
    rep(i,0,now) {
        cerr << v[i] << " ";
    }
    cerr << endl;
#endif
        now++;
    }

    // give result
    if (now > n) {
        rep(i,0,n) {
            cout << v[i];
            if (i != n - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        int judge;
        cin >> judge;
#ifdef LOCAL
    cerr << "Result: " << judge << endl;
#endif
        if (judge == 1) ret = 1;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t,n,q;
    cin >> t >> n >> q;
#ifdef LOCAL
    cerr << t << " " << n << " " << q << endl;
#endif
    q /= t;
    while (t--) {
        if (!solve(n,q)) break;
    }
    
    return 0;
}