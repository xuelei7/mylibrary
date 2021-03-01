// Building a Space Station
// You are a member of the space station engineering team, and are assigned a task in the construction process of the station. You are expected to write a computer program to complete the task.

// The space station is made up with a number of units, called cells. All cells are sphere-shaped, but their sizes are not necessarily uniform. Each cell is fixed at its predetermined position shortly after the station is successfully put into its orbit. It is quite strange that two cells may be touching each other, or even may be overlapping. In an extreme case, a cell may be totally enclosing another one. I do not know how such arrangements are possible.

// All the cells must be connected, since crew members should be able to walk from any cell to any other cell. They can walk from a cell A to another cell B, if, (1) A and B are touching each other or overlapping, (2) A and B are connected by a `corridor', or (3) there is a cell C such that walking from A to C, and also from B to C are both possible. Note that the condition (3) should be interpreted transitively.

// You are expected to design a configuration, namely, which pairs of cells are to be connected with corridors. There is some freedom in the corridor configuration. For example, if there are three cells A, B and C, not touching nor overlapping each other, at least three plans are possible in order to connect all three cells. The first is to build corridors A-B and A-C, the second B-C and B-A, the third C-A and C-B. The cost of building a corridor is proportional to its length. Therefore, you should choose a plan with the shortest total length of the corridors.

// You can ignore the width of a corridor. A corridor is built between points on two cells' surfaces. It can be made arbitrarily long, but of course the shortest one is chosen. Even if two corridors A-B and C-D intersect in space, they are not considered to form a connection path between (for example) A and C. In other words, you may consider that two corridors never intersect.

// Input
// The input consists of multiple data sets. Each data set is given in the following format.

// n
// x1 y1 z1 r1
// x2 y2 z2 r2
// ...
// xn yn zn rn
// The first line of a data set contains an integer n, which is the number of cells. n is positive, and does not exceed 100.

// The following n lines are descriptions of cells. Four values in a line are x-, y- and z-coordinates of the center, and radius (called r in the rest of the problem) of the sphere, in this order. Each value is given by a decimal fraction, with 3 digits after the decimal point. Values are separated by a space character.

// Each of x, y, z and r is positive and is less than 100.0.

// The end of the input is indicated by a line containing a zero.

// Output
// For each data set, the shortest total length of the corridors should be printed, each in a separate line. The printed values should have 3 digits after the decimal point. They may not have an error greater than 0.001.

// Note that if no corridors are necessary, that is, if all the cells are connected without corridors, the shortest total length of the corridors is 0.000.

#include <bits/stdc++.h>
using namespace std;
int n;
double d[110][110];
double x[110], y[110], z[110], r[110];
int main() {
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i] >> r[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double dd = 0;
                dd += (x[i]-x[j])*(x[i]-x[j]);
                dd += (y[i]-y[j])*(y[i]-y[j]);
                dd += (z[i]-z[j])*(z[i]-z[j]);
                dd = sqrt(dd) - r[i] - r[j];
                d[i][j] = max(0.0,dd);
            }
        }
        set<int> st;
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        for (int i = 1; i < n; i++) {
            pq.push({d[0][i],i});
        }
        st.insert(0);
        double ans = 0;
        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            double dd = tp.first;
            int id = tp.second;
            if (st.find(id) != st.end()) continue;
            ans += dd;
            st.insert(id);
            for (int i = 0; i < n; i++) {
                if (!st.count(i)) pq.push({d[id][i],i});
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}