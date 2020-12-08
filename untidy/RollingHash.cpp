#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000, MS = 2;
const long long mod[] = {999999937LL, 1000000007LL}, base = 9973;
struct rolling_hash {
    int n;
    vector<long long> hs[MS], pw[MS];
    rolling_hash(){}
    rolling_hash(const string &s) {
        n = s.size();
        for (int i = 0; i < MS; i++) {
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for (int j = 0; j < n; j++) {
                pw[i][j+1] = pw[i][j]*base%mod[i];
                hs[i][j+1] = (hs[i][j]*base+s[j])%mod[i];
            }
        }
    }

    long long hash(int l, int r, int i) { return ((hs[i][r]-hs[i][l]*pw[i][r-l])%mod[i]+mod[i])%mod[i]; }

    bool match(int l1, int r1, int l2, int r2) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l1,r1,i)==hash(l2,r2,i);
        return ret;
    }

    bool match(int l, int r, long long h[]) {
        bool ret = 1;
        for (int i = 0; i < MS; i++) ret &= hash(l,r,i)==h[i];
        return ret;
    }
};

int main() {
    string s = "XueleiYu";
    string t = "Yu";
    rolling_hash rh(s+t);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        if (rh.match(s.size(), s.size()+t.size(), i, i+t.size())) {
            cout << "ok " << i << endl;
        }
    }
    return 0;
}