// Ninja Map
// Intersections of Crossing Path City are aligned to a grid. There are N east-west streets which are numbered from 1 to N, from north to south. There are also N north-south streets which are numbered from 1 to N, from west to east. Every pair of east-west and north-south streets has an intersection; therefore there are N2 intersections which are numbered from 1 to N2.

// Surprisingly, all of the residents in the city are Ninja. To prevent outsiders from knowing their locations, the numbering of intersections is shuffled.

// You know the connections between the intersections and try to deduce their positions from the information. If there are more than one possible set of positions, you can output any of them.

// Input
// The input consists of a single test case formatted as follows.

// N
// a1 b1
// ...
// a2N2−2N  b2N2−2N
// The first line consists of an integer N (2≤N≤100). The following 2N2−2N lines represent connections between intersections. The (i+1)-th line consists of two integers ai and bi (1≤ai,bi≤N2,ai≠bi), which represent that the ai-th and bi-th intersections are adjacent. More precisely, let's denote by (r,c) the intersection of the r-th east-west street and the c-th north-south street. If the intersection number of (r,c) is ai for some r and c, then the intersection number of either (r−1,c), (r+1,c), (r,c−1) or (r,c+1) must be bi. All inputs of adjacencies are different, i.e., (ai,bi) ≠ (aj,bj) and (ai,bi) ≠ (bj,aj) for all 1≤i<j≤2N2−2N. This means that you are given information of all adjacencies on the grid.

// The input is guaranteed to describe a valid map.

// Output
// Print a possible set of positions of the intersections. More precisely, the output consists of N lines each of which has space-separated N integers. The c-th integer of the r-th line should be the intersection number of (r,c).

// If there are more than one possible set of positions, you can output any of them.

