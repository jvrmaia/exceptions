typedef unsigned int ui;

template<class T> ui edit_distance(const T& s1, const T& s2){
    const size_t len1 = s1.size(), len2 = s2.size();
    vector<vector<ui> > d(len1 + 1, vector<ui>(len2 + 1));

    d[0][0] = 0;
    for(ui i = 1; i <= len1; ++i) d[i][0] = i;
    for(ui i = 1; i <= len2; ++i) d[0][i] = i;

    for(ui i = 1; i <= len1; ++i)
        for(ui j = 1; j <= len2; ++j)
            d[i][j] = min( min(d[i-1][j]+1,d[i][j-1]+1),
                    d[i-1][j-1]+(s1[i-1]==s2[j-1] ? 0 : 1) );
    return d[len1][len2];
}
