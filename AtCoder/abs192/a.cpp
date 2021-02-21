#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 1;
    for (; (i + n) % 100 != 0; i++) ;
    cout << i << endl;
    return 0;
}
