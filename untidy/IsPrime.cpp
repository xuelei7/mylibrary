#include <iostream>
using namespace std;

bool isPrime(long long data) {
  for (long long i = 2; i * i <= data; i++) {
    if (data % i == 0) return 0;
  }
  return 1;
}

int main() {
  int data;
  cin >> data;
  cout << isPrime(data) << endl;
  return 0;
}
