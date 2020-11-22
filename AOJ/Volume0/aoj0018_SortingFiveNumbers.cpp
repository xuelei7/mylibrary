// Sorting Five Numbers
// Write a program which reads five numbers and sorts them in descending order.

// Input
// Input consists of five numbers a, b, c, d and e (-100000 ≤ a, b, c, d,e ≤ 100000). The five numbers are separeted by a space.

// Output
// Print the ordered numbers in a line. Adjacent numbers should be separated by a space.

// Sample Input
// 3 6 9 7 5
// Output for the Sample Input
// 9 7 6 5 3

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    for (int i = 0; i < 5; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < 5; i++) cout << v[i] << " \n"[i == 4];
    return 0;
}