// National Budget
// A country has a budget of more than 81 trillion yen. We want to process such data, but conventional integer type which uses signed 32 bit can represent up to 2,147,483,647.

// Your task is to write a program which reads two integers (more than or equal to zero), and prints a sum of these integers.

// If given integers or the sum have more than 80 digits, print "overflow".

// Input
// Input consists of several datasets. In the first line, the number of datasets N (1 ≤ N ≤ 50) is given. Each dataset consists of 2 lines:

// The first integer
// The second integer
// The integer has at most 100 digits.

// Output
// For each dataset, print the sum of given integers in a line.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b;
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (a.size() < b.size()) swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        vector<int> v;
        int now = 0;
        for (int i = 0; i < a.size() + 1; i++) {
            if (i < a.size()) now += a[i] - '0';
            if (i < b.size()) now += b[i] - '0';
            if (i == a.size() && now == 0) continue;
            v.push_back(now % 10);
            now /= 10;
        }
        reverse(v.begin(),v.end());
        if (v.size() > 80) {
            cout << "overflow" << endl;
            continue;
        }
        for (auto i:v) cout << i;
        cout << endl;
    }
    return 0;
}