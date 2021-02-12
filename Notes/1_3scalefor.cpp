// 範囲for文
#include <iostream>
#include <vector>

int main() {

    std::vector<int> v = {1,2,3};

    for (std::vector<int>::const_iterator it = v.begin(), e = v.end(); it != e; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    for (const auto& e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    // const auto& e : eを変更できない
    // auto& e       : 実際のコンテナ内の値も変更できる
    // auto e        : eは変更できるが，コンテナ内の値が変更できない
}