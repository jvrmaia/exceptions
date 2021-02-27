// Mobius
//   - mobiusMu(n) = 1 if n is a square-free positive integer
//                 with an even number of prime factors.
//   - mobiusMu(n) = -1 if n is square-free positive integer
//                 with an odd number of prime factors.
//   - mobiusMu(n) = 0 if n is not square-free.
//   square-free: integer is one divisible by no perfect square, except 1.
//   example: 10 is square-free but 18 is not, as it is divisible by 9 = 3^2
int N = 20000000000;
int mobiusMu(int n){
    static int lookup = 0, p[N], f[N];
    if(!lookup){
        REP(i,N) p[i]=1, f[i]=1;
        for(int i=2;i<N;++i) {
            if(p[i]){
                f[i]=-1;
                for(int j=i+i;j<N;j+=i){
                    p[j]=0;
                    f[j]*=(j%(i*i)==0) ? 0 : -1;
                }
            }
        }
        lookup=1;
    }
    return f[n];
}
