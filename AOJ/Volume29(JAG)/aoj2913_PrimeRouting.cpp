// Problem J. Prime Routing
// Fox Jiro is one of the staffs of the ACM-ICPC 2018 Asia Yokohama Regional Contest and is responsible for designing the network for the venue of the contest. His network consists of [Math Processing Error] computers, which are connected by [Math Processing Error] cables. The [Math Processing Error]-th cable connects the [Math Processing Error]-th computer and the [Math Processing Error]-th computer, and it carries data in both directions. Your team will use the [Math Processing Error]-th computer in the contest, and a judge server is the [Math Processing Error]-th computer.

// He decided to adjust the routing algorithm of the network to maximize the performance of the contestants through the magical power of prime numbers. In this algorithm, a packet (a unit of data carried by the network) is sent from your computer to the judge server passing through the cables a prime number of times if possible. If it is impossible, the contestants cannot benefit by the magical power of prime numbers. To accomplish this target, a packet is allowed to pass through the same cable multiple times.

// You decided to write a program to calculate the minimum number of times a packet from [Math Processing Error] to [Math Processing Error] needed to pass through the cables. If the number of times a packet passes through the cables cannot be a prime number, print [Math Processing Error].

// Input
// The input consists of a single test case, formatted as follows.

// [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error]
// [Math Processing Error] [Math Processing Error]
// [Math Processing Error]
// [Math Processing Error] [Math Processing Error]
// The first line consists of four integers [Math Processing Error] and [Math Processing Error] ([Math Processing Error]). The [Math Processing Error]-th line of the following [Math Processing Error] lines consists of two integers [Math Processing Error] and [Math Processing Error] ([Math Processing Error]), which means the [Math Processing Error]-th cables connects the [Math Processing Error]-th computer and the [Math Processing Error]-th computer in the network. You can assume that the network satisfies the following conditions.

// The network has no multi-edge, i.e.,[Math Processing Error] for all [Math Processing Error] ([Math Processing Error]).
// The packets from [Math Processing Error] computers are reachable to [Math Processing Error] by passing through some number of cables. The number is not necessarily a prime.
// Output
// If there are ways such that the number of times a packet sent from [Math Processing Error] to [Math Processing Error] passes through the cables is a prime number, print the minimum prime number of times in one line. Otherwise, print [Math Processing Error].

