// Problem C: One-Dimensional Cellular Automaton
// There is a one-dimensional cellular automaton consisting of N cells. Cells are numbered from 0 to N − 1.

// Each cell has a state represented as a non-negative integer less than M. The states of cells evolve through discrete time steps. We denote the state of the i-th cell at time t as S(i, t). The state at time t + 1 is defined by the equation

// S(i, t + 1) = (A × S(i − 1, t) + B × S(i, t) + C × S(i + 1, t)) mod M,         (1)

// where A, B and C are non-negative integer constants. For i < 0 or N ≤ i, we define S(i, t) = 0.

// Given an automaton definition and initial states of cells, your mission is to write a program that computes the states of the cells at a specified time T.

// Input
// The input is a sequence of datasets. Each dataset is formatted as follows.

// N M A B C T
// S(0, 0) S(1, 0) ... S(N − 1, 0)
// The first line of a dataset consists of six integers, namely N, M, A, B, C and T. N is the number of cells. M is the modulus in the equation (1). A, B and C are coefficients in the equation (1). Finally, T is the time for which you should compute the states.

// You may assume that 0 < N ≤ 50, 0 < M ≤ 1000, 0 ≤ A, B, C < M and 0 ≤ T ≤ 109.

// The second line consists of N integers, each of which is non-negative and less than M. They represent the states of the cells at time zero.

// A line containing six zeros indicates the end of the input.

// Output
// For each dataset, output a line that contains the states of the cells at time T. The format of the output is as follows.

// S(0, T) S(1, T) ... S(N − 1, T)

// Each state must be represented as an integer and the integers must be separated by a space.

