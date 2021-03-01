// Estimating the Flood Risk
// Mr. Boat is the owner of a vast extent of land. As many typhoons have struck Japan this year, he became concerned of flood risk of his estate and he wants to know the average altitude of his land. The land is too vast to measure the altitude at many spots. As no steep slopes are in the estate, he thought that it would be enough to measure the altitudes at only a limited number of sites and then approximate the altitudes of the rest based on them.

// Multiple approximations might be possible based on the same measurement results, in which case he wants to know the worst case, that is, one giving the lowest average altitude.

// Mr. Boat’s estate, which has a rectangular shape, is divided into grid-aligned rectangular areas of the same size. Altitude measurements have been carried out in some of these areas, and the measurement results are now at hand. The altitudes of the remaining areas are to be approximated on the assumption that altitudes of two adjoining areas sharing an edge differ at most 1.

// In the first sample given below, the land is divided into 5 × 4 areas. The altitudes of the areas at (1, 1) and (5, 4) are measured 10 and 3, respectively. In this case, the altitudes of all the areas are uniquely determined on the assumption that altitudes of adjoining areas differ at most 1.

// In the second sample, there are multiple possibilities, among which one that gives the lowest average altitude should be considered.

// In the third sample, no altitude assignments satisfy the assumption on altitude differences.


// Your job is to write a program that approximates the average altitude of his estate. To be precise, the program should compute the total of approximated and measured altitudes of all the mesh-divided areas. If two or more different approximations are possible, the program should compute the total with the severest approximation, that is, one giving the lowest total of the altitudes.

// Input
// The input consists of a single test case of the following format.

// [Math Processing Error] [Math Processing Error] [Math Processing Error]
// [Math Processing Error] [Math Processing Error] [Math Processing Error]
// .
// .
// .
// [Math Processing Error] [Math Processing Error] [Math Processing Error]
// Here, [Math Processing Error], [Math Processing Error], and [Math Processing Error] are integers between [Math Processing Error] and [Math Processing Error], inclusive. [Math Processing Error] and [Math Processing Error] are the numbers of areas in the two sides of the land. [Math Processing Error] is the number of areas where altitudes are measured. The [Math Processing Error]-th line of the following [Math Processing Error] lines contains three integers, [Math Processing Error], [Math Processing Error], and [Math Processing Error] satisfying [Math Processing Error], [Math Processing Error], and [Math Processing Error]. They mean that the altitude of the area at [Math Processing Error] was measured to be [Math Processing Error]. At most one measurement result is given for the same area, i.e., for [Math Processing Error], [Math Processing Error].

// Output
// If all the unmeasured areas can be assigned their altitudes without any conflicts with the measured altitudes assuming that two adjoining areas have the altitude difference of at most 1, output an integer that is the total of the measured or approximated altitudes of all the areas. If more than one such altitude assignment is possible, output the minimum altitude total among the possible assignments.

// If no altitude assignments satisfy the altitude difference assumption, output No.

