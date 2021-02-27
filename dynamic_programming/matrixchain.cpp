// matrix chain
int matrix_chain(vector<int>& p, vector< vector<int> >& s) {
    const int n = p.size()-1;
    vector< vector<int> > X(n, vector<int>(n, inf));
    s.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) X[i][i] = 0;
    for (int w = 1; w < n; ++w)
        for (int i = 0, j; j = i+w, j < n; ++i)
            for (int k = i, f; k < j; ++k) {
                int f = p[i]*p[k+1]*p[j+1];
                if (X[i][k] + X[k+1][j] + f < X[i][j]) {
                    X[i][j] = X[i][k] + X[k+1][j] + f;
                    s[i][j] = k;
                }
            }
    return X[0][n-1];
}
