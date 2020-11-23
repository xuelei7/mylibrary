// Physical Experiments
// Ignoring the air resistance, velocity of a freely falling object v after t seconds and its drop y in t seconds are represented by the following formulas:

// v=9.8t
// y=4.9t^2

// A person is trying to drop down a glass ball and check whether it will crack. Your task is to write a program to help this experiment.

// You are given the minimum velocity to crack the ball. Your program should print the lowest possible floor of a building to crack the ball. The height of the N floor of the building is defined by 5×N−5.

// Input
// The input consists of multiple datasets. Each dataset, a line, consists of the minimum velocity v (0 < v < 200) to crack the ball. The value is given by a decimal fraction, with at most 4 digits after the decimal point. The input ends with EOF. The number of datasets is less than or equal to 50.

// Output
// For each dataset, print the lowest possible floor where the ball cracks.

#include <bits/stdc++.h>
using namespace std;

int main() {
    double v;
    while (cin >> v) {
        for (int n = 1; ; n++) {
            double y = 5 * n - 5;
            double t = sqrt(y / 4.9);
            if (9.8 * t >= v) {
                cout << n << endl;
                break;
            }
        }
        
    }
    return 0;
}