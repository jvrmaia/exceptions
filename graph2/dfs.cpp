#define MAX 100
queue<int> myQueue;
int G[MAX][MAX];
int visit[MAX];
int V, E;

void dfs(int s) {
    int i, j, node;
    memset(visit, 0, sizeof(visit));
    myQueue.push(s);
    while(!myQueue.empty()){
        node = myQueue.front();
        myQueue.pop();
        if(visit[node]) continue;
        visit[node] = 1;
        cout << node << " ";
        REP(i,V)
            if(G[i][node]) myQueue.push(i);
        REP(j,V)
            if(G[node][j]) myQueue.push(j);
    }

}

