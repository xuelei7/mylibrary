// Problem G: Surface Area of Cubes
// Taro likes a single player game "Surface Area of Cubes".

// In this game, he initially has an $A \times B \times C$ rectangular solid formed by $A \times B \times C$ unit cubes (which are all 1 by 1 by 1 cubes). The center of each unit cube is placed at 3-dimentional coordinates $(x, y, z)$ where $x$, $y$, $z$ are all integers ($0 \leq x \leq A-1, 0 \leq y \leq B -1, 0 \leq z \leq C - 1$). Then, $N$ distinct unit cubes are removed from the rectangular solid by the game master. After the $N$ cubes are removed, he must precisely tell the total surface area of this object in order to win the game.

// Note that the removing operation does not change the positions of the cubes which are not removed. Also, not only the cubes on the surface of the rectangular solid but also the cubes at the inside can be removed. Moreover, the object can be divided into multiple parts by the removal of the cubes. Notice that a player of this game also has to count up the surface areas which are not accessible from the outside.

// Taro knows how many and which cubes were removed but this game is very difficult for him, so he wants to win this game by cheating! You are Taro's friend, and your job is to make a program to calculate the total surface area of the object on behalf of Taro when you are given the size of the rectangular solid and the coordinates of the removed cubes.

// Input
// The input is formatted as follows.

// The first line of a test case contains four integers $A$, $B$, $C$, and $N$ ($1 \leq A, B, C \leq 10^8, 0 \leq N \leq $ min{$1,000, A \times B \times C - 1$}).

// Each of the next $N$ lines contains non-negative integers $x$, $y$, and $z$ which represent the coordinate of a removed cube. You may assume that these coordinates are distinct.

// Output
// Output the total surface area of the object from which the $N$ cubes were removed.

