#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    string s = to_string(n);
    sort(s.begin(),s.end());
    int a = stoi(s);
    reverse(s.begin(),s.end());
    int b = stoi(s);
    return b - a;
}

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) n = f(n);
    cout << n << endl;
    return 0;
}
