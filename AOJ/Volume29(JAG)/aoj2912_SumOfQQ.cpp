// Problem I. Sum of QQ
// You received a card with an integer S and a multiplication table of infinite size. All the elements in the table are integers, and an integer at the i-th row from the top and the j-th column from the left is Ai,j=i×j (i,j≥1). The table has infinite size, i.e., the number of the rows and the number of the columns are infinite.

// You love rectangular regions of the table in which the sum of numbers is S. Your task is to count the number of integer tuples (a,b,c,d) that satisfies 1≤a≤b,1≤c≤d and ∑bi=a∑dj=cAi,j=S.

// Input
// The input consists of a single test case of the following form.

// S  
// The first line consists of one integer S (1≤S≤105), representing the summation of rectangular regions you have to find.

// Output
// Print the number of rectangular regions whose summation is S in one line.


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll s;
    cin >> s;
    s *= 4;
    int ans = 0;
    vector<ll> v;
    for (int i = 1; i <= s; i++) {
        if (s % i == 0) v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            ll d1 = v[i], d2 = v[j];
            if (s % (d1 * d2) != 0) continue;
            ll lft = s / d1 / d2;
            for (ll d3 = d1 + 1; d3 <= lft; d3++) {
                if (lft % d3 != 0) continue;
                if ((d3 - d1 + 1) % 2 != 0) continue;
                ll d4 = lft / d3;
                if (d4 < d2 + 1) continue;
                if ((d4 - d2 + 1) % 2 != 0) continue;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}