// determina o fecho convexo de um conjunto de pontos no plano
// destroi a lista de pontos T
polygon convex_hull(vector<point> &T){
    int j=0, k, n=T.size(); polygon U(n);

    point::pivot = *min_element(ALL(T));
    sort(ALL(T), radial_lt);
    for(k=n-2;k>=0&&ccw(T[0],T[n-1],T[k])==0;k--);
    reverse((k+1)+ALL(T));

    REP(i,n){
        // troque o >= por > para manter pontos colineares
        while(j>1&&ccw(U[j-1],U[j-2],T[i])>=0) j--;
        U[j++]=T[i];
    }
    U.erase(j+ALL(U));
    return U;
}

