Weight minimumDiameterSpanningTree(const Graph &g) {
    int n = g.size();
    Matrix dist(n, Array(n, INF)); // all-pair shortest
    REP(u, n) dist[u][u] = 0;
    REP(u, n) EACH(e, g[u]) dist[e->src][e->dst] = e->weight;
    REP(k, n) REP(i, n) REP(j, n)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

    Edges E;
    REP(u, n) EACH(e, g[u]) if (e->src < e->dst) E.push_back(*e);
    int m = E.size();

    Weight H = INF;
    vector<Weight> theta(m);
    REP(r, m) {
        int u = E[r].src, v = E[r].dst;
        Weight d = E[r].weight;
        REP(w, n) theta[r] = max(theta[r], min(dist[u][w], dist[v][w]));
        H = min(H, d + 2 * theta[r]);
    }
    Weight value = INF;
    REP(r, m) if (2 * theta[r] <= H) {
        int u = E[r].src, v = E[r].dst;
        Weight d = E[r].weight;
        vector< pair<Weight,Weight> > list;
        REP(w, n) list.push_back( make_pair(dist[u][w], dist[v][w]) );
        sort(ALL(list), greater< pair<Weight,Weight> >());
        int p = 0;
        value = min(value, 2 * list[0].first);
        REP(k, n) if (list[p].second < list[k].second)
            value = min(value, d + list[p].second + list[k].first), p = k;
        value = min(value, 2 * list[p].second);
    }
    return n == 1 ? 0 : value;
}
