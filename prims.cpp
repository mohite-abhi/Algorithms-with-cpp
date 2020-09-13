/*
#include<iostream>
using namespace std;



class graph
{
public:
    int *par;
    int *key;
    int *order;
    int v;
    int *V;
    int ***adj;

    graph(int vv)
    {
        v = vv;
        V = new int[vv];
        key = new int[vv];
        for (int i = 0; i < v; i++)
        {
            
            V[i] = i;
        }
        
        order = new int[vv];
        par = new int[vv];
    }

    void get_adj()
    {
        adj = new int**[v];
        for (int i = 0; i < v; i++)
        {
            cin>>order[i];
            adj[i] = new int *[order[i]];

            for (int j = 0; j < order[i]; j++)
            {
                adj[i][j] = new int[2];
                cin>>adj[i][j][0]>>adj[i][j][1];
            }
        }
    }
};



void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}


void min_prioritize(int *key_ar, int i, int len, int *val)
{
    int l = 2*i +1;
    int r = 2*i + 2;
    int smallest = i;

    if (l<len and key_ar[l] < key_ar[smallest])
    {
        smallest = l;
    }
    if (r<len and key_ar[r] < key_ar[smallest])
    {
        smallest = r;
    }
    swap(key_ar[i], key_ar[smallest]);
    swap(val[i], val[smallest]);
    if (smallest != i)
    {
        min_prioritize(key_ar, smallest, len, val);
    }

}

void build_priority_queue(int * key_ar, int len,int * val)
{
    for (int i = len/2-1; i >=0; i--)
    {
        min_prioritize(key_ar, i, len, val);
    }
    
}



int extract_priority_min(int *key_ar, int &len, int *val)
{
    if (len==0)
    {
        cout<<"heap empty!";
        return 666;
    }
    
    int temp = val[0];
    swap(key_ar[0],key_ar[len-1]);
    swap(val[0],val[len-1]);
    min_prioritize(key_ar,0,--len, val);

    return temp;
}


bool is_in_queue(int query, int *val, int len)
{
    for (int i = 0; i < len; i++)
    {
        if(query == val[i])
        {
            return true;
        }
    }
    return false;
    
}

void prims(graph *G, int root)
{

    for (int i = 0; i < G->v; i++)
    {
        G->par[i] = -66;
        G->key[i] = 100000;
    }

    G->key[root] = 0;
    int q_len = G->v;
    build_priority_queue(G->key, q_len, G->V);
    
    int u, v;
    
    while (q_len != 0)
    {
        u = extract_priority_min(G->key, q_len, G->V);

        for (int i = 0; i < G->order[u]; i++)
        {
            v =  G->adj[u][i][0];

            if (is_in_queue(v, G->V, q_len) && G->adj[u][i][1] < G->key[v] )
            {
                G->key[v] = G->adj[u][i][1];
                G->par[v] = u;
                min_prioritize(G->key, v, q_len, G->V);
                
            }
            
        }
        cout<<endl;
        
    }
    

}




int main()
{
    graph *G = new graph(9);

    G->get_adj();

    prims(G, 0);

    for (int i = 0; i < G->v; i++)
    {
        cout<<i<<"<="<<G->par[i]<<endl;
    }
    

    return 0;
}

*/


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


int is_in_queue(queue* Q, int x)
{
    for (int i = 1; i < Q->cur_len; i++)
    {
        if (Q->data[i] == x)
        {
            return 1;
        }
    }
    return 0;
}




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


    void relax(int u, int u_adj_ind, queue * Q)
    {
        int v = adj[u][u_adj_ind];
        int w_u_v =  W[u][u_adj_ind];
        

        if (is_in_queue(Q, v) ==1 && w_u_v < dis[v])
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


void prims(graph *G, int root)
{
    G->initialize(root);

    queue *Q = new queue(G->v, G->V, G->dis);

    int u;

    while (Q->cur_len != 0)
    {
        

        u = G->V[0];

        for (int u_adj_ind = 0; u_adj_ind < G->order[u]; u_adj_ind++)
        {
            G->relax(u, u_adj_ind, Q);
        }

        Q->extract_min();
        
    }
    
}



int main()
{
    
    graph *G = new graph(4);

    G->get_adj();

    
    prims(G, 0);

    for (int i = 0; i < G->v; i++)
    {
        cout<<i<<" is child of "<<G->par[i]<<endl;
    }cout<<endl;
    
     
    return 0;
}


