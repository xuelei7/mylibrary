// Factorial
// Write a program which reads an integer n and prints the factorial of n. You can assume that n ≤ 20.

// Input
// An integer n (1 ≤ n ≤ 20) in a line.

// Output
// Print the factorial of n in a line.

// Sample Input
// 5
// Output for the Sample Input
// 120

// to number

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans = 1;
    for (long long i = 2LL; i <= n; i++) ans *= i;
    cout << ans << endl;
    return 0;
}