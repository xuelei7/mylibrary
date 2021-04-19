#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool ok = 1;
    for (int i = 0; i < s.size(); i++) {
        if (i&1) {
            if (s[i] < 'A' || s[i] > 'Z') ok = 0;
        } else {
            if (s[i] < 'a' || s[i] > 'z') ok = 0;
        }
    }
    cout << (ok?"Yes":"No") << endl;
    return 0;
}
