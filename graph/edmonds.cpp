#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Weight maximumFlow(const Graph &g, int s, int t) {
    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n));
    REP(u,n) EACH(e,g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    while (1) {
        queue<int> Q; Q.push(s);
        vector<int> prev(n, -1); prev[s] = s;
        while (!Q.empty() && prev[t] < 0) {
            int u = Q.front(); Q.pop();
            EACH(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                prev[e->dst] = u;
                Q.push(e->dst);
            }
        }
        if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
        Weight inc = INF;
        for (int j = t; prev[j] != j; j = prev[j])
            inc = min(inc, RESIDUE(prev[j], j));
        for (int j = t; prev[j] != j; j = prev[j])
            flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
        total += inc;
    }
}
