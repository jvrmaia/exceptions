// Euler Phi
//   eulerPhi(n) returns the number
//   of co-primes smaller than n
int eulerPhi(int n){
    if(n==0) return 0;
    int ans=n;
    for(int x=2;x*x<=n;++x){
        if(n%x==0){
            ans-=ans/x;
            while(n%x==0) n/=x;
        }
    }
    if(n>1) ans-=ans/n;
    return ans;
}
