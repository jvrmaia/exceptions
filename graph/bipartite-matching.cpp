bool augment(const Graph& g, int u,
        vector<int>& matchTo, vector<bool>& visited) {
    if (u < 0) return true;
    EACH(e, g[u]) if (!visited[e->dst]) {
        visited[e->dst] = true;
        if (augment(g, matchTo[e->dst], matchTo, visited)) {
            matchTo[e->src] = e->dst;
            matchTo[e->dst] = e->src;
            return true;
        }
    }
    return false;
}
int bipartiteMatching(const Graph& g, int L, Edges& matching) {
    const int n = g.size();
    vector<int> matchTo(n, -1);
    int match = 0;
    REP(u, L) {
        vector<bool> visited(n);
        if (augment(g, u, matchTo, visited)) ++match;
    }
    REP(u, L) if (matchTo[u] >= 0) // make explicit matching
        matching.push_back( Edge(u, matchTo[u]) );
    return match;
}
