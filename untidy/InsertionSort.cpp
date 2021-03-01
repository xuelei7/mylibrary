#include <iostream>
using namespace std;

template <typename T>
class InsertionSort{
private:
  T *A;
  int sz;
public:
  InsertionSort(int n) {
    A = new T[n];
    sz = n;
  }
  ~InsertionSort() {delete[] A;}
  void set(int k, T val) {A[k] = val;}
  void sort() {
    for (int i = 1; i < sz; i++) {
      int v = A[i];
      int j = i - 1;
      while (j >= 0 && v < A[j]) {
        A[j+1] = A[j];
        j--;
      }
      A[j+1] = v;
    }
  }
  int size() {return sz;}
  void show() {
    for (int i = 0; i < sz; i++) {
      cout << A[i] << " \n"[i == sz - 1];
    }
  }
};

int main() {
  int n;
  cin >> n;
  InsertionSort<int> is(n);
  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    is.set(i,data);
  }
  is.sort();
  return 0;
}
