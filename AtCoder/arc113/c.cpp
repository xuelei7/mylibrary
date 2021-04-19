#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    int cnt[26] = {};
    for (int i = n - 3; i >= 0; i--) {
        if (s[i] == s[i+1] && s[i] != s[i+2]) {
            ans += n - i - 2;
            ans -= cnt[s[i] - 'a'];
            cout << s[i] << " " << cnt[s[i]-'a'] << endl;
            for (int j = 0; j < 26; j++) {
                if (j != s[i] - 'a') cnt[j] = 0;
                else cnt[j] = n - i - 2;
            }
        } else {
            cnt[s[i+2] - 'a']++;
        }
    }
    cout << ans << endl;
    return 0;
}