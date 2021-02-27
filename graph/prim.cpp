pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
    int n = g.size();
    Edges T;
    Weight total = 0;

    vector<bool> visited(n);
    priority_queue<Edge> Q;
    Q.push( Edge(-1, r, 0) );
    while (!Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (visited[e.dst]) continue;
        T.push_back(e);
        total += e.weight;
        visited[e.dst] = true;
        EACH(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
    }
    return pair<Weight, Edges>(total, T);
}
