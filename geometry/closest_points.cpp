bool compy(point a, point b){
    return cmp(a.y,b.y) ? cmp(a.y,b.y) < 0 : cmp(a.x,b.x) < 0;
}

pair<point, point> closest_points_rec(vector<point>& px, vector<point>& py) {
    pair<point, point> ret;
    double d;

    if(px.size() <= 3) {
        double best = 1e10;
        for(int i = 0; i < px.size(); ++i)
            for(int j = i + 1; j < px.size(); ++j)
                if(dist(px[i], px[j]) < best) {
                    ret = make_pair(px[i], px[j]);
                    best = dist(px[i], px[j]);
                }

        return ret;
    }

    point split = px[(px.size() - 1)/2];
    vector<point> qx, qy, rx, ry;
    for(int i = 0; i < px.size(); ++i)
        if(px[i] <= split) qx.push_back(px[i]);
        else rx.push_back(px[i]);

    for(int i = 0; i < py.size(); ++i)
        if(py[i] <= split) qy.push_back(py[i]);
        else ry.push_back(py[i]);

    ret = closest_points_rec(qx, qy);
    pair<point, point> rans = closest_points_rec(rx, ry);
    double delta = dist(ret.first, ret.second);

    if((d = dist(rans.first, rans.second)) < delta) {
        delta = d;
        ret = rans;
    }

    vector<point> s;
    for(int i = 0; i < py.size(); ++i)
        if(cmp(abs(py[i].x - split.x), delta) <= 0)
            s.push_back(py[i]);

    for(int i = 0; i < s.size(); ++i)
        for(int j = 1; j <= 7 && i + j < s.size(); ++j)
            if((d = dist(s[i], s[i+j])) < delta) {
                delta = d;
                ret = make_pair(s[i], s[i+j]);
            }

    return ret;
}

pair<point, point> closest_points(vector<point> pts) {
    if(pts.size() == 1) return make_pair(point(-INF, -INF), point(INF, INF));

    sort(pts.begin(), pts.end());
    for(int i = 0; i + 1 < pts.size(); ++i)
        if(pts[i] == pts[i+1])
            return make_pair(pts[i], pts[i+1]);

    vector<point> py = pts;
    sort(py.begin(), py.end(), compy);
    return closest_points_rec(pts, py);
}
