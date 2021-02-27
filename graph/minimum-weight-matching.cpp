// adj[i][j] = w(i,j)
Weight adj[N][N];
int size, sorted[N][N], num[N];
void rec(int match[], int p, int l, Weight w, Weight &opt) {
  int q = p + 1, i;
  if (w >= opt) return;
  for (; q < size; ++q) if (match[q] == -1) break;
  int m = num[q], *list = sorted[q];
  REP(j,m) if (match[i=list[j]] == -1) { // process greedily
    match[q] = i, match[i] = q;
    w += adj[i][q];
    if (l + 1 < size / 2) rec(match, q, l+1, w, opt);
    else opt = min(opt, w);
    w -= adj[i][q];
    match[q] = -1, match[i] = -1;
  }
}
int gs;
bool compareWith(int i, int j) { return adj[gs][i] < adj[gs][j]; }
Weight minimumWeightMatching() {
  for (gs = 0; gs < size; ++gs) { // sort adjacent nodes by edge weight
    for (int j = gs+1; j < size; ++j)
      sorted[gs][num[gs]++] = j;
    sort(sorted[gs], sorted[gs]+num[gs], compareWith);
  }
  int match[size]; fill(match, match+size, -1);
  Weight opt = INF;
  rec(match, -1, 0, 0, opt);
  return opt;
}

/////////////////////////////

Weight best[1<<26];
int minimumWeightMatching() {
  fill(best, best+(1<<size), INF);
  best[0] = 0;
  for (int S = 0; S < (1<<size); ++S) {
    int i;
    for (i = 0; S & (1<<i); ++i);
    for (int j = i+1; j < size; ++j) {
      if (S & (1<<j)) continue;
      best[S + (1<<i) + (1<<j)] =
        min(best[S + (1<<i) + (1<<j)], best[S] + adj[i][j]);
    }
  }
  return best[(1<<size)-1];
}
