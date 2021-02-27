void shortestPath(const Matrix &g,Matrix &dist,vector<vector<int> > &inter){
    int n = g.size();
    dist = g;
    inter.assign(n, vector<int>(n,-1));
    REP(k, n) REP(i, n) REP(j, n) {
        if (dist[i][j] < dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            inter[i][j] = k;
        }
    }
}

void buildPath(const vector<vector<int> > &inter,int s,int t,vector<int> &path){
    int u = inter[s][t];
    if (u < 0) path.push_back(s);
    else buildPath(inter, s, u, path), buildPath(inter, u, s, path);
}

vector<int> buildPath(const vector< vector<int> > &inter, int s, int t) {
    vector<int> path;
    buildPath(inter, s, t, path);
    path.push_back(t);
    return path;
}
