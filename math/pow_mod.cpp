// powMod
//   x^k (mod n)
int powMod(int x, int k, int m){
    if(k==0)   return 1;
    if(k%2==0) return powMod(x*x%m,k/2,m);
    else       return x*powMod(x,k-1,m)%m;
}
