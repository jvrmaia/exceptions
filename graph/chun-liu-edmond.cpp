void visit(Graph &h, int v, int s, int r,
        vector<int> &no, vector< vector<int> > &comp,
        vector<int> &prev, vector< vector<int> > &next, vector<Weight> &mcost,
        vector<int> &mark, Weight &cost, bool &found) {
    const int n = h.size();
    if (mark[v]) {
        vector<int> temp = no;
        found = true;
        do {
            cost += mcost[v];
            v = prev[v];
            if (v != s) {
                while (comp[v].size() > 0) {
                    no[comp[v].back()] = s;
                    comp[s].push_back(comp[v].back());
                    comp[v].pop_back();
                }
            }
        } while (v != s);
        EACH(j,comp[s]) if (*j != r) EACH(e,h[*j])
            if (no[e->src] != s) e->weight -= mcost[ temp[*j] ];
    }
    mark[v] = true;
    EACH(i,next[v]) if (no[*i] != no[v] && prev[no[*i]] == v)
        if (!mark[no[*i]] || *i == s)
            visit(h, *i, s, r, no, comp, prev, next, mcost, mark, cost, found);
}
Weight minimumSpanningArborescence(const Graph &g, int r) {
    const int n = g.size();
    Graph h(n);
    REP(u,n) EACH(e,g[u]) h[e->dst].push_back(*e);

    vector<int> no(n);
    vector< vector<int> > comp(n);
    REP(u, n) comp[u].push_back(no[u] = u);

    for (Weight cost = 0; ;) {
        vector<int> prev(n, -1);
        vector<Weight> mcost(n, INF);

        REP(j,n) if (j != r) EACH(e,g[j])
            if (no[e->src] != no[j])
                if (e->weight < mcost[ no[j] ])
                    mcost[ no[j] ] = e->weight, prev[ no[j] ] = no[e->src];

        vector< vector<int> > next(n);
        REP(u,n) if (prev[u] >= 0)
            next[ prev[u] ].push_back(u);

        bool stop = true;
        vector<int> mark(n);
        REP(u,n) if (u != r && !mark[u] && !comp[u].empty()) {
            bool found = false;
            visit(h, u, u, r, no, comp, prev, next, mcost, mark, cost, found);
            if (found) stop = false;
        }
        if (stop) {
            REP(u,n) if (prev[u] >= 0) cost += mcost[u];
            return cost;
        }
    }
}


///////////////////////////////////////////////////////////////////

void backward_traverse(int v, int s, int r, matrix &g,
        vector<int> &no, vector< vector<int> > &comp,
        vector<int> &prev, vector<weight> &mcost,
        vector<int> &mark, weight &cost, bool &found) {
    const int n = g.size();
    if (mark[v]) {
        vector<int> temp = no;
        found = true;
        do {
            cost += mcost[v];
            v = prev[v];
            if (v != s) {
                while (comp[v].size() > 0) {
                    no[comp[v].back()] = s;
                    comp[s].push_back(comp[v].back());
                    comp[v].pop_back();
                }
            }
        } while (v != s);
        for (int j = 0; j < n; ++j)
            if (j != r && no[j] == s)
                for (int i = 0; i < n; ++i)
                    if (no[i] != s && g[i][j] < inf)
                        g[i][j] -= mcost[ temp[j] ];
    }
    mark[v] = true;
    for (int i = 0; i < n; ++i)
        if (no[i] != no[v] && prev[ no[i] ] == v)
            if (!mark[ no[i] ] || i == s)
                backward_traverse(i, s, r, g,
                        no, comp, prev, mcost, mark, cost, found);
}

weight minimum_spanning_arborescence(int r, matrix &g) {
    const int n = g.size();

    vector<int> no(n);
    vector< vector<int> > comp(n);
    for (int i = 0; i < n; ++i) {
        no[i] = i;
        comp[i].push_back(i);
    }
    weight cost = 0;
    while (1) {
        vector<int> prev(n, -1);
        vector<weight> mcost(n, inf);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == r) continue;
                if (no[i] != no[j] && g[i][j] < inf) {
                    if (g[i][j] < mcost[ no[j] ]) {
                        mcost[ no[j] ] = g[i][j];
                        prev[ no[j] ] = no[i];
                    }
                }
            }
        }
        bool stop = true;
        vector<int> mark(n);
        for (int i = 0; i < n; ++i) {
            if (i == r || mark[i] || comp[i].size() == 0) continue;
            bool found = false;
            backward_traverse(i, i, r, g,
                    no, comp, prev, mcost, mark, cost, found);
            if (found) stop = false;
        }
        if (stop) {
            for (int i = 0; i < n; ++i)
                if (prev[i] >= 0)
                    cost += mcost[i];
            return cost;
        }
    }
}
