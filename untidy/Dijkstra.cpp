#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
struct edge{int to, cost;};
const int INF = 1e9;
int V;
const int MAX_V = 1e5;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s, int *d, vector<edge> *G, int V) {
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  return 0;
}
