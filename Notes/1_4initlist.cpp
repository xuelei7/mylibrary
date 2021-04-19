// 初期化子リスト
#include <vector>

int main () {
    // 1, 2, 3の3要素を持つ配列オブジェクトを定義する
    int ar[] = {1, 2, 3};
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 {1, 2, 3};

    // 再代入
    v2 = {4, 5, 6};

}