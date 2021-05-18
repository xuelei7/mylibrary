#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    a = a % 10;
    int ans[10][4] = {
        {0,0,0,0},
        {1,1,1,1},
        {6,2,4,8},
        {1,3,9,7},
        {6,4,6,4},
        {5,5,5,5},
        {6,6,6,6},
        {1,7,9,3},
        {6,8,4,2},
        {1,9,1,9},
    };
    b %= 4;
    cout << ans[a][ans[b][c%4]%4] << endl;
    return 0;
}