// Problem A:Infnity Maze
// Dr. Fukuoka has placed a simple robot in a two-dimensional maze. It moves within the maze and never goes out of the maze as there is no exit.

// The maze is made up of H × W grid cells as depicted below. The upper side of the maze faces north. Consequently, the right, lower and left sides face east, south and west respectively. Each cell is either empty or wall and has the coordinates of (i, j) where the north-west corner has (1, 1). The row i goes up toward the south and the column j toward the east.


// The robot moves on empty cells and faces north, east, south or west. It goes forward when there is an empty cell in front, and rotates 90 degrees to the right when it comes in front of a wall cell or on the edge of the maze. It cannot enter the wall cells. It stops right after moving forward by L cells.

// Your mission is, given the initial position and direction of the robot and the number of steps, to write a program to calculate the final position and direction of the robot.

// Input
// The input is a sequence of datasets. Each dataset is formatted as follows.

// H W L
// c1,1c1,2...c1,W
// .
// .
// .
// cH,1cH,2...cH,W
// The first line of a dataset contains three integers H, W and L (1 ≤ H, W ≤ 100, 1 ≤ L ≤ 1018).

// Each of the following H lines contains exactly W characters. In the i-th line, the j-th character ci,j represents a cell at (i, j) of the maze. "." denotes an empty cell. "#" denotes a wall cell. "N", "E", "S", "W" denote a robot on an empty cell facing north, east, south and west respectively; it indicates the initial position and direction of the robot.

// You can assume that there is at least one empty cell adjacent to the initial position of the robot.

// The end of input is indicated by a line with three zeros. This line is not part of any dataset.

// Output
// For each dataset, output in a line the final row, column and direction of the robot, separated by a single space. The direction should be one of the following: "N" (north), "E" (east), "S" (south) and "W" (west).

// No extra spaces or characters are allowed.

