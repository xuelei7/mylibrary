// Problem F: City Merger
// Recent improvements in information and communication technology have made it possible to provide municipal service to a wider area more quickly and with less costs. Stimulated by this, and probably for saving their not sufficient funds, mayors of many cities started to discuss on mergers of their cities.

// There are, of course, many obstacles to actually put the planned mergers in practice. Each city has its own culture of which citizens are proud. One of the largest sources of friction is with the name of the new city. All citizens would insist that the name of the new city should have the original name of their own city at least as a part of it. Simply concatenating all the original names would, however, make the name too long for everyday use.

// You are asked by a group of mayors to write a program that finds the shortest possible name for the new city that includes all the original names of the merged cities. If two or more cities have common parts, they can be overlapped. For example, if "FUKUOKA", "OKAYAMA", and "YAMAGUCHI" cities are to be merged, "FUKUOKAYAMAGUCHI" is such a name that include all three of the original city names. Although this includes all the characters of the city name "FUKUYAMA" in this order, it does not appear as a consecutive substring, and thus "FUKUYAMA" is not considered to be included in the name.

// Input
// The input is a sequence of datasets. Each dataset begins with a line containing a positive integer n (n ≤ 14), which denotes the number of cities to be merged. The following n lines contain the names of the cities in uppercase alphabetical letters, one in each line. You may assume that none of the original city names has more than 20 characters. Of course, no two cities have the same name.

// The end of the input is indicated by a line consisting of a zero.

// Output
// For each dataset, output the length of the shortest possible name of the new city in one line. The output should not contain any other characters.

