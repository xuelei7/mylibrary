// Problem I Starting a Scenic Railroad Service
// Jim, working for a railroad company, is responsible for planning a new tourist train service. He is sure that the train route along a scenic valley will arise a big boom, but not quite sure how big the boom will be.

// A market survey was ordered and Jim has just received an estimated list of passengers' travel sections. Based on the list, he'd like to estimate the minimum number of train seats that meets the demand.

// Providing as many seats as all of the passengers may cost unreasonably high. Assigning the same seat to more than one passenger without overlapping travel sections may lead to a great cost cutback.

// Two different policies are considered on seat assignments. As the views from the train windows depend on the seat positions, it would be better if passengers can choose a seat. One possible policy (named `policy-1') is to allow the passengers to choose an arbitrary seat among all the remaining seats when they make their reservations. As the order of reservations is unknown, all the possible orders must be considered on counting the required number of seats.

// The other policy (named `policy-2') does not allow the passengers to choose their seats; the seat assignments are decided by the railroad operator, not by the passengers, after all the reservations are completed. This policy may reduce the number of the required seats considerably.

// Your task is to let Jim know how dierent these two policies are by providing him a program that computes the numbers of seats required under the two seat reservation policies. Let us consider a case where there are four stations, S1, S2, S3, and S4, and four expected passengers p1, p2, p3, and p4 with the travel list below.

// passenger	from	to
// p1	S1	S2
// p2	S2	S3
// p3	S1	S3
// p4	S3	S4

// The travel sections of p1 and p2 do not overlap, that of p3 overlaps those of p1 and p2, and that of p4 does not overlap those of any others.

// Let's check if two seats would suffice under the policy-1. If p1 books a seat first, either of the two seats can be chosen. If p2 books second, as the travel section does not overlap that of p1, the same seat can be booked, but the other seat may look more attractive to p2. If p2 reserves a seat different from that of p1, there will remain no available seats for p3 between S1 and S3 (Figure I.1).


// Figure I.1. With two seats

// With three seats, p3 can find a seat with any seat reservation combinations by p1 and p2. p4 can also book a seat for there are no other passengers between S3 and S4 (Figure I.2).


// Figure I.2. With three seats

// For this travel list, only three seats suffice considering all the possible reservation orders and seat preferences under the policy-1.

// On the other hand, deciding the seat assignments after all the reservations are completed enables a tight assignment with only two seats under the policy-2 (Figure I.3).


// Figure I.3. Tight assignment to two seats

// Input
// The input consists of a single test case of the following format.

// n
// a1 b1
// ...
// an bn
// Here, the first line has an integer n, the number of the passengers in the estimated list of passengers' travel sections (1≤n≤200000). The stations are numbered starting from 1 in their order along the route. Each of the following n lines describes the travel for each passenger by two integers, the boarding and the alighting station numbers, ai and bi, respectively (1≤ai<bi≤100000). Note that more than one passenger in the list may have the same boarding and alighting stations.

// Output
// Two integers s1 and s2 should be output in a line in this order, separated by a space. s1 and s2 are the numbers of seats required under the policy-1 and -2, respectively.


