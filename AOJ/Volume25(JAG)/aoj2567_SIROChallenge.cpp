// Problem Statement
// You are now participating in the Summer Training Camp for Programming Contests with your friend Jiro, who is an enthusiast of the ramen chain SIRO. Since every SIRO restaurant has its own tasteful ramen, he wants to try them at as many different restaurants as possible in the night. He doesn't have plenty of time tonight, however, because he has to get up early in the morning tomorrow to join a training session. So he asked you to find the maximum number of different restaurants to which he would be able to go to eat ramen in the limited time.

// There are $n$ railway stations in the city, which are numbered $1$ through $n$. The station $s$ is the nearest to the camp venue. $m$ pairs of stations are directly connected by the railway: you can move between the stations $a_i$ and $b_i$ in $c_i$ minutes in the both directions. Among the stations, there are $l$ stations where a SIRO restaurant is located nearby. There is at most one SIRO restaurant around each of the stations, and there are no restaurants near the station $s$. It takes $e_i$ minutes for Jiro to eat ramen at the restaurant near the station $j_i$.

// It takes only a negligibly short time to go back and forth between a station and its nearby SIRO restaurant. You can also assume that Jiro doesn't have to wait for the ramen to be served in the restaurants.

// Jiro is now at the station $s$ and have to come back to the station in $t$ minutes. How many different SIRO's can he taste?

// Input
// The input is a sequence of datasets. The number of the datasets does not exceed $100$. Each dataset is formatted as follows:

// $n$ $m$ $l$ $s$ $t$
// $a_1$ $b_1$ $c_1$
// :
// :
// $a_m$ $b_m$ $c_m$
// $j_1$ $e_1$
// :
// :
// $j_l$ $e_l$
// The first line of each dataset contains five integers:

// $n$ for the number of stations,

// $m$ for the number of directly connected pairs of stations,

// $l$ for the number of SIRO restaurants,

// $s$ for the starting-point station, and

// $t$ for the time limit for Jiro.

// Each of the following $m$ lines contains three integers:

// $a_i$ and $b_i$ for the connected stations, and

// $c_i$ for the time it takes to move between the two stations.

// Each of the following $l$ lines contains two integers:

// $j_i$ for the station where a SIRO restaurant is located, and

// $e_i$ for the time it takes for Jiro to eat at the restaurant.

// The end of the input is indicated by a line with five zeros, which is not included in the datasets.

// The datasets satisfy the following constraints:

// $2 \le n \le 300$

// $1 \le m \le 5{,}000$

// $1 \le l \le 16$

// $1 \le s \le n$

// $1 \le t \le 100{,}000$

// $1 \le a_i, b_i \le n$

// $1 \le c_i \le 1{,}000$

// $1 \le j_i \le n$

// $1 \le e_i \le 15$

// $s \ne j_i$

// $j_i$'s are distinct.

// $a_i \ne b_i$

// $(a_i, b_i) \ne (a_j, b_j)$ and $(a_i, b_i) \ne (b_j, a_j)$ for any $i \ne j$

// Note that there may be some stations not reachable from the starting point $s$.

// Output
// For each data set, output the maximum number of different restaurants where Jiro can go within the time limit.

