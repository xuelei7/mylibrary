// Problem C: Dial Lock
// A dial lock is a kind of lock which has some dials with printed numbers. It has a special sequence of numbers, namely an unlocking sequence, to be opened.

// You are working at a manufacturer of dial locks. Your job is to verify that every manufactured lock is unlocked by its unlocking sequence. In other words, you have to rotate many dials of many many locks.

// It’s a very hard and boring task. You want to reduce time to open the locks. It’s a good idea to rotate multiple dials at one time. It is, however, a difficult problem to find steps to open a given lock with the fewest rotations. So you decided to write a program to find such steps for given initial and unlocking sequences.

// Your company’s dial locks are composed of vertically stacked k (1 ≤ k ≤ 10) cylindrical dials. Every dial has 10 numbers, from 0 to 9, along the side of the cylindrical shape from the left to the right in sequence. The neighbor on the right of 9 is 0.

// A dial points one number at a certain position. If you rotate a dial to the left by i digits, the dial newly points the i-th right number. In contrast, if you rotate a dial to the right by i digits, it points the i-th left number. For example, if you rotate a dial pointing 8 to the left by 3 digits, the dial newly points 1.

// You can rotate more than one adjacent dial at one time. For example, consider a lock with 5 dials. You can rotate just the 2nd dial. You can rotate the 3rd, 4th and 5th dials at the same time. But you cannot rotate the 1st and 3rd dials at one time without rotating the 2nd dial. When you rotate multiple dials, you have to rotate them to the same direction by the same digits.

// Your program is to calculate the fewest number of rotations to unlock, for given initial and unlocking sequences. Rotating one or more adjacent dials to the same direction by the same digits is counted as one rotation.

// Input
// The input consists of multiple datasets. Each datset consists of two lines. The first line contains an integer k. The second lines contain two strings, separated by a space, which indicate the initial and unlocking sequences.

// The last dataset is followed by a line containing one zero. This line is not a part of any dataset and should not be processed.

// Output
// For each dataset, print the minimum number of rotations in one line.

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

int solve(int n, string a, string b) {
    queue<pair<string,int>> q;
    q.push({a,0});
    set<string> st;
    int ans = 1e9;
    while (!q.empty()) {
        auto tp = q.front(); q.pop();
        string s = tp.first;
        if (s == b) {
            ans = min(ans, tp.second);
            continue;
        }

        int i = 0;
        while (s[i] == b[i]) i++;
        int dif = (b[i] - s[i] + 10) % 10;
        for (;i<n;i++) {
            s[i] = (s[i] - '0' + dif) % 10 + '0';
            if (!st.count(s)) {
                st.insert(s);
                q.push({s, tp.second + 1});
#ifdef LOCAL
    cerr << i << " " << s << " " << tp.second + 1 << endl;
#endif
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        string a,b;
        cin >> a >> b;
        auto ans = solve(n,a,b);
        cout << ans << endl;
    }
    

    return 0;
}