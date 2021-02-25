// I: Starting Line
// ICPC で良い成績を収めるには修行が欠かせない．うさぎは ICPC で勝ちたいので，今日も修行をすることにした．

// 今日の修行は，一直線上の道を走って，体力と判断力を養おうというものである．うさぎは今，スタートラインに立って長い長い道を見渡している．

// 道の途中にはいくつかニンジンが置かれており，うさぎはニンジンを食べると加速することができる．加速していないときのうさぎの走る速さは毎秒 U メートルであるが，ニンジンを食べることで，最後のニンジンを食べてから T 秒後までは速さが毎秒 V メートルとなる．また，うさぎはニンジンを K 個まで食べずに持っておくことができる．ニンジンを持っていても走る速さは変わらない．

// ニンジンを持ったり食べたりするのに時間はかからないとして，ゴールまでの最短所要時間を求めたい．

// Input
// N K T U V L
// D1
//  ...
// DN
// N はニンジンの個数，L はスタートからゴールまでの距離 (メートル)，Di (1 ≤ i ≤ N) は i 番目のニンジンが置かれている場所のスタートからの距離 (メートル) である．

// 1 ≤ N ≤ 200，1 ≤ K ≤ N，1 ≤ T ≤ 10,000，1 ≤ U < V ≤ 10,000，2 ≤ L ≤ 10,000，0 < D1 < D2 < ... < DN < L を満たす．入力の値はすべて整数である．

// Output
// 最短所要時間 (秒) を 1 行に出力せよ．10-6 以下の絶対誤差が許容される．

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k,t,l;
    double u,v;
    double time = 0;
    set<int> st;
    cin >> n >> k >> t >> u >> v >> l;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        st.insert(p);
    }
    // from i-1 to i
    int carrot = 0;
    int leftdist = 0;
    double speed = u;
    for (int i = 1; i <= l; i++) {
        time += 1.0 / speed;
        leftdist--;
        leftdist = max(leftdist,0);
        if (leftdist == 0) {
            if (carrot != 0) {
                carrot--;
                leftdist = t * v;
                speed = v;
            } else speed = u;
        }
        if (st.count(i)) {
            carrot++;
            if (carrot > k || leftdist == 0) {
                carrot--;
                leftdist = t * v;
                speed = v;
            }
        }
        // cout << i << " " << carrot << " " << leftdist << " " << time << endl;
    }

    cout << fixed << setprecision(20) << time << endl;
    return 0;
}