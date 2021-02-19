
// ログアウト
 
// 登録・設定
// 日本語   英語
// My Statusはじめての方へ    HOME- Volume13-1347
// Tag Discussion Solution Statistics Submit
 
// Shopping
// 時間制限 : 1 sec, メモリ制限 : 262144 KB
// English
// Problem C: Shopping
// Your friend will enjoy shopping. She will walk through a mall along a straight street, where N individual shops (numbered from 1 to N) are aligned at regular intervals. Each shop has one door and is located at the one side of the street. The distances between the doors of the adjacent shops are the same length, i.e. a unit length. Starting shopping at the entrance of the mall, she visits shops in order to purchase goods. She has to go to the exit of the mall after shopping.

// She requires some restrictions on visiting order of shops. Each of the restrictions indicates that she shall visit a shop before visiting another shop. For example, when she wants to buy a nice dress before choosing heels, she shall visit a boutique before visiting a shoe store. When the boutique is farther than the shoe store, she must pass the shoe store before visiting the boutique, and go back to the shoe store after visiting the boutique.

// If only the order of the visiting shops satisfies all the restrictions, she can visit other shops in any order she likes.

// Write a program to determine the minimum required walking length for her to move from the entrance to the exit.

// Assume that the position of the door of the shop numbered k is k units far from the entrance, where the position of the exit is N+1 units far from the entrance.

// Input
// The input consists of a single test case.

// N m
// c1 d1
// .
// .
// .
// cm dm

// The first line contains two integers N and m, where N (1≤N≤1000) is the number of shops, and m (0≤m≤500) is the number of restrictions. Each of the next m lines contains two integers ci and di (1≤ci<di≤N) indicating the i-th restriction on the visiting order, where she must visit the shop numbered ci after she visits the shop numbered di (i=1,...,m).

// There are no pair of j and k that satisfy cj=ck and dj=dk.

// Output
// Output the minimum required walking length for her to move from the entrance to the exit. You should omit the length of her walk in the insides of shops.

