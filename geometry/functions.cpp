// decide se q esta sobre o segmento fechado pr
bool between(point p, point q, point r){
    return ccw(p,q,r) == 0 && cmp((p-q)*(r-q)) <= 0;
}

// calcula a distancia do ponto r ao segmento pq
double seg_distance(point p, point q, point r){
    point A = r-q, B=r-p, C=q-p;
    double a = A*A, b = B*B, c = C*C;
    if(cmp(b,a+c)>=0) return sqrt(a);
    else if(cmp(a,b+c)>=0) return sqrt(b);
    else return fabs(A%B)/sqrt(c);
}

// classifica o ponto p em relacao ao poligono T
// return: 0 - p esta no exterior
//        -1 - p esta na fronteira
//         1 - p esta no interior
int in_poly(point p, polygon &T){
    double a=0; int N = T.size();
    REP(i,N){
        if(between(T[i],p,T[(i+1)%N])) return -1;
        a += angle(T[i],p,T[(i+1)%N]);
    }
    return cmp(a)!=0;
}

// comparacao radial
bool radial_lt(point p, point q){
    point P = p-point::pivot, Q = q-point::pivot;
    double R = P%Q;
    if(cmp(R)) return R>0;
    return cmp(P*P,Q*Q)<0;
}

// calcula a area orientado do poligono T
// T deve estar orientado positivamente
double poly_area(polygon &T){
    double s=0; int n=T.size();
    REP(i,n){
        s += T[i]%T[(i+1)%n];
    }
    return s/2;
}

// encontra o ponto de intersecao das retas pq e rs
point line_intersect(point p, point q, point r, point s){
    point a = q-p, b = s-r, c = point(p%q,r%s);
    return point(point(a.x,b.x)%c, point(a.y,b.y)%c)/(a%b);
}

