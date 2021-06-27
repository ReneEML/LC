class Vertex{
public:
    int color;
    list<Vertex*> adj;
    Vertex(){
        color = 0;
    }
};

class Graph{
public:
    vector<Vertex*> V;
    bool dfs();
    void dfs_visit(Vertex* u, bool &result);
    Graph(vector<vector<int>> & v, int n){
        for(int i = 0; i < n; i ++){
            V.push_back(new Vertex());
        }
        for(int i = 0; i < v.size(); i++){
            V[v[i][0]]->adj.push_back(V[v[i][1]]);
        }
    }
};

bool Graph::dfs(){
    bool result = true;
    for(Vertex* u : V ){
        if(u->color == 0){
            dfs_visit(u, result);
        }
    }
    return result;
}

void Graph::dfs_visit(Vertex* u, bool &result){
    u->color = 1;
    for(Vertex* v: u->adj){
        if(v->color == 0){
            dfs_visit(v, result);
        }
        else if(v->color == 1){
            result = false;
        }
    }
    u->color = 2;
}
