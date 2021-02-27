// Greatest common divisor
//   if gcd(a,b) then a and b are coprime
inline int gcd(int a, int b){
    if(a<0) return gcd(-a,b);
    if(b<0) return gcd(a,-b);
    return (b==0) ? a : gcd(b,a%b);
}
