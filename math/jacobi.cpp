// Jacobi Symbol (m/n),
//   For any m integer and n positive odd integer:
//   (m/n) = (m/p_1)^e_1 * ... * (m/p_k)^e_k
//  where n = p_1^e_1 * ... * p_k^e_k
//   (m/n) returns:
//   * 0 if a == 0(mod p)
//   * 1 if a != 0(mod p) and for some integer x, a == x^2 (mod p)
//   * -1 if there is no such x
#define NEGPOW(e) ((e) % 2 ? -1 : 1)
int jacobi(int a, int m){
    if(a==0) return m == 1 ? 1 : 0;
    if(a%2)  return NEGPOW((a-1)*(m-1)/4)*jacobi(m%a, a);
    else     return NEGPOW((m*m-1)/8)*jacobi(a/2, m);
}
