// Marathon Match
// N people run a marathon. There are M resting places on the way. For each resting place, the i-th runner takes a break with probability Pi percent. When the i-th runner takes a break, he gets rest for Ti time.

// The i-th runner runs at constant speed Vi, and the distance of the marathon is L.

// You are requested to compute the probability for each runner to win the first place. If a runner arrives at the goal with another person at the same time, they are not considered to win the first place.

// Input
// A dataset is given in the following format:

// N M L
// P1 T1 V1
// P2 T2 V2
// …
// PN TN VN
// The first line of a dataset contains three integers N (1≤N≤100), M (0≤M≤50) and L (1≤L≤100,000). N is the number of runners. M is the number of resting places. L is the distance of the marathon.

// Each of the following N lines contains three integers Pi (0≤Pi≤100), Ti (0≤Ti≤100) and Vi (0≤Vi≤100) describing the i-th runner. Pi is the probability to take a break. Ti is the time of resting. Vi is the speed.

// Output
// For each runner, you should answer the probability of winning. The i-th line in the output should be the probability that the i-th runner wins the marathon. Each number in the output should not contain an error greater than 10−5.

