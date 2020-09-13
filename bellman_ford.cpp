#include<iostream>
using namespace std;


class graph
{
public:
    int v;
    int *V;
    int e;
    int **E;
    int *W;
    int *dis;
    int *par;

    graph(int vv, int ee)
    {
        v=vv;
        e=ee;
        V = new int[v];
        for (int i = 0; i < v; i++)
        {
            V[i] = i;
        }

        E = new int*[e];
        for (int i = 0; i < e; i++)
        {
            E[i] = new int[2]; // v1, v2
        }
        W = new int[e];

        dis = new int[v];
        par = new int[v];
    }

    void initialize(int root)
    {

        for (int i = 0; i < v; i++)
        {
            dis[i] = 1000;
            par[i] = -1;
        }

        dis[root] = 0;
    }

    void relax(int eth_edge)
    {
        if (dis[E[eth_edge][0]] + W[eth_edge] < dis[E[eth_edge][1]])
        {
            dis[E[eth_edge][1]] = dis[E[eth_edge][0]] + W[eth_edge];
            par[E[eth_edge][1]] = E[eth_edge][0];
        }
    }

};


bool bellman_ford(graph * G, int root)
{
    G->initialize(root);

    for (int i = 0; i < G->v; i++)
    {
        for (int e = 0; e < G->e; e++)
        {
            G->relax(e);
        }
    }


    for (int e = 0; e < G->e; e++)
    {
       if (G->dis[G->E[e][0]] + G->W[e] < G->dis[G->E[e][1]])
        {
            return false;
        }
    }
    return true;
    
}



int main()
{

    graph * G = new graph(5, 10);

    for (int e = 0; e < G->e; e++)
    {
        cin>>G->E[e][0] >>G->E[e][1] >> G->W[e];

    }

    bellman_ford(G, 0);
    
    for (int v = 0; v < G->v; v++)
    {
        cout<<v<<" is child of "<<G->par[v]<<endl;
    }
    
    

    return 0;
}

