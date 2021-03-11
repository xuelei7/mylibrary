// Problem D: Long Distance Taxi
// A taxi driver, Nakamura, was so delighted because he got a passenger who wanted to go to a city thousands of kilometers away. However, he had a problem. As you may know, most taxis in Japan run on liquefied petroleum gas (LPG) because it is cheaper than gasoline. There are more than 50,000 gas stations in the country, but less than one percent of them sell LPG. Although the LPG tank of his car was full, the tank capacity is limited and his car runs 10 kilometer per liter, so he may not be able to get to the destination without filling the tank on the way. He knew all the locations of LPG stations. Your task is to write a program that finds the best way from the current location to the destination without running out of gas.

// Input
// The input consists of several datasets, and each dataset is in the following format.

// N M cap
// src dest
// c1,1 c1,2 d1
// c2,1 c2,2 d2
// .
// .
// .
// cN,1 cN,2 dN
// s1
// s2
// .
// .
// .
// sM

// The first line of a dataset contains three integers (N, M, cap), where N is the number of roads (1 ≤ N ≤ 3000),M is the number of LPG stations (1≤ M ≤ 300), and cap is the tank capacity (1 ≤ cap ≤ 200) in liter. The next line contains the name of the current city (src) and the name of the destination city (dest). The destination city is always different from the current city. The following N lines describe roads that connect cities. The road i (1 ≤ i ≤ N) connects two different cities ci,1 and ci,2 with an integer distance di (0 < di ≤ 2000) in kilometer, and he can go from either city to the other. You can assume that no two different roads connect the same pair of cities. The columns are separated by a single space. The next M lines (s1,s2,...,sM) indicate the names of the cities with LPG station. You can assume that a city with LPG station has at least one road.

// The name of a city has no more than 15 characters. Only English alphabet ('A' to 'Z' and 'a' to 'z', case sensitive) is allowed for the name.

// A line with three zeros terminates the input.

// Output
// For each dataset, output a line containing the length (in kilometer) of the shortest possible journey from the current city to the destination city. If Nakamura cannot reach the destination, output "-1" (without quotation marks). You must not output any other characters. The actual tank capacity is usually a little bit larger than that on the specification sheet, so you can assume that he can reach a city even when the remaining amount of the gas becomes exactly zero. In addition, you can always fill the tank at the destination so you do not have to worry about the return trip.

