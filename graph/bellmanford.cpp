bool shortestPath(const Graph g,int s,vector<Weight> &dist,vector<int> &prev){
    int n = g.size();
    dist.assign(n, INF+INF); dist[s] = 0;
    prev.assign(n, -2);
    bool negative_cycle = false;
    REP(k, n) REP(i, n) EACH(e,g[i]) {
        if (dist[e->dst] > dist[e->src] + e->weight) {
            dist[e->dst] = dist[e->src] + e->weight;
            prev[e->dst] = e->src;
            if (k == n-1) {
                dist[e->dst] = -INF;
                negative_cycle = true;
            }
        }
    }
    return !negative_cycle;
}

vector<int> buildPath(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}
