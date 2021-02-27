bool augment(vector< vector<int> > &C, int u, int c1, int c2) {
    int v = C[u][c1];
    if (v >= 0) {
        augment(C, v, c2, c1);
        C[v][c2] = u;
        C[u][c1] = -1;
    }
    C[u][c2] = v;
}
int bipartiteColouring(const Graph &g,
        int L, vector< vector<int> > &color) {
    int n = g.size(), deg = 0;
    REP(u, n) deg = max(deg, (int)g[u].size());
    vector< vector<int> > C(n, vector<int>(deg, -1));

    REP(u,L) EACH(e,g[u]) {
        int v = e->dst, cu = 0, cv = 0;
        while (C[u][cu] != -1) ++cu;
        while (C[v][cv] != -1) ++cv;
        if (cu != cv) augment(C, v, cu, cv);
        C[u][cu] = v; C[v][cu] = u;
    }
    color.assign(n, vector<int>(n)); // make explicit color-table
    REP(u, L) REP(c, deg) if (C[u][c] >= 0)
        color[u][C[u][c]] = c+1;
    return deg;
}
