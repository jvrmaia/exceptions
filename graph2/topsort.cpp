#define MAX 100

int graph[MAX][MAX];

int indegree[MAX];  //Indegree of each vertex
int sorted[MAX];
int V, E;

void computeInDegrees() {
    memset(indegree, 0, sizeof(indegree));
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            if(graph[j][i])
                indegree[i]++;
}

void topsort() {
    queue<int> zeroin;   //Vertices of indegree 0
    int current, next;   //Current and next vertex

    computeInDegrees();

    for(int i=0; i<V; i++)
        if(indegree[i] == 0)
            zeroin.push(i);

    int j=0;
    while(!zeroin.empty()) {
        current = zeroin.front();
        zeroin.pop();
        sorted[j] = current;
        for(int i=0; i<V; i++) {
            cout << current << " " << i << " " << graph[current][i] << endl;
            if(graph[current][i]) {
                next = i;
                indegree[next]--;
                if(indegree[next] == 0) {
                    zeroin.push(next);
                }
            }
        }
        j += 1;
    }

    if( j != V) {
        cout << "Not a DAG -- only " << j << " vertices found" << endl;
        for(int i=0; i<V; i++)
            cout << sorted[i] << " ";
        cout << endl;
    }
    else {
        for(int i=0; i<V; i++)
            cout << sorted[i] << " ";
        cout << endl;
    }
}

void read()
{
    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
}
