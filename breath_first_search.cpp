#include<iostream>
using namespace std;

class graph
{
public:
    int V;
    int *dis;
    string *color;
    int *par;
    int ** adj;
    int * order;

    void add_adj(int, int, int *);
    graph(int);


};

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
}

class queue
{
public:
    int size;
    int mark;
    int end;
    int *q;

    queue(int);
    int empty();
    void push(int);
    int pop();
};

queue::queue(int sz)
{
    size =sz;
    end = 0;
    mark = 0;
    q = new int[size];
}

void queue::push(int dta)
{
    q[end] = dta;
    end++;
}

int queue::pop()
{
    int popd = q[mark];
    mark++;
    return popd;
}

int queue::empty()
{
    if (mark == end)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void bfs(graph G, int s)
{
    int u, v;

    for(int i = 0; i<G.V; i++)
    {
        G.color[i] = "white";
        G.par[i] = -1;
        G.dis[i] = G.V+1;
    }
    G.color[s] = "grey";
    G.dis[s] = 0;

    queue Q(G.V);
    Q.push(s);

    while (Q.empty()==0)
    {
        u = Q.pop();
        for (int i = 0; i < G.order[u]; i++)
        {
            v = G.adj[u][i];
            if (G.color[v] == "white")
            {
                G.color[v] = "grey";
                G.par[v] = u;
                G.dis[v] = G.dis[u] + 1;
                Q.push(v);
            }
        }
        G.color[u] = "black";
    }
}

void print_path(graph G, int s, int v)
{
    if (s==v)
    {
        cout<<s<<" ";
    }
    else if (G.par[v] == -1)
    {
        cout<<"no path sorry";
    }
    else
    {
        print_path(G, s, G.par[v]);
        cout<<v<<" ";
    }
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
    
    bfs(G, 0);

    cout<<"here:"<<endl;
    /*
    for (int i = 0; i < G.V; i++)
    {
        for (int j = 0; j < G.order[i]; j++)
        {
            cout<<G.adj[i][j]<<" ";
        }
        cout<<G.par[i]<<" <- "<<i;
        cout<<endl;
    }
    */

   print_path(G, 0, 7);


    return 0;
}
