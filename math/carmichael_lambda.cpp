// Carmichael Lambda
//   requisits: lcm
//   Given n, returns a^m == 1(mod n)
//   Lamda(p^k) = p^{k-1} (p - 1) (p >= 3 or k <= 2)
//   Lamda(2^k) = 2^{k-2} (k > 2)
//   Lamda(p1^k1 ... pn^kn) = lcm(Lamda(p1^k1), ..., Lamda(pn^kn))
int carmichaelLambda(int n){
    int ans = 1;
    if(n%8==0) n/=2;
    for(int d=2;d<=n;++d){
        if(n%d==0){
            int y=d-1;
            n/=d;
            while(n%d==0) n/=d, y*=d;
            ans = lcm(ans,y);
        }
    }
    return ans;
}
