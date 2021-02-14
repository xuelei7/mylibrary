// Problem B: Lagrange's Four-Square Theorem
// The fact that any positive integer has a representation as the sum of at most four positive squares (i.e. squares of positive integers) is known as Lagrange’s Four-Square Theorem. The first published proof of the theorem was given by Joseph-Louis Lagrange in 1770. Your mission however is not to explain the original proof nor to discover a new proof but to show that the theorem holds for some specific numbers by counting how many such possible representations there are.

// For a given positive integer n, you should report the number of all representations of n as the sum of at most four positive squares. The order of addition does not matter, e.g. you should consider 42 + 32 and 32 + 42 are the same representation.

// For example, let’s check the case of 25. This integer has just three representations 12 +22 +22 +42 , 32 + 42 , and 52 . Thus you should report 3 in this case. Be careful not to count 42 + 32 and 32 + 42 separately.

// Input
// The input is composed of at most 255 lines, each containing a single positive integer less than 215 , followed by a line containing a single zero. The last line is not a part of the input data.

// Output
// The output should be composed of lines, each containing a single integer. No other characters should appear in the output.

// The output integer corresponding to the input integer n is the number of all representations of n as the sum of at most four positive squares.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int dp[1<<16][5];

int main() {
    dp[0][0] = 1;
    for (int j = 1; j * j <= (1<<15); j++) {
        for (int i = 0; i + j * j <= (1<<15); i++) {
            for (int k = 0; k < 4; k++) {
                dp[i+j*j][k+1] += dp[i][k];
            }
        }
    }
    while (cin >> n) {
        if (n == 0) break;
        cout << dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] << endl;
    }
}