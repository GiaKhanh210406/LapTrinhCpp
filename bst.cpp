#include <iostream>
using namespace std;

struct Node
{
  int info;
  Node *left,*right;
};

struct bst
{
    Node *root;
    
    bst()
    {
        root == NULL;
    }
    
    Node *taoNode(int x)
    {
        Node *p = new Node;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    
    void themNode(Node *p,int x)
    {
        if (p == NULL)
            p = taoNode(x);
        else
        {
            if (p->info == x)
                return;
            if (p->info > x)
                return themNode(p->left,x);
            else
                return themNode(p->right,x);
        }
    }
    
    void timTheMang(Node *&p, Node *&q)
    {
        if (p->left == NULL)
        {
            p->info = q->info;
            p = q;
            q = q->right;
        }
        timTheMang(p,p->left);
    }
    
    int xoa(Node *&T, int x)
    {
        if (T == NULL)
            return 0;
        if (T->info == x)
        {
            Node *p = T;
            if (T->left == NULL)
                p = p->right;
            else if (T->right == NULL)
                p = p->left
            else //co 2 con 
                timTheMang(p,T->right);
                
            delete p;
            return 1;
        }
        
        if (T->info > x)
            return xoa(T->left,x);
        else
            return xoa(T->right,x);
    }
    
    Node *timKiem(Node *p,int x)
    {
        if (p != NULL)
        {
            if (p->info == x)
                return p;
            else if (p->info > x)
                return timKiem(p->left,x);
            else
                return timKiem(p->right,x);
        }
        return NULL;
    }
    
    void duyetNLR(Node *p)
    {
        cout << p->info << "\t";
        duyetNLR(p->left);
        duyetNLR(p->right);
    }
    
    void duyetLNR(Node *p)
    {
        duyetLNR(p->left);
        cout << p->info << "\t";
        duyetLNR(p->right);
    }
    
    void duyetLRN(Node *p)
    {
        duyetLRN(p->left);
        duyetLRN(p->right);
        cout << p->info << "\t";
    }
    
     int demCay(Node *p)
     {
         if (p == 0)
            return 0;
        return 1 + demCay(p->left) + demCay(p->right);
     }
     
     int tinhTong(Node *p)
     {
        if (p == NULL)
            return 0;
        return p->info + tinhTong(p->left) + tinhTong(p->right);
     }
     
     int timMax(Node *p)
     {
        if (p->right == NULL)
            return p->info;
        return timMax(p->right);  
     }
     
     int timMin(Node *p)
     {
         if (p->left == NULL)
            return p->info;
        return timMin(p->left);
     }
}
int main()
{
    
    return 0;
}
}