#include<iostream>
using namespace std;

class queue
{
public:
    int max_size;
    int *data;
    int *key;
    int cur_len;
    int temp;

    queue(int max_size)
    {
        data = new int[max_size];
        key = new int[max_size];
        cur_len = 0;
    }

    void swap(int pos1, int pos2)
    {
        temp = data[pos1];
        data[pos1] = data[pos2];
        data[pos2] = temp;
        
    }

    void min_heapify(int i)
    {
        int l = i*2 +1;
        int r = i*2 +2;
        int smallest = i;

        if(l < cur_len and key[data[l]] < key[data[i]])
        {
            smallest = l;
        }
        if (r < cur_len and key[data[r]] < key[data[smallest]])
        {
            smallest = r;
        }

        swap(i, smallest);

        if(smallest != i)
        {
            min_heapify(smallest);
        }   
    }

    int parant(int i)
    {
        return int((i-1)/2);
    }

    void decrease_key(int new_key, int pos)
    {
        key[data[pos]] = new_key;

        while(key[data[parant(pos)]] > key[data[pos]] and pos > 0)
        {
            swap(parant(pos), pos);
            pos = parant(pos);
        }
    }

    void insert(int key1, int data1)
    {
        data[cur_len] = data1;
        key[data[cur_len]] = key1;
        cur_len ++;
        decrease_key(key1, cur_len-1);
    }

    int extract_min()
    {
        int drop = data[0];
        swap(0, cur_len-1);
        cur_len--;
        min_heapify(0);
        

        return drop;
    }
    
    queue(int ln, int * dta, int * ky)
    {
        cur_len = max_size = ln;

        data = dta;
        key = ky;

        for (int i = int(ln/2) - 1; i >=0 ; i--)
        {
            min_heapify(i);
        }
        
    }

};




class graph
{
public:
    int v;
    int *V;
    int **adj;
    int **W;
    int *dis;
    int *par;
    int *order;


    graph(int vv)
    {
        v=vv;
        V = new int[v];
        for (int i = 0; i < v; i++)
        {
            V[i] = i;
        }

        adj = new int*[v];
        W = new int *[v];

        dis = new int[v];
        par = new int[v];
        order = new int [v];
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


    void relax(int u, int u_adj_ind)
    {
        int v = adj[u][u_adj_ind];
        int w_u_v =  W[u][u_adj_ind];
        

        if (dis[u] + w_u_v < dis[v])
        {
            dis[v] = dis[u] + w_u_v;
            par[v] = u;
        }
    }

    void get_adj()
    {
        for (int i = 0; i < v; i++)
        {
            cin>>order[i];                          //get noutorder for particular vertex
            adj[i] = new int[order[i]];              //deciding adj array of each vertex acc. to outorder
            W[i] = new int [order[i]];               //deciding weight array of each edje of v and its adjacent

            for (int j = 0; j < order[i]; j++)
            {
                cin>>adj[i][j] >> W[i][j];           //getting actual name of ajdacent and the weight btw them 
            }
            
        }
        
    }

};


void dijkstra(graph *G, int root)
{
    G->initialize(root);

    queue *Q = new queue(G->v, G->V, G->dis);
    queue *S = new queue(G->v);

    int u;

    int count = 0;

    while (Q->cur_len != 0)
    {

        u = G->V[0];

        for (int u_adj_ind = 0; u_adj_ind < G->order[u]; u_adj_ind++)
        {
            G->relax(u, u_adj_ind);
        }

        Q->extract_min();
        
    }
    
}



int main()
{
    
    graph *G = new graph(5);

    G->get_adj();

    
    dijkstra(G, 0);

    for (int i = 0; i < G->v; i++)
    {
        cout<<i<<" is child of "<<G->par[i]<<endl;
    }
     
    return 0;
}

