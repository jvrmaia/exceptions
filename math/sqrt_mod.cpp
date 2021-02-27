// Quadratic residue
//   requisits: invMod, powMod and jacobi
//   x^2 == a (mod p)
int sqrtMod(int n, int p) {
    int S, Q, W, i, m = invMod(n, p);
    for(Q=p-1,S=0;Q%2==0;Q/=2,++S);
    do{ W=rand()%p; } while(W== 0||jacobi(W,p)!=-1);
    for(int R = powMod(n,(Q+1)/2,p), V=powMod(W,Q,p);;){
        int z=R*R*m%p;
        for(i=0;i<S&&z%p!=1;z*=z,++i);
        if(i==0) return R;
        R=(R*powMod(V,1<<(S-i-1),p))%p;
    }
}
