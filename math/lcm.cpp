// Least common multiple
//   requisits: gcd
inline int lcm(int a, int b){
    if(a<0) return lcm(-a,b);
    if(b<0) return lcm(a,-b);
    return a*(b/gcd(a,b));
}
