#include <bits/stdc++.h>
using namespace std;

class FordFulkerson{
public:
  struct edge{int to, rev, cap;};

  const int INF = 2e9;
  static const int MAX_V = 10000;

  vector<edge> G[MAX_V];
  bool used[MAX_V] = {};
  void add_edge(int frm, int to, int cap) {
    G[frm].push_back((edge){to, G[to].size(), cap});
    G[to].push_back((edge){frm, G[frm].size() - 1, 0});
  }
  int dfs(int frm, int to, int flow) {
    if (frm == to) return flow;
    used[frm] = 1;
    for (int i = 0; i < G[frm].size(); i++) {
      edge &e = G[frm][i];
      if (!used[e.to] && e.cap > 0) {
        int d = dfs(e.to, to, min(flow, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
  int maxflow(int s, int t) {
    int flow = 0;
    while (1) {
      memset(used, 0, sizeof(used));
      int f = dfs(s, t, INF);
      if (f == 0) return flow;
      flow += f;
    }
  }
};

int main() {
  return 0;
}
