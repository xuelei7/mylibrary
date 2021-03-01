#include <bits/stdc++.h>
using namespace std;
vector<int> color;
vector<int> G[100];

//DFS
//頂点v以降を二色で塗れるか
bool dfs(int v, int c) {
    if (color[v] == 0) {
        color[v] = c;
        for (int i = 0; i < G[v].size(); i++) {
            int to = G[v][i];
            if (!dfs(to, -c)) return false;
        }
        return true;
    }
    return color[v] == c;
}

//Union Find
/*
unite(a,b+n);
unite(a+n,b);

i,i+nが同じグループにあるなら二部グラフではない
*/

int main() {
    return 0;
}