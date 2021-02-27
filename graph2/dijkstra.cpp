#define MAXINT (int)(pow(2,31)-1)
#define MAX 100

int G[MAX][MAX];
int total;

int dist[MAX];
int father[MAX];
bool visit[MAX];

void dijkstra(int start){
    priority_queue<pair<int,int> > queue;
    pair <int,int> nodotmp;
    int i, j;

    for (int i=1; i<=total; i++) {
        dist[i] = MAXINT;
        father[i] = -1;
        visit[i] = false;
    }

    dist[start] = 0;
    queue.push(pair <int,int> (dist[start], start));

    while(!queue.empty()) {
        nodotmp = queue.top();
        queue.pop();
        i = nodotmp.second;
        if (!visit[i]) {
            visit[i] = true;
            for (j = 1; j<=total; j++)
                if (!visit[j] && G[i][j] > 0 && dist[i] + G[i][j] < dist[j]) {
                    dist[j] = dist[i] + G[i][j];
                    father[j] = i;
                    queue.push(pair <int,int>(-dist[j], j));
                }
        }
    }
}


void getPath(int end) {
    cout << end << " ";
    while (father[end]!= -1) {
        cout << father[end] << " ";
        end = father[end];
    }
    cout << endl;
}

int main()
{
    int a, b, c;
    int tedges;
    memset(G, 0, sizeof(G));
    cin >> total >> tedges;
    for (int i=0; i<tedges; i++) {
        cin >> a >> b >> c;
        G[a][b] = c;
    }
    for(int i=1; i<=total; i++) {
        for(int j=1; j<=total; j++)
            printf("%d ", G[i][j]);
        printf("\n");
    }
    dijkstra(1);
    getPath(3);
    return 0;
}
