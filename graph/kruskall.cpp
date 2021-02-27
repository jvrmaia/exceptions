pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
    int n = g.size();
    UnionFind uf(n);
    priority_queue<Edge> Q;
    REP(u, n) EACH(e, g[u]) if (u < e->dst) Q.push(*e);

    Weight total = 0;
    Edges F;
    while (F.size() < n-1 && !Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (uf.unionSet(e.src, e.dst)) {
            F.push_back(e);
            total += e.weight;
        }
    }
    return pair<Weight, Edges>(total, F);
}
