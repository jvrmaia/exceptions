#define MAX 100

int graph[MAX][MAX];
int n;                  //Number of vertices
int color[MAX];

int colorea(int v, int nc) {
    int res, i, j, c;
    if(v == n)   return 1;
    for(c = 0; c<nc; c++) {
        for(i=0; i<n; i++) 
            if(graph[v][i] && color[i] == c) break;
        if(i==n) {
            color[v] = c;
            if(colorea(v+1, nc)) return 1;
        }
    }
}

int main() {
    int nc = 4;
    memset(color, 255, sizeof(color));
    colorea(0, nc);
    return 0;
}

