#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])

#define GLOBAL_RELABELING() { \
    queue<int> Q; Q.push(t); \
    fill(ALL(d), INF); d[t] = 0; \
    while (!Q.empty()) { \
        int u = Q.front(); Q.pop(); \
        EACH(e, g[u]) if (RESIDUE(e->dst, u) > 0 && d[u] + 1 < d[e->dst])  \
        Q.push(e->dst), d[e->dst] = d[u] + 1; \
    } \
}

#define PUSH(u, v) { \
    Weight delta = min(excess[u], RESIDUE(u, v)); \
    flow[u][v] += delta; flow[v][w] -= delta; \
    excess[u] -= delta; excess[v] += delta; }

Weight maximumFlow(const Graph &g, int s, int t) {
    int n = g.size(), count = 0;
    Matrix flow(n, Array(n)), capacity(n, Array(n)); // adj. matrix
    REP(u,n) EACH(e,g[u]) capacity[e->src][e->dst] += e->weight;

    vector<Weight> excess(n); excess[s] = INF; // initialize step
    vector<int> d(n);
    GLOBAL_RELABELING();
    vector< queue<int> > B(n); B[ d[s] ].push( s );

    for (int b = d[s]; b >= 0; ) {
        if (B[b].empty()) { --b; continue; }
        int v = B[b].front(); B[b].pop();
        if (excess[v] == 0 || v == t) continue;

        EACH(e, g[v]) {
            int w = e->dst; // e is the current edge of v
            if (RESIDUE(v,w) > 0 && d[v] == d[w] + 1) { // (w,v) is admissible
                PUSH(v, w);
                if (excess[w] > 0 && w != t) B[d[w]].push( w );
            }
        }
        if (excess[v] == 0) continue;
        d[v] = n;
        EACH(e, g[v]) if (RESIDUE(v, e->dst) > 0)
            d[v] = min(d[v], d[e->dst] + 1);
        if (d[v] < n) B[b = d[v]].push(v);

        if (++count % n == 0) GLOBAL_RELABELING(); // !!HEURISTICS
    }
    return excess[t];
}
