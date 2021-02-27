void shortestPath(const Graph &g,int s,vector<Weight> &dist,vector<int> &prev){
    int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q; 
    for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
        Edge e = Q.front(); Q.pop();
        if (prev[e.dst] != -1) continue;
        prev[e.dst] = e.src;
        EACH(f,g[e.dst]) {
            if (dist[f->dst] > e.weight+f->weight) {
                dist[f->dst] = e.weight+f->weight;
                Q.push(Edge(f->src, f->dst, e.weight+f->weight));
            }
        }
    }
}

vector<int> buildPath(const vector<int> &prev, int t) {
    vector<int> path;
    for (int u = t; u >= 0; u = prev[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}
