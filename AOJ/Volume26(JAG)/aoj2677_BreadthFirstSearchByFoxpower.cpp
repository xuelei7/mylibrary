// A - Breadth-First Search by Foxpower
// Problem Statement
// Fox Ciel went to JAG Kingdom by bicycle, but she forgot a place where she parked her bicycle. So she needs to search it from a bicycle-parking area before returning home.

// The parking area is formed as a unweighted rooted tree $T$ with $n$ vertices, numbered $1$ through $n$. Each vertex has a space for parking one or more bicycles. Ciel thought that she parked her bicycle near the vertex $1$, so she decided to search it from there by the breadth-first search. That is, she searches it at the vertices in the increasing order of their distances from the vertex $1$. If multiple vertices have the same distance, she gives priority to the vertices in the order of searching at their parents. If multiple vertices have the same parent, she searches at the vertex with minimum number at first.

// Unlike a computer, she can't go to a next vertex by random access. Thus, if she goes to the vertex $j$ after the vertex $i$, she needs to walk the distance between the vertices $i$ and $j$. BFS by fox power perhaps takes a long time, so she asks you to calculate the total moving distance in the worst case starting from the vertex $1$.

// Input
// The input is formatted as follows.

// $n$
// $p_2$ $p_3$ $p_4$ $\cdots$ $p_n$
// The first line contains an integer $n$ ($1 \le n \le 10^5$), which is the number of vertices on the unweighted rooted tree $T$. The second line contains $n-1$ integers $p_i$ ($1 \le p_i < i$), which are the parent of the vertex $i$. The vertex $1$ is a root node, so $p_1$ does not exist.

// Output
// Print the total moving distance in the worst case in one line.

