// Problem B. Colorful Drink
// In the Jambo Amusement Garden (JAG), you sell colorful drinks consisting of multiple color layers. This colorful drink can be made by pouring multiple colored liquids of different density from the bottom in order.

// You have already prepared several colored liquids with various colors and densities. You will receive a drink request with specified color layers. The colorful drink that you will serve must satisfy the following conditions.

// You cannot use a mixed colored liquid as a layer. Thus, for instance, you cannot create a new liquid with a new color by mixing two or more different colored liquids, nor create a liquid with a density between two or more liquids with the same color by mixing them.
// Only a colored liquid with strictly less density can be an upper layer of a denser colored liquid in a drink. That is, you can put a layer of a colored liquid with density x directly above the layer of a colored liquid with density y if x<y holds.
// Your task is to create a program to determine whether a given request can be fulfilled with the prepared colored liquids under the above conditions or not.

// Input
// The input consists of a single test case in the format below.

// N
// C1 D1
// ⋮
// CN DN
// M
// O1
// ⋮
// OM
// The first line consists of an integer N (1≤N≤105), which represents the number of the prepared colored liquids. The following N lines consists of Ci and Di (1≤i≤N). Ci is a string consisting of lowercase alphabets and denotes the color of the i-th prepared colored liquid. The length of Ci is between 1 and 20 inclusive. Di is an integer and represents the density of the i-th prepared colored liquid. The value of Di is between 1 and 105 inclusive. The (N+2)-nd line consists of an integer M (1≤M≤105), which represents the number of color layers of a drink request. The following M lines consists of Oi (1≤i≤M). Oi is a string consisting of lowercase alphabets and denotes the color of the i-th layer from the top of the drink request. The length of Oi is between 1 and 20 inclusive.

// Output
// If the requested colorful drink can be served by using some of the prepared colored liquids, print 'Yes'. Otherwise, print 'No'.

