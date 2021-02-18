// Problem H: Sightseeing Tour
// KM city has N sightseeing areas. Currently every pair of area is connected by a bidirectional road.

// However for some reason, Mr. KM, the mayor of this city, decided to make all of these roads one-way . It costs Ci,j dollars to renovate the road between area i and area j to a one-way road from area i to area j. Of course, Mr. KM is economic and wants to minimize the total cost of the renovation.

// On the other hand, because tourism is the most important industry for KM city, there must exists a tour that goes through all the sightseeing areas, visiting each area exactly once. The first and last area of the path need not to be the same. Can you calculate the minimum total cost required for the renovation, given this situation?

// Input
// The first line contains the number of sightseeing area N (1≤N≤100). Next N lines describe the integer matrix C, where the j-th element of the i-th row of the input describes Ci,j (0≤Ci,j≤1,000,000). For each i, you can assume Ci,i is always zero.

// Output
// Output the minimum cost in a line.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m[110][110];
int main() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += min(m[i][j],m[j][i]);
        }
    }
    cout << ans << endl;
}