/*****************
 * Lex k-subsets *
 *****************
 * Given a set of n elements, prints all subsets of size k in
 * lexicographic order. Each one is displayed as a string of
 * 0's and 1's. For example, when n = 4, k = 2, the
 * routine prints
 *      0011
 *      0101
 *      0110
 *      1001
 *      1010
 *      1100
 * COMPLEXITY: O(n*2^n)
 **/
void lexKSubsets( int n, int k )
{
    for( int i = 0; i < ( 1 << n ); i++ )
    {
        int bits = 0;
        for( int j = 0; j < n; j++ ) if( i & ( 1 << j ) ) bits++;
        if( bits != k ) continue;
        for( int j = n - 1; j >= 0; j-- )
            printf( "%c", ( ( i & ( 1 << j ) ) ? '1' : '0' ) );
        printf( "\n" );
    }
}

