#define MAX 100

int graph[MAX][MAX];
int visit[MAX];
int V, E;

int orden[MAX];
int component[MAX];
int T;
int componentId;

void dfs(int v) {
   visit[v] = 1;
   for(int i=0; i<V; i++) 
      if(graph[v][i] && !visit[i])
         dfs(i);
   orden[T--] = v;
}

void dfsInverse(int v, int componentId) {
   visit[v] = 1;
   component[v] = componentId;
   for(int i=0; i<V; i++) 
      if(graph[i][v] && !visit[i])
         dfsInverse(i, componentId);
}

void findStronglyConnectedComponents() {
   T = V-1;
   for(int i=0; i<V; i++)
      if(!visit[i])
         dfs(i);
   memset(visit,0, sizeof(visit));
   componentId = 0;
   for(int i=0; i<V; i++) 
      if(!visit[orden[i]])
         dfsInverse(orden[i], componentId++);
}

bool read() {
   cin >> V >> E;
   if(!V && !E) return false;
   memset(graph, 0, sizeof(graph));
   memset(visit, 0, sizeof(visit));
   memset(orden, 0, sizeof(orden));
   memset(component, 0, sizeof(component));
   
   int v1, v2;
   for(int i=0; i<E; i++) {
      cin >> v1 >> v2;
      graph[v1][v2] = 1;
   }
   return true;
}

int main() {
   while(read()) {
      findStronglyConnectedComponents();
      int j=0;   
      while(j<componentId) {
         cout << " component " << (j+1) << endl << " ";
         for(int i=0; i<V; i++) {
            if(j==component[i])
               cout << i << " ";
         }
         cout << endl;
         j++;
      }    
   }
}
