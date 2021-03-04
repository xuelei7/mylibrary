// RPG Maker
// You are planning to create a map of an RPG. This map is represented by a grid whose size is H×W. Each cell in this grid is either '@', '*', '#', or '.'. The meanings of the symbols are as follows.

// '@': The start cell. The story should start from this cell.
// '*': A city cell. The story goes through or ends with this cell.
// '#': A road cell.
// '.': An empty cell.
// You have already located the start cell and all city cells under some constraints described in the input section, but no road cells have been located yet. Then, you should decide which cells to set as road cells.

// Here, you want a "journey" exists on this map. Because you want to remove the branch of the story, the journey has to be unforked. More formally, the journey is a sequence of cells and must satisfy the following conditions:

// The journey must contain as many city cells as possible.
// The journey must consist of distinct non-empty cells in this map.
// The journey must begin with the start cell.
// The journey must end with one of the city cells.
// The journey must contain all road cells. That is, road cells not included in the journey must not exist.
// The journey must be unforked. In more detail, all road cells and city cells except for a cell at the end of the journey must share edges with the other two cells both of which are also contained in the journey. Then, each of the start cell and a cell at the end of the journey must share an edge with another cell contained in the journey.
// You do not have to consider the order of the cities to visit during the journey.
// Initially, the map contains no road cells. You can change any empty cells to road cells to make a journey satisfying the conditions above. Your task is to print a map which maximizes the number of cities in the journey.

// Input
// The input consists of a single test case of the following form.

// H W
// S1
// S2
// :
// SH
// The first line consists of two integers N and W. H and W are guaranteed to satisfy H=4n−1 and W=4m−1 for some positive integers n and m (1≤n,m≤10). The following H lines represent a map without road cells. The (i+1)-th line consists of a string Si of length W. The j-th character of Si is either '*', '@' or '.' if both i and j are odd, otherwise '.'. The number of occurrences of '@' in the grid is exactly one. It is guaranteed that there are one or more city cells on the grid.

// Output
// Print a map indicating a journey. If several maps satisfy the condition, you can print any of them.

