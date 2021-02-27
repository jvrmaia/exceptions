void visit(const Graph & g, int v, int u,
        Edges& brdg, vector< vector<int> >& tecomp,
        stack<int>& roots, stack<int>& S, vector<bool>& inS,
        vector<int>& num, int& time) {
    num[v] = ++time;
    S.push(v); inS[v] = true;
    roots.push(v);
    EACH(e, g[v]) {
        int w = e->dst;
        if (num[w] == 0)
            visit(g, w, v, brdg, tecomp, roots, S, inS, num, time);
        else if (u != w && inS[w])
            while (num[roots.top()] > num[w]) roots.pop();
    }
    if (v == roots.top()) {
        brdg.push_back(Edge(u, v));
        tecomp.push_back(vector<int>());
        while (1) {
            int w = S.top(); S.pop(); inS[w] = false;
            tecomp.back().push_back(w);
            if (v == w) break;
        }
        roots.pop();
    }
}

void bridge(const Graph& g, Edges& brdg, vector< vector<int> >& tecomp) {
    const int n = g.size();
    vector<int> num(n);
    vector<bool> inS(n);
    stack<int> roots, S;
    int time = 0;
    REP(u, n) if (num[u] == 0) {
        visit(g, u, n, brdg, tecomp, roots, S, inS, num, time);
        brdg.pop_back();
    }
}
