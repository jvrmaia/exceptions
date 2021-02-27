void visit(const Graph &g, vector<vector<int> > &adj,int s,vector<int> &path){
    EACH(e, g[s]) if (adj[e->src][e->dst]) {
        --adj[e->src][e->dst];
        --adj[e->dst][e->src];
        visit(g, adj, e->dst, path);
    }
    path.push_back(s);
}
bool eulerPath(const Graph &g, int s, vector<int> &path) {
    int n = g.size();
    int odd = 0, m = 0;
    REP(i, n) {
        if (g[i].size() % 2 == 1) ++odd;
        m += g[i].size();
    }
    m /= 2;
    if (odd == 0 || (odd == 2 && g[s].size() % 2 == 0)) {
        vector< vector<int> > adj(n, vector<int>(n));
        REP(u, n) EACH(e, g[u]) ++adj[e->src][e->dst];
        path.clear();
        visit(g, adj, s, path);
        reverse(ALL(path));
        return path.size() == m + 1;
    }
    return false;
}
