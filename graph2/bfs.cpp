#define MAX 100
queue<int> myStack;
int G[MAX][MAX];
int visit[MAX];
int V, E;

void bfs(int s) {
    int i, j, node;
    memset(visit, 0, sizeof(visit));
    myStack.push(s);
    while(!myStack.empty()){
        node = myStack.top();
        myStack.pop();
        if(visit[node]) continue;
        visit[node] = 1;
        cout << node << " ";

        REP(i,V)
            if(G[node][i]) myStack.push(i);
    }

}

