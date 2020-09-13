#include<iostream>
using namespace std;


class node
{
    public:
        int freq;
        char c;
        node * left;
        node * right;
        int code[20];
        node(){freq=0;left=right=nullptr;c='?';}
        node(int f, char cc){freq=f;c=cc;left=right=nullptr;}
        void get(){cin>>freq;cin>>c;}
        void show(){cout<<freq<<"->"<<c<<" ";}
};



void swap(node *a, node *b)
{
    node *temp;
    temp = a;
    a = b;
    b = temp;
}

void min_heapify(node ** nd, int i, int len)
{
    
    int l = 2*i +1;
    int r = 2*i +2;
    int smallest = i;
    

    if(l < len && nd[l]->freq < nd[i]->freq )
    {
        smallest = l;
        
    }
    
    if(r < len &&nd[r]->freq < nd[smallest]->freq)
    {
        smallest = r;
    }
    if (smallest != i)
    {
        node *temp;
        temp = nd[i];
        nd[i] = nd[smallest];
        nd[smallest] = temp;
    }
}


node * extract_from_pq(node **nd, int & len)
{
    
    if (len <1){cout<<"empty!";return nullptr;}
    node *temp = new node;
    
    temp = nd[0];
    node * temp1 = nd[0];
    nd[0] = nd[len-1];
    nd[len-1] = temp1;

    min_heapify(nd, 0, --len);
    return temp;
}


int parent(int n){return (n-1)/2;}


void decrease_pq_freq(node ** ar, int i, int new_f)
{
    ar[i]->freq = new_f;
    while (i>0 and ar[parent(i)]->freq > ar[i]->freq)
    {
        node * temp = ar[parent(i)];
        ar[parent(i)] = ar[i];
        ar[i] = temp;
        i = parent(i);
    }
    
}

void insert_pq_freq(node ** ar, node * tmp, int & len)
{
    ar[len] = tmp;
    len += 1;
    decrease_pq_freq(ar,len-1,tmp->freq);
}


node * huffman(node ** ar, int &len)
{

    int n = len; node *z; node *x; node *y;
    for (int i = 0; i < n-1; i++)
    {
        z = new node; x = new node; y = new node;
        x=extract_from_pq(ar,len);
        y=extract_from_pq(ar,len);

        z->left = x;
        z->right = y;

        z->freq = x->freq + y->freq;
        insert_pq_freq(ar,z,len);
    }
    z= extract_from_pq(ar,len);   
    return z;
}

void traverse_huffman(node * huff, node * store, int * cod, int i=0)
{
    if (huff!=nullptr)
    {
        if (huff->c != '?')
        {
            node * tmp = new node;
            node * leaf = store;
            while (leaf->right!=nullptr)
            {
                leaf=leaf->right;
            }

            for (int i = 0; i < 20; i++) 
            {(tmp->code)[i] = cod[i];}

            tmp->c = huff->c;
            leaf->right = tmp;
            
            return;   
        }
        if (huff->left != nullptr)
        {
            cod[i] = 0;
            traverse_huffman(huff->left, store, cod, i+1);
            cod[i] = -1;
        }
        if (huff->right != nullptr)
        {
            cod[i] = 1;
            traverse_huffman(huff->right, store, cod, i+1);
            cod[i] = -1;
        }

    }
    
}


int main()
{
    
    node **ar;
    for (int i = 0; i < 100; i++)
    {
        ar = new node*;
    }
    for (int i = 0; i < 100; i++)
    {
        ar[i] = new node(0,'?');
    }
    
    node *temp;int inp=0;
    
    int huf_len = 0;
    

    while (inp >=0)
    {
        temp = new node;
        temp->get();
        inp=temp->freq;
        if (inp >=0)
        {
           insert_pq_freq(ar,temp,huf_len);
        }
    }


    node *temp2 = huffman(ar, huf_len);

    node *store = new node;

    int cod[20]; 
    for (int i = 0; i < 20; i++) 
        { cod[i] = -1 ; }

    traverse_huffman(temp2, store, cod);

    while (store!=nullptr)
    {
        cout<<store->c<<" -> ";
        for (int i = 0; i < 20; i++) 
        { cout<<(store->code)[i]; }
        cout<<endl;
        store=store->right;
    }

    return 0;
}
