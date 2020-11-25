// What day is today?
// Your task is to write a program which reads a date (from 2004/1/1 to 2004/12/31) and prints the day of the date. Jan. 1, 2004, is Thursday. Note that 2004 is a leap year and we have Feb. 29.

// Input
// The input is a sequence of datasets. The end of the input is indicated by a line containing one zero. Each dataset consists of two integers m and d separated by a single space in a line. These integers respectively represent the month and the day.

// The number of datasets is less than or equal to 50.

// Output
// For each dataset, print the day (please see the following words) in a line.

// to utils

#include <bits/stdc++.h>
using namespace std;

// return the date of year/month/day
// 0: Sunday 1: Monday ...
int Zeller(int year, int month, int day) {
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7;
}

int main() {
    int m,d;
    while (cin >> m >> d) {
        if (m == 0 && d == 0) break;
        int date = Zeller(2004,m,d);
        if (date == 0) cout << "Sunday\n";
        else if (date == 1) cout << "Monday\n";
        else if (date == 2) cout << "Tuesday\n";
        else if (date == 3) cout << "Wednesday\n";
        else if (date == 4) cout << "Thursday\n";
        else if (date == 5) cout << "Friday\n";
        else if (date == 6) cout << "Saturday\n";
    }
    return 0;
}