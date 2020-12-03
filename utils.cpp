// from
// aoj0002
// return the digit number
int digitnum(int k) {
    if (k == 0) return 1;
    int cnt = 0;
    while (k > 0) {
        k /= 10;
        cnt++;
    }
    return cnt;
}

// from
// aoj0027
// return the date of year/month/day
// 0: Sunday 1: Monday ...
int Zeller(int year, int month, int day) {
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7;
}

// from
// aoj0038
string poker_hand(vector<int> v) {
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) return "four card";
    if (v[1] == v[2] && v[2] == v[3] && v[3] == v[4]) return "four card";
    if (v[0] == v[1] && v[2] == v[3] && v[3] == v[4]) return "full house";
    if (v[0] == v[1] && v[1] == v[2] && v[3] == v[4]) return "full house";
    if (v[0] == v[1] - 1 && v[1] == v[2] - 1 && v[2] == v[3] - 1 && v[3] == v[4] - 1) return "straight";
    if (v[0] == 1 && v[1] == 10 && v[2] == 11 && v[3] == 12 && v[4] == 13) return "straight";
    if (v[0] == v[1] && v[1] == v[2]) return "three card";
    if (v[1] == v[2] && v[2] == v[3]) return "three card";
    if (v[2] == v[3] && v[3] == v[4]) return "three card";
    if (v[0] == v[1] && (v[2] == v[3] || v[3] == v[4])) return "two pair";
    if (v[1] == v[2] && v[3] == v[4]) return "two pair";
    if (v[0] == v[1] || v[1] == v[2] || v[2] == v[3] || v[3] == v[4]) return "one pair";
    return "null";
}

// from
// aoj0039
int roman_figure(string s) {
    int ans = 0, biggest = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        int now ;
        if (s[i] == 'I') now = 1;
        else if (s[i] == 'V') now = 5;
        else if (s[i] == 'X') now = 10;
        else if (s[i] == 'L') now = 50;
        else if (s[i] == 'C') now = 100;
        else if (s[i] == 'D') now = 500;
        else if (s[i] == 'M') now = 1000;
        if (now >= biggest) {
            biggest = now;
            ans += now;
        } else {
            ans -= now;
        }
    }
    return ans;
}