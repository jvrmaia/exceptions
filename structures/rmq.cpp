// Given an array A[0, N-1] find the position of
// the element with the minimum value between two given indices.
// RMQ(2,7)=3
// a[0] | a[1] | a[2] | a[3] | a[4] | a[5] | a[6] | a[7] | a[8] | a[9]
// 2    | 4    | 3    | 1    | 6    | 7    | 8    | 9    | 1    | 7
int *buildRMQ(int *a, int n) {
    int logn = 1;
    for (int k = 1; k < n; k *= 2) ++logn;
    int *r = new int[n * logn];
    int *b = r; copy(a, a+n, b);
    for (int k = 1; k < n; k *= 2) {
        copy(b, b+n, b+n); b += n;
        REP(i, n-k) b[i] = min(b[i], b[i+k]);
    }
    return r;
}

int minimum(int x, int y, int *rmq, int n) {
    int z = y - x, k = 0, e = 1, s; // y - x >= e = 2^k
    s = ( (z & 0xffff0000) != 0 ) << 4; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x0000ff00) != 0 ) << 3; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x000000f0) != 0 ) << 2; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x0000000c) != 0 ) << 1; z >>= s; e <<= s; k |= s;
    s = ( (z & 0x00000002) != 0 ) << 0; z >>= s; e <<= s; k |= s;
    return min( rmq[x+n*k], rmq[y+n*k-e+1] );
}
