//------------------------------
// from
// aoj0156, aoj2332, aoj2608
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


// lowlink
struct edge {
    int from, to;
    longl long cost;
};
using edges = vector<edge>;
using graph = vector<edges>;
void add_edge(graph& g, int from, int to, ll cost) {
    g[from].push_back(edge{from, to, cost});
}
struct lowlink { // multiple edges ok
    std::vector<int> articulation_points;
    std::vector<edge> bridges;
    std::vector<int> ord, low;

    lowlink(graph const& g) : ord(g.size()), low(g.size()) {
        const int n = g.size();
        std::vector<bool> visited(n);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(g, i, -1, cnt, visited);
            }
        }
    }

    std::vector<int> get_articulation_points() const { return articulation_points; }
    std::vector<edge> get_bridges() const            { return bridges; }

    bool is_bridge(int u, int v) const {
        if(ord[u] > ord[v]) std::swap(u, v);
        return ord[u] < low[v];
    }

private:
    void dfs(graph const& g, int v, int prev, int& cnt, std::vector<bool>& visited) {
        cout << "dfs " << v << " " << prev << " " << cnt << endl;
        visited[v] = true;
        low[v] = ord[v] = cnt++;
        bool is_articulation = false;
        int cnt2 = 0, pcnt = 0;

        for(auto& e : g[v]) {
            if((e.to != prev || (e.to == prev && pcnt == 1)) && visited[e.to]) {
                low[v] = min(low[v], ord[e.to]);
            } else if(!visited[e.to]) {
                cnt2++;
                dfs(g, e.to, v, cnt, visited);
                low[v] = min(low[v], low[e.to]);
                if(prev != -1 && ord[v] <= low[e.to]) {
                    is_articulation = true;
                }
                if(is_bridge(v, e.to)) {
                    bridges.push_back(edge{min(v, e.to), max(v, e.to), e.cost});
                }
            }
            pcnt += e.to == prev;
        }
        is_articulation |= (prev == -1 && cnt2 > 1);
        if(is_articulation) articulation_points.push_back(v);

        cout << "end dfs: " << v << ", ord: " << ord[v] << ", low: " << low[v] << endl; 
    }
};

// menu
// void dijkstra
// struct lowlink