#define MAX 100
int G[MAX][MAX];
int prev[MAX];
int V, E;

void floyd(){
    REP(i,V+1)
        REP(j,V+1)
        if(G[j][i])
            for(int k=1; k<=V; k++)
                if(G[i][k] > 0)
                    if(!G[j][k] || (G[j][i] + G[i][k] < G[j][k])) {
                        G[j][k] = G[j][i] + G[i][k];
                        prev[j][k] = prev[i][k];
                    }
}

void print_path (int i, int j) {
    if (i!=j)
        print_path(i,p[i][j]);
    cout << j << " ";
}

