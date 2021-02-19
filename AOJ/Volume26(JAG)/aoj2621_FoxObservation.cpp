// Ievan Ritola is a researcher of behavioral ecology. Her group visited a forest to analyze an ecological system of some kinds of foxes.

// The forest can be expressed as a two-dimensional plane. With her previous research, foxes in the forest are known to live at lattice points. Here, lattice points are the points whose x and y coordinates are both integers. Two or more foxes might live at the same point.

// To observe the biology of these foxes, they decided to put a pair of sensors in the forest. The sensors can be put at lattice points. Then, they will be able to observe all foxes inside the bounding rectangle (including the boundary) where the sensors are catty-corner to each other. The sensors cannot be placed at the points that have the same x or y coordinate; in other words the rectangle must have non-zero area.

// The more foxes can be observed, the more data can be collected; on the other hand, monitoring a large area consumes a large amount of energy. So they want to maximize the value given by N'⁄(|x1−x2|×|y1−y2|), where N' is the number of foxes observed and (x1,y1) and (x2,y2) are the positions of the two sensors.

// Let's help her observe cute foxes!

// Input
// The input is formatted as follows.

// N
// x1 y1 w1
// x2 y2 w2
// :
// :
// xN yN wN
// The first line contains a single integer N (1≤N≤105) indicating the number of the fox lairs in the forest. Each of the next N lines contains three integers xi, yi (|xi|, |yi|≤109) and wi (1≤wi≤104), which represent there are wi foxes at the point (xi,yi). It is guaranteed that all points are mutually different.

// Output
// Output the maximized value as a fraction:

// a / b
// where a and b are integers representing the numerator and the denominato respectively. There should be exactly one space before and after the slash. The fraction should be written in the simplest form, that is, a and b must not have a common integer divisor greater than one.

// If the value becomes an integer, print a fraction with the denominator of one (e.g. 5 / 1 to represent 5). This implies zero should be printed as 0 / 1 (without quotes).

