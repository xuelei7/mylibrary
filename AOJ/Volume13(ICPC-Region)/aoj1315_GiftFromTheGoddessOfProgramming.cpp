// Problem A: Gift from the Goddess of Programming
// The goddess of programming is reviewing a thick logbook, which is a yearly record of visitors to her holy altar of programming. The logbook also records her visits at the altar.

// The altar attracts programmers from all over the world because one visitor is chosen every year and endowed with a gift of miracle programming power by the goddess. The endowed programmer is chosen from those programmers who spent the longest time at the altar during the goddess's presence. There have been enthusiastic visitors who spent very long time at the altar but failed to receive the gift because the goddess was absent during their visits.

// Now, your mission is to write a program that finds how long the programmer to be endowed stayed at the altar during the goddess's presence.

// Input
// The input is a sequence of datasets. The number of datasets is less than 100. Each dataset is formatted as follows.

// n
// M1/D1 h1:m1e1 p1
// M2/D2 h2:m2e2 p2
// .
// .
// .
// Mn/Dn hn:mnen pn
// The first line of a dataset contains a positive even integer, n ≤ 1000, which denotes the number of lines of the logbook. This line is followed by n lines of space-separated data, where Mi/Di identifies the month and the day of the visit, hi:mi represents the time of either the entrance to or exit from the altar, ei is either I for entrance, or O for exit, and pi identifies the visitor.

// All the lines in the logbook are formatted in a fixed-column format. Both the month and the day in the month are represented by two digits. Therefore April 1 is represented by 04/01 and not by 4/1. The time is described in the 24-hour system, taking two digits for the hour, followed by a colon and two digits for minutes, 09:13 for instance and not like 9:13. A programmer is identified by an ID, a unique number using three digits. The same format is used to indicate entrance and exit of the goddess, whose ID is 000.

// All the lines in the logbook are sorted in ascending order with respect to date and time. Because the altar is closed at midnight, the altar is emptied at 00:00. You may assume that each time in the input is between 00:01 and 23:59, inclusive.

// A programmer may leave the altar just after entering it. In this case, the entrance and exit time are the same and the length of such a visit is considered 0 minute. You may assume for such entrance and exit records, the line that corresponds to the entrance appears earlier in the input than the line that corresponds to the exit. You may assume that at least one programmer appears in the logbook.

// The end of the input is indicated by a line containing a single zero.

// Output
// For each dataset, output the total sum of the blessed time of the endowed programmer. The blessed time of a programmer is the length of his/her stay at the altar during the presence of the goddess. The endowed programmer is the one whose total blessed time is the longest among all the programmers. The output should be represented in minutes. Note that the goddess of programming is not a programmer.

#include <bits/stdc++.h>
using namespace std;
string d[1010],t[1010],e[1010],id[1010];
int pre[1010], cnt[1010];
int n;
bool god = 0;
int time(string t) {
    int h = (t[0]-'0')*10 + (t[1]-'0');
    int m = (t[3]-'0')*10 + (t[4]-'0');
    return h*60+m;
}
void in(int i) {
    string str = id[i];
    int num = stoi(str);
    pre[num] = time(t[i]);
}
void out(int i) {
    string str = id[i];
    int num = stoi(str);
    int tt = time(t[i]);

    if (num != 0 && pre[0] != 0) {
        cnt[num] += tt - max(pre[0],pre[num]);
    }
    if (num == 0) {
        for (int k = 1; k <= 999; k++) {
            if (pre[k] != 0) {
                cnt[k] += tt - max(pre[k], pre[0]);
            }
        }
    }

    pre[num] = 0;
}
int main() {
    while (cin >> n) {
        if (n == 0) break;
        memset(cnt,0,sizeof(cnt));
        for (int i = 0; i < n; i++) cin >> d[i] >> t[i] >> e[i] >> id[i];
        int p;
        for (int i = 0; i < n; i++) {
            if (e[i] == "I") {
                in(i);
            } else {
                out(i);
            }
        }
        int mx = 0;
        for (int i = 1; i <= 999; i++) mx = max(mx, cnt[i]);
        cout << mx << endl;
    }
    return 0;
}