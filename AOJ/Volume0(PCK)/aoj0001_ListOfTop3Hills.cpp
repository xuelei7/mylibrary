// List of Top 3 Hills
// There is a data which provides heights (in meter) of mountains. The data is only for ten mountains.

// Write a program which prints heights of the top three mountains in descending order.

// Input
// Height of mountain 1
// Height of mountain 2
// Height of mountain 3
//  .
//  .
// Height of mountain 10
// Constraints
// 0 ≤ height of mountain (integer) ≤ 10,000

// Output
// Height of the 1st mountain
// Height of the 2nd mountain
// Height of the 3rd mountain

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(10);
    for (int i = 0; i < 10; i++) cin >> v[i];
    sort(v.begin(),v.end());
    cout << v[9] << "\n" << v[8] << "\n" << v[7] << "\n";
    return 0;
}