struct Query {
    int u, v, w;
    Query(int u, int v) : u(u), v(v), w(-1) { }
};

void visit(const Graph &g, int u, int w,
        vector<Query> &qs, vector<int> &color,
        vector<int> &ancestor, UnionFind &uf) {
    ancestor[ uf.root(u) ] = u;
    EACH(e, g[u]) if (e->dst != w) {
        visit(g, e->dst, u, qs, color, ancestor, uf);
        uf.unionSet( e->src, e->dst );
        ancestor[ uf.root(u) ] = u;
    }
    color[u] = 1;
    EACH(q, qs) {
        int w = (q->v == u ? q->u : q->u == u ? q->v : -1);
        if (w >= 0 && color[w]) q->w = ancestor[ uf.root(w) ];
    }
}

void leastCommonAncestor(const Graph &g, int r, vector<Query> &qs) {
    UnionFind uf(g.size());
    vector<int> color(g.size()), ancestor(g.size());
    visit(g, r, -1, qs, color, ancestor, uf);
}
