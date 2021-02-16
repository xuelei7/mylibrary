// Problem A Rearranging a Sequence
// You are given an ordered sequence of integers, (1,2,3,...,n). Then, a number of requests will be given. Each request specifies an integer in the sequence. You need to move the specified integer to the head of the sequence, leaving the order of the rest untouched. Your task is to find the order of the elements in the sequence after following all the requests successively.

// Input
// The input consists of a single test case of the following form.

// n m
// e1
// ...
// em
// The integer n is the length of the sequence (1≤n≤200000). The integer m is the number of requests (1≤m≤100000). The following m lines are the requests, namely e1,...,em, one per line. Each request ei (1≤i≤m) is an integer between 1 and n, inclusive, designating the element to move. Note that, the integers designate the integers themselves to move, not their positions in the sequence.

// Output
// Output the sequence after processing all the requests. Its elements are to be output, one per line, in the order in the sequence.

#include <bits/stdc++.h>
using namespace std;
bool used[200010];
int a[100010];
int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = m - 1; i >= 0; i--) {
        if (!used[a[i]]) {
            cout << a[i] << endl;
            used[a[i]] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << i << endl;
        }
    }
    return 0;
}