struct UndirectionalCompare {
    bool operator() (const Edge& e, const Edge& f) const {
        if (min(e.src,e.dst) != min(f.src,f.dst))
            return min(e.src,e.dst) < min(f.src,f.dst);
        return max(e.src,e.dst) < max(f.src,f.dst);
    }
};
typedef set<Edge, UndirectionalCompare> Edgeset;
void visit(const Graph &g, int v, int u,
        vector<int>& art, vector<Edgeset>& bcomp,
        stack<Edge>& S, vector<int>& num, vector<int>& low, int& time) {
    low[v] = num[v] = ++time;
    EACH(e, g[v]) {
        int w = e->dst;
        if (num[w] < num[v]) S.push(*e);              // for bcomps
        if (num[w] == 0) {
            visit(g, w, v, art, bcomp, S, num, low, time);
            low[v] = min(low[v], low[w]);
            if ((num[v] == 1 && num[w] != 2) ||         // for arts
                    (num[v] != 1 && low[w] >= num[v])) art.push_back(v);
            if (low[w] >= num[v]) {                     // for bcomps
                bcomp.push_back(Edgeset());
                while (1) {
                    Edge f = S.top(); S.pop();
                    bcomp.back().insert(f);
                    if (f.src == v && f.dst == w) break;
                }
            }
        } else low[v] = min(low[v], num[w]);
    }
}
void articulationPoint(const Graph& g,
        vector<int>& art, vector<Edgeset>& bcomp) {
    const int n = g.size();
    vector<int> low(n), num(n);
    stack<Edge> S;
    REP(u, n) if (num[u] == 0) {
        int time = 0;
        visit(g, u, -1, art, bcomp, S, num, low, time);
    }
}
