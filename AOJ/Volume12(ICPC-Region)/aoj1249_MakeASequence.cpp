// Problem B: Make a Sequence
// Your company’s next product will be a new game, which is a three-dimensional variant of the classic game “Tic-Tac-Toe”. Two players place balls in a three-dimensional space (board), and try to make a sequence of a certain length.

// People believe that it is fun to play the game, but they still cannot fix the values of some parameters of the game. For example, what size of the board makes the game most exciting? Parameters currently under discussion are the board size (we call it n in the following) and the length of the sequence (m). In order to determine these parameter values, you are requested to write a computer simulator of the game.

// You can see several snapshots of the game in Figures 1-3. These figures correspond to the three datasets given in the Sample Input.


// Figure 1: A game with n = m = 3

// Here are the precise rules of the game.

// Two players, Black and White, play alternately. Black plays first.
// There are n × n vertical pegs. Each peg can accommodate up to n balls. A peg can be specified by its x- and y-coordinates (1 ≤ x, y ≤ n). A ball on a peg can be specified by its z-coordinate (1 ≤ z ≤ n). At the beginning of a game, there are no balls on any of the pegs.


// Figure 2: A game with n = m = 3 (White made a 3-sequence before Black)

// On his turn, a player chooses one of n × n pegs, and puts a ball of his color onto the peg. The ball follows the law of gravity. That is, the ball stays just above the top-most ball on the same peg or on the floor (if there are no balls on the peg). Speaking differently, a player can choose x- and y-coordinates of the ball, but he cannot choose its z-coordinate.
// The objective of the game is to make an m-sequence. If a player makes an m-sequence or longer of his color, he wins. An m-sequence is a row of m consecutive balls of the same color. For example, black balls in positions (5, 1, 2), (5, 2, 2) and (5, 3, 2) form a 3-sequence. A sequence can be horizontal, vertical, or diagonal. Precisely speaking, there are 13 possible directions to make a sequence, categorized as follows.


// Figure 3: A game with n = 4, m = 3 (Black made two 4-sequences)

// (a) One-dimensional axes. For example, (3, 1, 2), (4, 1, 2) and (5, 1, 2) is a 3-sequence. There are three directions in this category.
// (b) Two-dimensional diagonals. For example, (2, 3, 1), (3, 3, 2) and (4, 3, 3) is a 3-sequence. There are six directions in this category.
// (c) Three-dimensional diagonals. For example, (5, 1, 3), (4, 2, 4) and (3, 3, 5) is a 3- sequence. There are four directions in this category.

// Note that we do not distinguish between opposite directions.

// As the evaluation process of the game, people have been playing the game several times changing the parameter values. You are given the records of these games. It is your job to write a computer program which determines the winner of each recorded game.

// Since it is difficult for a human to find three-dimensional sequences, players often do not notice the end of the game, and continue to play uselessly. In these cases, moves after the end of the game, i.e. after the winner is determined, should be ignored. For example, after a player won making an m-sequence, players may make additional m-sequences. In this case, all m-sequences but the first should be ignored, and the winner of the game is unchanged.

// A game does not necessarily end with the victory of one of the players. If there are no pegs left to put a ball on, the game ends with a draw. Moreover, people may quit a game before making any m-sequence. In such cases also, the game ends with a draw.

// Input
// The input consists of multiple datasets each corresponding to the record of a game. A dataset starts with a line containing three positive integers n, m, and p separated by a space. The relations 3 ≤ m ≤ n ≤ 7 and 1 ≤ p ≤ n3 hold between them. n and m are the parameter values of the game as described above. p is the number of moves in the game.

// The rest of the dataset is p lines each containing two positive integers x and y. Each of these lines describes a move, i.e. the player on turn puts his ball on the peg specified. You can assume that 1 ≤ x ≤ n and 1 ≤ y ≤ n. You can also assume that at most n balls are put on a peg throughout a game.

// The end of the input is indicated by a line with three zeros separated by a space.

// Output
// For each dataset, a line describing the winner and the number of moves until the game ends should be output. The winner is either “Black” or “White”. A single space should be inserted between the winner and the number of moves. No other extra characters are allowed in the output.

// In case of a draw, the output line should be “Draw”.

#include <bits/stdc++.h>
using namespace std;
int n,m,p;
int a[10][10][10];
int cnt[10][10];
int dx[13] = {1,0,0,1,0,1, 1, 1, 0,1, 1, 1, 1};
int dy[13] = {0,1,0,1,1,0, 0,-1, 1,1,-1,-1, 1};
int dz[13] = {0,0,1,0,1,1,-1, 0,-1,1, 1,-1,-1};
int check(int x, int y, int z) {
    for (int i = 0; i < 13; i++) {
        int lk = 1;
        int tx = x, ty = y, tz = z;
        while (1) {
            tx += dx[i];
            ty += dy[i];
            tz += dz[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n || tz < 0 || tz >= n) break;
            if (a[tx][ty][tz] == a[x][y][z]) {
                lk++;
            } else break;
        }
        tx = x, ty = y, tz = z;
        while (1) {
            tx -= dx[i];
            ty -= dy[i];
            tz -= dz[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= n || tz < 0 || tz >= n) break;
            if (a[tx][ty][tz] == a[x][y][z]) {
                lk++;
            } else break;
        }
        if (lk >= m) return a[x][y][z];
    }
    return 0;
}
int putpeg(int x, int y, int c) {
    int z = cnt[x][y]++;
    a[x][y][z] = c;
    return z;
}

int px[1010],py[1010];
void solve() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cnt[i][j] = 0;
            for (int k = 0; k < 10; k++) {
                a[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < p; i++) {
        cin >> px[i] >> py[i];
        px[i]--;
        py[i]--;
    }
    bool draw = 1;
    for (int i = 0; i < p; i++) {
        int z = putpeg(px[i],py[i],(i&1)+1);
        int result = check(px[i],py[i],z);
        if (result != 0) {
            cout << (result == 1? "Black":"White") << " " << i+1 << endl;
            draw = 0;
            break;
        }
    }
    if (draw) {
        cout << "Draw" << endl;
    }
}

int main() {
    while (cin >> n >> m >> p) {
        if (n == 0 && m == 0 && p == 0) break;
        solve();
    }
    return 0;
}