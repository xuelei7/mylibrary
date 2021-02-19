// Help the Princess!
// The people of a certain kingdom make a revolution against the bad government of the princess. The revolutionary army invaded the royal palace in which the princess lives. The soldiers of the army are exploring the palace to catch the princess. Your job is writing a program to decide that the princess can escape from the royal palace or not.

// For simplicity, the ground of the palace is a rectangle divided into a grid. There are two kinds of cells in the grid: one is a cell that soldiers and the princess can enter, the other is a cell that soldiers or the princess cannot enter. We call the former an empty cell, the latter a wall. The princess and soldiers are in different empty cells at the beginning. There is only one escape hatch in the grid. If the princess arrives the hatch, then the princess can escape from the palace. There are more than or equal to zero soldiers in the palace.

// The princess and all soldiers take an action at the same time in each unit time. In other words, the princess and soldiers must decide their action without knowing a next action of the other people. In each unit time, the princess and soldiers can move to a horizontally or vertically adjacent cell, or stay at the current cell. Furthermore the princess and soldiers cannot move out of the ground of the palace. If the princess and one or more soldiers exist in the same cell after their move, then the princess will be caught. It is guaranteed that the princess can reach the escape hatch via only empty cells if all soldiers are removed from the palace.

// If there is a route for the princess such that soldiers cannot catch the princess even if soldiers make any moves, then the princess can escape the soldiers. Note that if the princess and a soldier arrive the escape hatch at the same time, the princess will be caught. Can the princess escape from the palace?

// Input
// Each dataset is formatted as follows.

// H W
// map1
// map2
// ...
// mapH
// The first line of a dataset contains two positive integers H and W delimited by a space, where H is the height of the grid and W is the width of the grid (2≤H,W≤200).

// The i-th line of the subsequent H lines gives a string mapi, which represents situation in the ground of palace.

// mapi is a string of length W, and the j-th character of mapi represents the state of the cell of the i-th row and the j-th column.

// '@', '$', '%', '.', and '#' represent the princess, a soldier, the escape hatch, an empty cell, and a wall, respectively. It is guaranteed that there exists only one '@', only one '%', and more than or equal to zero '$' in the grid.

// Output
// Output a line containing a word "Yes", if the princess can escape from the palace. Otherwise, output "No".

#include <bits/stdc++.h>
using namespace std;

bool soldier[2][210][210];
bool princess[2][210][210];
bool wall[210][210];
char maze[210][210];
int h,w;
int dh[5] = {0,0,1,-1,0};
int dw[5] = {1,-1,0,0,0};
int gh,gw;
int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) cin >> maze[i];
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == '%') {
                gh = i;
                gw = j;
            } else if (maze[i][j] == '#') {
                wall[i][j] = 1;
            } else if (maze[i][j] == '@') {
                princess[0][i][j] = 1;
            } else if (maze[i][j] == '$') {
                soldier[0][i][j] = 1;
            }
        }
    }
    for (int t = 1; t < h * w; t++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < 5; k++) {
                    int th = i + dh[k];
                    int tw = j + dw[k];
                    if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                    if (wall[th][tw]) continue;
                    if (soldier[0][i][j]) soldier[1][th][tw] = 1;
                }
                for (int k = 0; k < 5; k++) {
                    int th = i + dh[k];
                    int tw = j + dw[k];
                    if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                    if (wall[th][tw]) continue;
                    if (princess[0][i][j]) princess[1][th][tw] = 1;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            memset(princess[0][i],0,sizeof(princess[0][i]));
            memset(soldier[0][i],0,sizeof(soldier[0][i]));
            for (int j = 0; j < w; j++) {
                princess[0][i][j] = (princess[1][i][j] && !soldier[1][i][j]);
                soldier[0][i][j] = soldier[1][i][j];
            }
        }
        cout << "-----" << endl;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (wall[i][j]) cout << '#';
                else if (soldier[0][i][j]) cout << '$';
                else if (princess[0][i][j]) cout << '@';
                else cout << '.';
            }
            cout << endl;
        }
        if (soldier[0][gh][gw] || princess[0][gh][gw]) break;
    }
    cout << (princess[0][gh][gw]?"Yes":"No") << endl;
    return 0;
}