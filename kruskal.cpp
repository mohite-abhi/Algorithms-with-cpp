#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *p;
    int rank;
    node(int x)
    {
        data = x;
        p = this;
        rank = 0;
    }
};

void link(node*x, node*y)
{
    if (x->rank > y->rank)
    {
        y->p = x;
    }
    else
    {
        x->p = y;
        if (x->rank == y->rank)
        {
            y->rank++;
        }
    }
}

node * find_set(node *x)
{
    node *temp = x;
    while (temp->p != temp)
    {
        temp = temp->p;
    }
    return temp->p;
}

void union_set(node*x, node*y)
{
    link(find_set(x), find_set(y));
}

class graph
{
public:
    int v;
    int e;
    int *V;
    int **E;
    int *W;

    graph(int vv, int ee)
    {
        v = vv;
        e = ee;
        V = new int[vv];
        E = new int*[ee];
        for (int i = 0; i < ee; i++)
        {
            E[i] = new int[3];
        }
        
    }
};


int ** kruskal(graph *G)
{
    
    int ** mst = new int*[G->e];
    for (int i = 0; i < G->e; i++)
    {
        mst[i] = new int[2];
    }
    


    node **indiv_sets = new node*[G->v];

    for (int i = 0; i < G->v; i++)
    {
        indiv_sets[i] =  new node(i);
    }

    int * temp;

    for (int i = 0; i < G->e; i++)
    {
        for (int j = i; j < G->e; j++)
        {
            if(G->E[i][0] > G->E[j][0])
            {
                temp = G->E[i];
                G->E[i] = G->E[j];
                G->E[j] = temp;
            }
        }
        
    }
    int ind = 0, u, v;
    for (int i = 0; i < G->e; i++)
    {
        u = G->E[i][1];
        v = G->E[i][2];

        if (find_set(indiv_sets[u]) != find_set(indiv_sets[v]))
        {
            mst[ind][0] = u;
            mst[ind][1] = v;
            union_set(indiv_sets[u], indiv_sets[v]);
            ind++;
        }
    }
    return mst;
    
}


int main()
{
    
    graph *G = new graph(9, 14);
    
    for (int i = 0; i < G->e; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>G->E[i][j];
        }
    }
    
    int **ans = kruskal(G);

    for (int i = 0; i < G->e; i++)
    {
        cout<<ans[i][0]<<"  "<<ans[i][1]<<endl;
    }
    
    
    return 0;
}