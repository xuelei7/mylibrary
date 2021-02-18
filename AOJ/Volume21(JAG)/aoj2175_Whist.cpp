// Problem A: Whist
// Whist is a game played by four players with a standard deck of playing cards. The players seat around a table, namely, in north, east, south, and west. This game is played in a team-play basis: the players seating opposite to each other become a team. In other words, they make two teams we could call the north-south team and the east-west team.

// Remember that the standard deck consists of 52 cards each of which has a rank and a suit. The rank indicates the strength of the card and is one of the following: 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king, and ace (from the lowest to the highest). The suit refers to the type of symbols printed on the card, namely, spades, hearts, diamonds, and clubs. The deck contains exactly one card for every possible pair of a rank and a suit, thus 52 cards.

// One of the four players (called a dealer) shuffles the deck and deals out all the cards face down, one by one, clockwise from the player left to him or her. Each player should have thirteen cards. Then the last dealt card, which belongs to the dealer, is turned face up. The suit of this card is called trumps and has a special meaning as mentioned below.

// A deal of this game consists of thirteen tricks. The objective for each team is winning more tricks than another team. The player left to the dealer leads the first trick by playing one of the cards in his or her hand. Then the other players make their plays in the clockwise order. They have to play a card of the suit led if they have one; they can play any card otherwise. The trick is won by the player with the highest card of the suit led if no one plays a trump, or with the highest trump otherwise. The winner of this trick leads the next trick, and the remaining part of the deal is played similarly. After the thirteen tricks have been played, the team winning more tricks gains a score, one point per trick in excess of six.

// Your task is to write a program that determines the winning team and their score for given plays of a deal.

// Input
// The input is a sequence of datasets. Each dataset corresponds to a single deal and has the following format:

// Trump
// CardN,1 CardN,2 ... CardN,13
// CardE,1 CardE,2 ... CardE,13
// CardS,1 CardS,2 ... CardS,13
// CardW,1 CardW,2 ... CardW,13
// Trump indicates the trump suit. CardN,i, CardE,i, CardS,i, and CardW,i denote the card played in the i-th trick by the north, east, south, and west players respectively. Each card is represented by two characters; the first and second character indicates the rank and the suit respectively.

// The rank is represented by one of the following characters: ‘2’, ‘3’, ‘4’, ‘5’, ‘6’, ‘7’, ‘8’, ‘9’, ‘T’ (10), ‘J’ (jack), ‘Q’ (queen), ‘K’ (king), and ‘A’ (ace). The suit is represented by one of the following characters: ‘S’ (spades), ‘H’ (hearts), ‘D’ (diamonds), and ‘C’ (clubs).

// You should assume the cards have been dealt out by the west player. Thus the first trick is led by the north player. Also, the input does not contain any illegal plays.

// The input is terminated by a line with “#”. This is not part of any dataset and thus should not be processed.

// Output
// For each dataset, print the winner and their score of the deal in a line, with a single space between them as a separator. The winner should be either “NS” (the north-south team) or “EW” (the east-west team). No extra character or whitespace should appear in the output.


#include <bits/stdc++.h>
using namespace std;
string m[4][13];

string ss = "23456789TJQKA";
char trump;

int check(int k, int& host) {
    int num[4], c[4];
    bool trp = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (m[i][k][0] == ss[j]) num[i] = j;
        }
        c[i] = m[i][k][1];
        if (c[i] == trump) trp = 1;
    }
    int mx = -1, winner = -1;
    for (int i = 0; i < 4; i++) {
        if (trp) {
            if (c[i] == trump && num[i] > mx) {
                mx = num[i];
                winner = i;
            }
        } else {
            if (c[i] == c[host] && num[i] > mx) {
                mx = num[i];
                winner = i;
            }
        }
    }
    host = winner;
    return winner % 2;
}

int main() {
    while (cin >> trump) {
        if (trump == '#') break;
        int host = 0;
        int cnt[3] = {};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                cin >> m[i][j];
            }
        }
        for (int i = 0; i < 13; i++) {
            int w = check(i,host);
            cnt[w]++;
        }
        int winner = (cnt[0] > cnt[1]? 0:1);
        cout << (winner == 0?"NS":"EW") << " " << cnt[winner] - 6 << endl;
    }
    return 0;
}