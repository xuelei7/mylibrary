// Problem E: Colored Octahedra
// A young boy John is playing with eight triangular panels. These panels are all regular triangles of the same size, each painted in a single color; John is forming various octahedra with them.

// While he enjoys his playing, his father is wondering how many octahedra can be made of these panels since he is a pseudo-mathematician. Your task is to help his father: write a program that reports the number of possible octahedra for given panels. Here, a pair of octahedra should be considered identical when they have the same combination of the colors allowing rotation.

// Input
// The input consists of multiple datasets. Each dataset has the following format:

// Color1 Color2 ... Color8

// Each Colori (1 ≤ i ≤ 8) is a string of up to 20 lowercase alphabets and represents the color of the i-th triangular panel.

// The input ends with EOF.

// Output
// For each dataset, output the number of different octahedra that can be made of given panels.

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

int a[3][8] = {
    {0,1,2,3,7,6,5,4},
    
    {0,7,6,1,3,4,5,2},

    {1,6,5,2,0,7,4,3},
};

auto solve (V<string>& Vec) -> int {
    sort(all(Vec));
    set<V<string>> st;
    int ans = 0;
    do {
        bool unique = 0;
        set<V<string>> newst;
        rep(i,0,3) {
            V<string> tmp(8);
            rep(j,0,4) {
                rep(k,0,8) {
                    tmp[k] = Vec[a[i][(k+j)%4+k/4*4]];
                }
                if (!st.count(tmp)) unique = 1;
                st.insert(tmp);
                reverse(all(tmp));
                if (!st.count(tmp)) unique = 1;
                st.insert(tmp);
            }            
        }
        ans += unique;
#ifdef LOCAL
if (unique) {
    rep(i,0,8) {
        cerr << Vec[i] << " ";
    }
    cerr << endl;
}
#endif
    } while (next_permutation(all(Vec)));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    V<string> v(8);
    string s;
    while (getline(cin,s)) {
        stringstream ss(s);
        rep(i,0,8) ss >> v[i];
        auto ans = solve(v);
        cout << ans << endl;
    }
    
    return 0;
}