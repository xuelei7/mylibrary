#include <bits/stdc++.h>
using namespace std;

int main(){

  int m;
  cin >> m;

  //Case 1:
  if (m < 100) {
    cout << "00" << endl;
  }

  //Case 2:
  else if (m <= 5000) {
    cout << setw(2) << setfill('0') << m * 10 / 1000 << endl;
  }

  //Case 3:
  else if (m <= 30000) {
    cout << m / 1000 + 50 << endl;
  }

  //Case 4:
  else if (m <= 70000) {
    cout << (m / 1000 - 30) / 5 + 80 << endl;
  }

  //Case 5:
  else {
    cout << 89 << endl;
  }

  return 0;
}
