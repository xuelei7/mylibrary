#include <bits/stdc++.h>
using namespace std;

class SegTreeMax{
    int seg[1<<19];
public:
    void insert(int id, int data) {
        id += (1 << 18);
        while (id > 0) {
            seg[id] = max(seg[id], data);
            id /= 2;
        }
    }
    int find(int left, int right) {
        left += (1 << 18);
        right += (1 << 18);
        int ret = -1000000000;
        while (left < right) {
            if (right % 2 == 0) {
                ret = max(ret, seg[right]);
                right--;
            }
            if (left & 1) {
                ret = max(ret, seg[left]);
                left++;
            }
        }
        ret = max(ret, seg[left]);
        return ret;
    }
};

int main() {
    return 0;
}