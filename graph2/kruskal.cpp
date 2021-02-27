#define max 100

struct Edge{
    int vi,vj,w;
};

bool lequal(Edge const* t1, Edge const* t2){
    return (t1->w<t2->w);
}

int V,E;
vector <Edge*>edges;
vector <Edge*>mst;
int cicles[max];

int main(){

    int i,W,number,c;
    Edge *e;

    c=1;
    while(true){
        edges.clear();
        mst.clear();
        cin>>V>>E;
        if(!V && !E) break;

        for(i=0;i<E;i++){
            e = new Edge;
            cin>>e->vi>>e->vj>>e->w;
            edges.push_back(e);
        }

        sort(edges.begin(),edges.end(),lequal);
        for(i=0;i<V;i++) cicles[i] = i;

        while(mst.size()<(V-1) && edges.size()){
            if(cicles[edges[0]->vi]!=cicles[edges[0]->vj]){
                number = cicles[edges[0]->vj];
                for(i=0;i<V;i++) {
                    if(cicles[i]==number)
                        cicles[i] = cicles[edges[0]->vi];
                }
                mst.push_back(edges[0]);
            }
            edges.erase(edges.begin(),edges.begin()+1);
        }
        W = 0;
        for(i=0;i<mst.size();i++) {
            W+=mst[i]->w;
        }
        cout<<"Case "<<c++<<":"<<endl;
        cout<<"The Minimun Spanning Tree has cost: "<<W<<endl;
    }

    return 0;
}
