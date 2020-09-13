#include<iostream>
using namespace std;

class node
{
    
    public:
        int data;
        int key;
        node * left;
        node * right;
        node * p;
        node(int ky=0,int dta=0){key=ky;data=dta;left=nullptr;right=nullptr;p=nullptr;}
};


void bin_inp(node * root, int key, int data = 0)
{

   if(key <= root->key)
   {
       if (root->left != nullptr)
       {
           bin_inp(root->left, key, data);
       }
       else
       {
           node*tmp = new node();
           tmp->data = data;
           tmp->key = key;
           tmp->p = root;
           root->left = tmp;
       }
   }
   else
   {
       if (root->right != nullptr)
       {
           bin_inp(root->right, key, data);
       }
       else
       {
           node*tmp = new node();
           tmp->data = data;
           tmp->key = key;
           tmp->p = root;
           root->right = tmp;
       }

   }
    
}


void bin_inorder(node * root)
{
    if (root!=nullptr)
    {
        bin_inorder(root->left);
        cout<<root->key<<" ";
        bin_inorder(root->right);
    }
    
}

int bin_min(node * root)
{
    node * head = root;
    while (head->left != nullptr)
    {
        head = head->left;
    }
    return head->key;
}

int bin_max(node * root)
{
    node * head = root;
    while (head->right != nullptr)
    {
        head = head->right;
    }
    return head->key;
}


node* inp(int n)
{   
    int tmp;
    cout<<"give "<<n<<" numbers :";
    cin>>tmp;
    node *temp = new node(tmp);
    for (int i = 0; i < n-1; i++)
    {
        cin>>tmp;
        bin_inp(temp,tmp);
    }
    return temp;
}

int main()
{

    int n, choice=1;
    cout<<"\ngive no. of tests for binary tree:"; cin>>n;cout<<endl;
    
    node * bin_tree = inp(n);
    


    while (choice/4 == 0)
    {
        cout<<"\n1. traverse inorder \t2. show min element \n3. show max element\t4. exit\n";cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<">>>";bin_inorder(bin_tree);
            break;
        case 2:
            cout<<">>>"<<bin_min(bin_tree);
            break;
        case 3:
            cout<<">>>"<<bin_max(bin_tree);
            break;
        case 0:
            cout<<"hidden choice initiated, give key to input :";cin>>n;
            bin_inp(bin_tree, n);
            break;
        default:
            break;
        }
    }
    


    return 0;
}