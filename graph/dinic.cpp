#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])

Weight augment(const Graph &g, const Matrix &capacity, Matrix &flow,
               const vector<int> &level, vector<bool> &finished, 
               int u, int t, Weight cur) {
    if (u == t || cur == 0) return cur;
    if (finished[u]) return 0;
    finished[u] = true;
    EACH(e, g[u]) if (level[e->dst] > level[u]) {
        Weight f = augment(g, capacity, flow, level, finished,
                e->dst, t, min(cur, RESIDUE(u, e->dst)));
        if (f > 0) {
            flow[u][e->dst] += f; flow[e->dst][u] -= f;
            finished[u] = false;
            return f;
        }
    }
    return 0;
}

Weight maximumFlow(const Graph &g, int s, int t) {
    int n = g.size();
    Matrix flow(n, Array(n)), capacity(n, Array(n)); // adj. matrix
    REP(u,n) EACH(e,g[u]) capacity[e->src][e->dst] += e->weight;

    Weight total = 0;
    for (bool cont = true; cont; ) {
        cont = false;
        vector<int> level(n, -1); level[s] = 0; // make layered network
        queue<int> Q; Q.push(s);
        for (int d = n; !Q.empty() && level[Q.front()] < d; ) {
            int u = Q.front(); Q.pop();
            if (u == t) d = level[u];
            EACH(e, g[u]) if (RESIDUE(u,e->dst) > 0 && level[e->dst] == -1)
                Q.push(e->dst), level[e->dst] = level[u] + 1;
        }
        vector<bool> finished(n); // make blocking flows
        for (Weight f = 1; f > 0; ) {
            f = augment(g, capacity, flow, level, finished, s, t, INF);
            if (f == 0) break;
            total += f; cont = true;
        }
    }
    return total;
}
