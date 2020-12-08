#include <bits/stdc++.h>
using namespace std;

class BIT{
    int bit[1<<19];
public:
    void insert(int id, int num) {
        int tmp = id;
        while (tmp < (1 << 19)) {
            bit[tmp] += num;
            tmp += -tmp & tmp;
        }
    }
    int find(int id) {
        int tmp = id;
        int ret = 0;
        while (tmp > 0) {
            ret += bit[tmp];
            tmp -= -tmp & tmp;
        }
        return ret;
    }
    int find(int left, int right) {
        return find(right) - find(left - 1);
    }
};

int main() {
    return 0;
}