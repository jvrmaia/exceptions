// longest common sequence
vector<int> lcs(const vector<int>& a, const vector<int>& b) {
    const int n = a.size(), m = b.size();
    vector< vector<int> > X(n+1, vector<int>(m+1));
    vector< vector<int> > Y(n+1, vector<int>(m+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                X[i+1][j+1] = X[i][j] + 1;
                Y[i+1][j+1] = 0;
            } else if (X[i+1][j] < X[i][j+1]) {
                X[i+1][j+1] = X[i][j+1];
                Y[i+1][j+1] = +1;
            } else {
                X[i+1][j+1] = X[i+1][j];
                Y[i+1][j+1] = -1;
            }
        }
    }
    vector<int> c;
    for (int i = n, j = m; i > 0 && j > 0; ) {
        if      (Y[i][j] > 0) --i;
        else if (Y[i][j] < 0) --j;
        else { c.push_back(a[i-1]); --i; --j; }
    }
    reverse(c.begin(), c.end());
    return c;
}
