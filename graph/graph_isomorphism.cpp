typedef vector< vector<int> > Matrix;

typedef pair<int, int> VertexInfo;
#define index second
#define degree first
bool permTest(int k, const Matrix &g, const Matrix &h,
    vector<VertexInfo> &gs, vector<VertexInfo> &hs) {
  const int n = g.size();
  if (k >= n) return true;
  for (int i = k; i < n && hs[i].degree == gs[k].degree; ++i) {
    swap(hs[i], hs[k]);
    int u = gs[k].index, v = hs[k].index;
    for (int j = 0; j <= k; ++j) {
      if (g[u][gs[j].index] != h[v][hs[j].index]) goto esc;
      if (g[gs[j].index][u] != h[hs[j].index][v]) goto esc;
    }
    if (permTest(k+1, g, h, gs, hs)) return true;
esc:swap(hs[i], hs[k]);
  }
  return false;
}
bool isomorphism(const Matrix &g, const Matrix &h) {
  const int n = g.size();
  if (h.size() != n) return false;
  vector<VertexInfo> gs(n), hs(n);
  REP(i, n) {
    gs[i].index = hs[i].index = i;
    REP(j, n) {
      gs[i].degree += g[i][j];
      hs[j].degree += h[i][j];
    }
  }
  sort(ALL(gs)); sort(ALL(hs));
  REP(i, n) if (gs[i].degree != hs[i].degree) return false;

  return permTest(0, g, h, gs, hs);
}
