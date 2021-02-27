// Binomial - Pascal Triangle
#define DIM 80
unsigned long long C[DIM+1][DIM+1];

void run(){
    unsigned long long n,k;
    for(n=0; n<=DIM; ++n) {
        C[n][0] = C[n][n] = 1;
        for(k=1; k<n; ++k)
            C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
}
