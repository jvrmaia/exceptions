const int M = 20;
Weight best[1<<M][M];
int    prev[1<<M][M];

void buildPath(int S, int i, vector<int> &path) {
    if (!S) return;
    buildPath(S^(1<<i), prev[S][i], path);
    path.push_back(i);
}

Weight shortestHamiltonPath(Matrix w, int s, vector<int> &path) {
    int N = 1 << n;
    REP(S,N) REP(i,n) best[S][i] = INF;
    best[1<<s][s] = 0;
    REP(S,N) REP(i,n) if (S&(1<<i)) REP(j,n)
        if (best[S|(1<<j)][j] > best[S][i] + w[i][j])
            best[S|(1<<j)][j] = best[S][i] + w[i][j],
                prev[S|(1<<j)][j] = i;
    int t = min_element(best[N-1], best[N-1]+n) - best[N-1];
    path.clear(); buildPath(N-1, t, path);
    return best[N-1][t];
}
