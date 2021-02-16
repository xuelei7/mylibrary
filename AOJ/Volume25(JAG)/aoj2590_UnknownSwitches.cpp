// Problem Statement
// In the headquarter building of ICPC (International Company of Plugs & Connectors), there are M light bulbs and they are controlled by N switches. Each light bulb can be turned on or off by exactly one switch. Each switch may control multiple light bulbs. When you operate a switch, all the light bulbs controlled by the switch change their states. You lost the table that recorded the correspondence between the switches and the light bulbs, and want to restore it.

// You decided to restore the correspondence by the following procedure.

// At first, every switch is off and every light bulb is off.
// You operate some switches represented by S1.
// You check the states of the light bulbs represented by B1.
// You operate some switches represented by S2.
// You check the states of the light bulbs represented by B2.
// ...
// You operate some switches represented by SQ.
// You check the states of the light bulbs represented by BQ.
// After you operate some switches and check the states of the light bulbs, the states of the switches and the light bulbs are kept for next operations.

// Can you restore the correspondence between the switches and the light bulbs using the information about the switches you have operated and the states of the light bulbs you have checked?

// Input
// The input consists of multiple datasets. The number of dataset is no more than 50 and the file size is no more than 10MB. Each dataset is formatted as follows.

// N M Q
// S1 B1
// :
// :
// SQ BQ
// The first line of each dataset contains three integers N (1≤N≤36), M (1≤M≤1,000), Q (0≤Q≤1,000), which denote the number of switches, the number of light bulbs and the number of operations respectively. The following Q lines describe the information about the switches you have operated and the states of the light bulbs you have checked. The i-th of them contains two strings Si and Bi of lengths N and M respectively. Each Si denotes the set of the switches you have operated: Sij is either 0 or 1, which denotes the j-th switch is not operated or operated respectively. Each Bi denotes the states of the light bulbs: Bij is either 0 or 1, which denotes the j-th light bulb is off or on respectively.

// You can assume that there exists a correspondence between the switches and the light bulbs which is consistent with the given information.

// The end of input is indicated by a line containing three zeros.

// Output
// For each dataset, output the correspondence between the switches and the light bulbs consisting of M numbers written in base-36. In the base-36 system for this problem, the values 0-9 and 10-35 are represented by the characters '0'-'9' and 'A'-'Z' respectively. The i-th character of the correspondence means the number of the switch controlling the i-th light bulb. If you cannot determine which switch controls the i-th light bulb, output '?' as the i-th character instead of the number of a switch.

