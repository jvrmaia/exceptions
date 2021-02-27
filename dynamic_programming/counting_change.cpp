#define MAX 100
int s, n, coins[MAX], sol[MAX];

int solve(){
    REP(i,s+1) sol[i]=INF;
    sol[0] = 0;
    for(int i=1; i<=s; i++) {
        REP(j,n){
            if(coins[j]<=i && sol[i-coins[j]]+1 < sol[i]) {
                sol[i] = sol[i-coins[j]]+1;
            }
        }
    }
    REP(i,s+1){
        printf("%d ",sol[i]);
    puts("");
    return sol[s];
}

void read() {
    scanf("%d %d",&s,&n);
    REP(i,n) scanf("%d",&coins[i]);
    printf("%d",solve());
}
