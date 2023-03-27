// TC: O(E * V^3)
// SC: O(E + V)
// E is the number of edges and V is the number of vertices in the graph
// Mahesh Reddy B N

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Edge {
    int v, u, w;
    Edge(int v, int u, int w) : v(v), u(u), w(w) {}
};
vector<vector<int>> adj;
vector<Edge> edges;
vector<int> parent;
int bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({s, INF});
    while (!q.empty()) {
        int v = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int i = 0; i < adj[v].size(); ++i) {
            int e = adj[v][i];
            int u = edges[e].u;
            if (parent[u] == -1 && edges[e].w > 0) {
                int new_flow = min(flow, edges[e].w);
                parent[u] = e;
                if (u == t) {
                    return new_flow;
                }
                q.push({u, new_flow});
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        int new_flow = bfs(s, t);
        if (new_flow == 0) {
            break;
        }
        flow += new_flow;
        int v = t;
        while (v != s) {
            int e = parent[v];
            edges[e].w -= new_flow;
            edges[e^1].w += new_flow;
            v = edges[e].v;
        }
    }
    return flow;
}
int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    parent.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
        edges.push_back(Edge(v, u, 0));
        adj[u].push_back(edges.size() - 2);
        adj[v].push_back(edges.size() - 1);
    }
    int s, t;
    cin >> s >> t;
    int max_flow_val = max_flow(s, t);
    cout<<"Mahesh Reddy B N"<<endl;
    cout<<"Output : "<<endl;
    cout << "Max flow: " << max_flow_val << endl;
    return 0;
}














