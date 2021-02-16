// Problem B: Butterfly
// Claire is a man-eater. She's a real man-eater. She's going around with dozens of guys. She's dating all the time. And one day she found some conflicts in her date schedule. D'oh!

// So she needs to pick some dates and give the others up. The dates are set by hours like 13:00 to 15:00. She may have more than one date with a guy. For example, she can have dates with Adam from 10:00 to 12:00 and from 14:00 to 16:00 and with Bob from 12:00 to 13:00 and from 18:00 to 20:00. She can have these dates as long as there is no overlap of time. Time of traveling, time of make-up, trouble from love triangles, and the likes are not of her concern. Thus she can keep all the dates with Adam and Bob in the previous example. All dates are set between 6:00 and 22:00 on the same day.

// She wants to get the maximum amount of satisfaction in total. Each guy gives her some satisfaction if he has all scheduled dates. Let's say, for example, Adam's satisfaction is 100 and Bob's satisfaction is 200. Then, since she can make it with both guys, she can get 300 in total. Your task is to write a program to satisfy her demand. Then she could spend a few hours with you... if you really want.

// Input
// The input consists of a sequence of datasets. Each dataset has the following format:

// N
// Guy1
// ...
// GuyN
// The first line of the input contains an integer N (1 ≤ N ≤ 100), the number of guys. Then there come the descriptions of guys. Each description is given in this format:

// M L
// S1 E1
// ...
// SM EM
// The first line contains two integers Mi (1 ≤ Mi ≤ 16) and Li (1 ≤ Li ≤ 100,000,000), the number of dates set for the guy and the satisfaction she would get from him respectively. Then M lines follow. The i-th line contains two integers Si and Ei (6 ≤ Si < Ei ≤ 22), the starting and ending time of the i-th date.

// The end of input is indicated by N = 0.

// Output
// For each dataset, output in a line the maximum amount of satisfaction she can get.

