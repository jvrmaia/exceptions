Weight chinesePostman(const Graph &g) {
    Weight total = 0;
    vector<int> odds;
    REP(u, g.size()) {
        EACH(e, g[u]) total += e->weight;
        if (g[u].size() % 2) odds.push_back(u);
    }
    total /= 2;
    int n = odds.size(), N = 1 << n;
    Weight w[n][n]; // make odd vertices graph
    REP(u,n) {
        int s = odds[u]; // dijkstra's shortest path
        vector<Weight> dist(g.size(), INF); dist[s] = 0;
        vector<int>    prev(g.size(), -2);
        priority_queue<Edge> Q;
        Q.push( Edge(-1, s, 0) );
        while (!Q.empty()) {
            Edge e = Q.top(); Q.pop();
            if (prev[e.dst] != -2) continue;
            prev[e.dst] = e.src;
            EACH(f,g[e.dst]) {
                if (dist[f->dst] > e.weight+f->weight) {
                    dist[f->dst] = e.weight+f->weight;
                    Q.push(Edge(f->src, f->dst, e.weight+f->weight));
                }
            }
        }
        REP(v,n) w[u][v] = dist[odds[v]];
    }
    Weight best[N]; // DP for general matching
    REP(S,N) best[S] = INF;
    best[0] = 0;

    for (int S = 0; S < N; ++S)
        for (int i = 0; i < n; ++i) if (!(S&(1<<i)))
            for (int j = i+1; j < n; ++j) if (!(S&(1<<j)))
                best[S|(1<<i)|(1<<j)] = min(best[S|(1<<i)|(1<<j)], best[S]+w[i][j]);
    return total + best[N-1];
}
