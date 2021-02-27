// encontra o menor circulo que contem todos os pontos dados
typedef pair<point,double> circle;

bool in_circle(circle C, point p){
    return cmp(abs(p-C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r){
    point a = p-r, b = q-r, c = point(a*(p+r)/2, b*(q+r)/2);
    return point(c%point(a.y,b.y), point(a.x,b.x)%c)/(a%b);
}

circle spanning_circle(vector<point> &T){
    int n = T.size();
    random_shuffle(ALL(T));
    circle C(point(),-INF);
    REP(i,n) if(!in_circle(C,T[i])){
        C = circle(T[i],0);
        REP(j,i) if(!in_circle(C,T[j])){
            C = circle((T[i]+T[j])/2, abs(T[i]-T[j])/2);
            REP(k,j) if(!in_circle(C,T[k])){
                point o = circumcenter(T[i],T[j],T[k]);
                C = circle(o,abs(o-T[k]));
            }
        }
    }
    return C;
}

