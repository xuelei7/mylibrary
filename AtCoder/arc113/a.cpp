#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int main() {
    int k;
    cin >> k;
    int cnt = 0;
    // a,a,a
    for (int i = 1; i * i * i <= k; i++) {
        if (i * i * i <= k) cnt++;
    }
    // a,b,b
    for (int i = 1; i * i <= k; i++) {
        int a = k / i / i;
        if (a >= i) a--;
        cnt += a * 3;
    }
    // a,b,c
    for (int i = 1; i * i * i <= k; i++) {
        for (int j = i + 1; i * j * j <= k; j++) {
            int a = k / i / j;
            if (a <= j) continue;
            a = a - j;
            cnt += a * 6;
        }
    }
    cout << cnt << endl;
    return 0;
}