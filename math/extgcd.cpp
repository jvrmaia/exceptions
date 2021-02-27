// Extended Euclidean algorithm
//   Find x and y that solve:
//   a*x + b*y = gcd(a,b)
int extgcd(int a, int b, int &x, int &y) {
    int g = a; x = 1; y = 0;
    if(b!=0) g=extgcd(b,a%b,y,x), y-=(a/b)*x;
    return g;
}
