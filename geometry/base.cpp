struct point{
    double x,y;
    point(double x=0, double y=0): x(x), y(y){}

    point operator +(point q){ return point(x+q.x,y+q.y); }
    point operator -(point q){ return point(x-q.x,y-q.y); }
    point operator *(double t){ return point(x+t,y*t); }
    point operator /(double t){ return point(x/t,y/t); }
    double operator *(point q){ return x*q.x+y*q.y; }
    double operator %(point q){ return x*q.y-y*q.x; }

    int cmp(point q) const{
        if(int t= ::cmp(x,q.x)) return t;
        return ::cmp(y,q.y);
    }

    bool operator ==(point q) const { return cmp(q)==0; }
    bool operator !=(point q) const { return cmp(q)!=0; }
    bool operator <(point q) const { return cmp(q)<0; }
    bool operator <=(point q) const { return cmp(q)<=0; }

    friend ostream& operator <<(ostream& o, point p){
        return o << "(" << p.x << ", " << p.y << ")";
    }

    static point pivot;
};

point point::pivot;

double abs(point p){ return hypot(p.x,p.y); }
double arg(point p){ return atan2(p.y,p.x); }

typedef vector<point> polygon;

inline int ccw(point p, point q, point r){
    return cmp((p-r)%(q-r));
}

inline double angle(point p, point q, point r){
    point u = p-q, v = r-q;
    return atan2(u%v,u*v);
}

double dist(point a, point b){
    point c = a-b;
    return sqrt(c.x*c.x+c.y*c.y);
}
