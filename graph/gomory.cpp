#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
Graph cutTree(const Graph &g) {
    int n = g.size();
    Matrix capacity(n, Array(n)), flow(n, Array(n));
    REP(u,n) EACH(e,g[u]) capacity[e->src][e->dst] += e->weight;

    vector<int> p(n), prev;
    vector<Weight> w(n);
    for (int s = 1; s < n; ++s) {
        int t = p[s]; // max-flow(s, t)
        REP(i,n) REP(j,n) flow[i][j] = 0;
        Weight total = 0;
        while (1) {
            queue<int> Q; Q.push(s);
            prev.assign(n, -1); prev[s] = s;
            while (!Q.empty() && prev[t] < 0) {
                int u = Q.front(); Q.pop();
                EACH(e,g[u]) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
                    prev[e->dst] = u;
                    Q.push(e->dst);
                }
            }
            if (prev[t] < 0) goto esc;
            Weight inc = INF;
            for (int j = t; prev[j] != j; j = prev[j])
                inc = min(inc, RESIDUE(prev[j], j));
            for (int j = t; prev[j] != j; j = prev[j])
                flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
            total += inc;
        }
esc:w[s] = total; // make tree
    REP(u, n) if (u != s && prev[u] != -1 && p[u] == t)
        p[u] = s;
    if (prev[p[t]] != -1)
        p[s] = p[t], p[t] = s, w[s] = w[t], w[t] = total;
    }
    Graph T(n); // (s, p[s]) is a tree edge of weight w[s]
    REP(s, n) if (s != p[s]) {
        T[  s ].push_back( Edge(s, p[s], w[s]) );
        T[p[s]].push_back( Edge(p[s], s, w[s]) );
    }
    return T;
}

// Gomory-Hu tree O(n)
Weight maximumFlow(const Graph &T, int u, int t, int p = -1, Weight w = INF) {
    if (u == t) return w;
    Weight d = INF;
    EACH(e, T[u]) if (e->dst != p)
        d = min(d, maximumFlow(T, e->dst, t, u, min(w, e->weight)));
    return d;
}
