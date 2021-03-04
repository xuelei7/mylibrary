// Problem Statement
// You are given a connected undirected graph which has even numbers of nodes. A connected graph is a graph in which all nodes are connected directly or indirectly by edges.

// Your task is to find a spanning tree whose median value of edges' costs is minimum. A spanning tree of a graph means that a tree which contains all nodes of the graph.

// Input
// The input consists of multiple datasets.

// The format of each dataset is as follows.

// n m
// s1 t1 c1
// ...
// sm tm cm
// The first line contains an even number n (2≤n≤1,000) and an integer m (n−1≤m≤10,000). n is the nubmer of nodes and m is the number of edges in the graph.

// Then m lines follow, each of which contains si (1≤si≤n), ti (1≤si≤n,ti≠si) and ci (1≤ci≤1,000). This means there is an edge between the nodes si and ti and its cost is ci. There is no more than one edge which connects si and ti.

// The input terminates when n=0 and m=0. Your program must not output anything for this case.

// Output
// Print the median value in a line for each dataset.

