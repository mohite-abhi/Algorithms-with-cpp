#include <iostream>
using namespace std;


class graph
{
public:
    static int time;
    int V;
    int *dis;
    string *color;
    int *par;
    int ** adj;
    int * order;
    int * fin;

    void add_adj(int, int, int *);
    graph(int);


};

int graph::time=0;

void graph::add_adj(int u, int n, int *ar)
{
    adj[u] = ar;
    order[u] = n;
}

graph::graph(int v)
{
    V = v;
    adj = new int *[v];
    dis = new int [v];
    color = new string [v];
    par = new int [v];
    order = new int [V];
    fin = new int[v];
}

void dfs_visit(graph G, int u);
void dfs(graph G)
{
    for (int i = 0; i < G.V; i++)
    {
        G.color[i] = "white";
        G.par[i] = -1;
    }
    G.time = 0;

    for (int i = 0; i < G.V; i++)
    {
       if (G.color[i] == "white")
       {
           dfs_visit(G, i);
       }
    }
}

void dfs_visit(graph G, int u)
{
    int v;

    G.color[u] = "grey";
    G.time ++;
    G.dis[u] = G.time;
    cout<<" ("<<" "<<u<<" ";

    for (int i = 0; i < G.order[u]; i++)
    {
        v = G.adj[u][i];
        if (G.color[v] == "white")
        {
            dfs_visit(G, v);
            G.par[v] = u;
        }
    }
    G.time++;
    G.color[u] = "black";
    cout<<" "<<u<<" )";
    G.fin[u] = G.time; 
     
}


int main()
{
    
    int ord, *tmar, v;
    cout<<"give no. of nodes :";cin>>v;
    graph G(v);
    cout<<"give order of each vertex followed by its adjacent vertices if any.."<<endl;
    for (int i=0; i<v; i++)
    {
        
        cin>>ord;
        if (ord)
        {
            tmar = new int [ord];
            for (int i = 0; i < ord; i++)
            {
                cin>>tmar[i];
            }
            G.add_adj(i, ord, tmar);
        }
    }
    
    dfs(G);

    return 0;
}