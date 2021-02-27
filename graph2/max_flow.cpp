#define MAX 100

int graph[MAX][MAX];
int queue[MAX];
int head, tail;
int parent[MAX];
int V, E;
int s, t, fTotal;
int F[MAX][MAX];

//Breadth First Search
bool reachable(int s, int t) {
    bool found = false;
    int vq;
    head = tail = 0;
    memset(parent, 255, sizeof(parent));
    queue[tail++] = s;
    parent[s] = s;

    while(head < tail && !found) {
        vq = queue[head++];
        for(int i=0; i<V; i++) {
            //Parents also made the function as visit vector
            if(graph[vq][i] && parent[i] == -1) {
                queue[tail++] = i;
                parent[i] = vq;

                if(i == t) {
                    found = true;
                    break;
                }
            }
        }
    }
    return found;
}

void maxflow() {
    int vj, min;
    fTotal = 0;
    while(reachable(s, t)) {
        //Gets the minimum possible capacity in edges of the path s to t
        min = graph[parent[t]][t];
        vj = t;
        while(parent[vj] != vj) {
            if(graph[parent[vj]][vj] < min)
                min = graph[parent[vj]][vj];
            vj = parent[vj];
        }

        vj = t;
        while(parent[vj] != vj) {
            graph[parent[vj]][vj] -= min;
            graph[vj][parent[vj]] += min;
            F[parent[vj]][vj] += min;
            vj = parent[vj];
        }
        fTotal += min;
    }
}

bool read() {
    cin >> V >> E >> s >> t;
    if(!V && !E) return false;
    memset(graph, 0, sizeof(graph));
    //memset(parent, -1, sizeof(parent));
    memset(queue, 0, sizeof(queue));
    memset(F, 0, sizeof(F));


    int v1, v2, val;
    for(int i=0; i<E; i++) {
        cin >> v1 >> v2 >> val;
        graph[v1][v2] = val;
    }
    return true;
}

