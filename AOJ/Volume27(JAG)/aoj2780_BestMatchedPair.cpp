// Best Matched Pair
// You are working for a worldwide game company as an engineer in Tokyo. This company holds an annual event for all the staff members of the company every summer. This year's event will take place in Tokyo. You will participate in the event on the side of the organizing staff. And you have been assigned to plan a recreation game which all the participants will play at the same time.

// After you had thought out various ideas, you designed the rules of the game as below.

// Each player is given a positive integer before the start of the game.
// Each player attempts to make a pair with another player in this game, and formed pairs compete with each other by comparing the products of two integers.
// Each player can change the partner any number of times before the end of the game, but cannot have two or more partners at the same time.
// At the end of the game, the pair with the largest product wins the game.
// In addition, regarding the given integers, the next condition must be satisfied for making a pair.

// The sequence of digits obtained by considering the product of the two integers of a pair as a string must be increasing and consecutive from left to right. For example, 2, 23, and 56789 meet this condition, but 21, 334, 135 or 89012 do not.
// Setting the rules as above, you noticed that multiple pairs may be the winners who have the same product depending on the situation. However, you can find out what is the largest product of two integers when a set of integers is given.

// Your task is, given a set of distinct integers which will be assigned to the players, to compute the largest possible product of two integers, satisfying the rules of the game mentioned above.

// Input
// The input consists of a single test case formatted as follows.

// N
// a1 a2 ... aN
// The first line contains a positive integer N which indicates the number of the players of the game. N is an integer between 1 and 1,000. The second line has N positive integers that indicate the numbers given to the players. For i=1,2,...,N−1, there is a space between ai and ai+1. ai is between 1 and 10,000 for i=1,2,...,N, and if i≠j, then ai≠aj.

// Output
// Print the largest possible product of the two integers satisfying the conditions for making a pair. If any two players cannot make a pair, print -1.

#include <bits/stdc++.h>
using namespace std;
int n;
int a[1010];
void solve() {
    int mx = -1;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int p = a[i] * a[j];
            string s = to_string(p);
            bool ok = 1;
            for (int k = 0; k < s.size() - 1; k++) {
                if (s[k+1] != s[k]+1) ok = 0;
            }
            if (ok) mx = max(mx, p);
        }
    }
    cout << mx << endl;
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        solve();
    }

}