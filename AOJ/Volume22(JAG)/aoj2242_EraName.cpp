// Problem A: Era Name
// As many of you know, we have two major calendar systems used in Japan today. One of them is Gregorian calendar which is widely used across the world. It is also known as “Western calendar” in Japan.

// The other calendar system is era-based calendar, or so-called “Japanese calendar.” This system comes from ancient Chinese systems. Recently in Japan it has been a common way to associate dates with the Emperors. In the era-based system, we represent a year with an era name given at the time a new Emperor assumes the throne. If the era name is “A”, the first regnal year will be “A 1”, the second year will be “A 2”, and so forth.

// Since we have two different calendar systems, it is often needed to convert the date in one calendar system to the other. In this problem, you are asked to write a program that converts western year to era-based year, given a database that contains association between several western years and era-based years.

// For the simplicity, you can assume the following:

// A new era always begins on January 1st of the corresponding Gregorian year.
// The first year of an era is described as 1.
// There is no year in which more than one era switch takes place.
// Please note that, however, the database you will see may be incomplete. In other words, some era that existed in the history may be missing from your data. So you will also have to detect the cases where you cannot determine exactly which era the given year belongs to.

// Input
// The input contains multiple test cases. Each test case has the following format:

// N Q
// EraName1 EraBasedYear1 WesternYear1
// .
// .
// .
// EraNameN EraBasedYearN WesternYearN
// Query1 .
// .
// .
// QueryQ

// The first line of the input contains two positive integers N and Q (1 ≤ N ≤ 1000, 1 ≤ Q ≤ 1000). N is the number of database entries, and Q is the number of queries.

// Each of the following N lines has three components: era name, era-based year number and the corresponding western year (1 ≤ EraBasedYeari ≤ WesternYeari ≤ 109 ). Each of era names consist of at most 16 Roman alphabet characters. Then the last Q lines of the input specifies queries (1 ≤ Queryi ≤ 109 ), each of which is a western year to compute era-based representation.

// The end of input is indicated by a line containing two zeros. This line is not part of any dataset and hence should not be processed.

// You can assume that all the western year in the input is positive integers, and that there is no two entries that share the same era name.

// Output
// For each query, output in a line the era name and the era-based year number corresponding to the western year given, separated with a single whitespace. In case you cannot determine the era, output “Unknown” without quotes.

#include <bits/stdc++.h>
using namespace std;
int n,q;
struct S {
    string name;
    int from, to;
    S(string name="", int from=0, int to=0):name(name),from(from),to(to) {}
};
void solve() {
    S s[1010];
    for (int i = 0; i < n; i++) {
        int base, west;
        cin >> s[i].name >> base >> west;
        s[i].from = west - base + 1;
        s[i].to = west;
    }
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        bool ok = 0;
        for (int j = 0; j < n; j++) {
            if (y >= s[j].from && y <= s[j].to) {
                cout << s[j].name << " " << y - s[j].from + 1 << endl;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << "Unknown" << endl;
        }
    }
}

int main() {
    while (cin >> n >> q) {
        if (n == 0 && q == 0) break;
        solve();
    }
    
}