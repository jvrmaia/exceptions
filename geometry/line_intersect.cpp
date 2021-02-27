// decide se os segmentos fechados pq e rs tem pontos em comum
bool seg_intersect(point p, point q, point r, point s){
    point A = q-p, B = s-r, C = r-p, D=s-q;
    int a = cmp(A%C)+2*cmp(A%D);
    int b = cmp(B%C)+2*cmp(B%D);
    if(a==3||a==-3||b==3||b==-3) return false;
    int t=(p<r)+(p<s)+(q<r)+(q<s);
    return t!=0 && t!=4;
}

