bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
    color[v] = 1;
    EACH(e, g[v]) {
        if (color[e->dst] == 2) continue;
        if (color[e->dst] == 1) return false;
        if (!visit(g, e->dst, order, color)) return false;
    }
    order.push_back(v); color[v] = 2;
    return true;
}
bool topologicalSort(const Graph &g, vector<int> &order) {
    int n = g.size();
    vector<int> color(n);
    REP(u, n) if (!color[u] && !visit(g, u, order, color))
        return false;
    reverse(ALL(order));
    return true;
}
