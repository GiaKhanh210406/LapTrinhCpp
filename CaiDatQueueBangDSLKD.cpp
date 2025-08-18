#include <iosteam>
using namespace std;

struct Node
{
  int info;
  Node *next;
};

struct queue
{
    Node *rear,*font;
    
    queue()
    {
        font = rear = NULL;
    }
    
    bool isEmpty()
    {
        return font == NULL;
    }
    
    Node *taoNode(int x)
    {
      Node *p = new Node;
      p->info = x;
      p->next = NULL;
      return p;
    }
    
    void push(int x)
    {
        Node *p = taoNode(x);
        if (rear == NULL)
            font = p;
        else
            rear->next = p;
        rear = p;
    }
    
    int pop(int &x)
    {
        if (font != NULL)
        {
            Node *p = font;
            x = p->info;
            
            if (font == NULL)
                rear == NULL;
            else
                font = font->next;
            delete p;
            return 1;
        }
        return 0;
    }
    
    void xoaToanBoQueue()
    {
      if (font != NULL)
      {
          while (font != NULL)
          {
            Node *p = font;
            font=font->next;
            delete p;
          }
          cout << "Xoa toan bo hang doi thanh cong!" << endl;
      } 
      return;
    }
};
int main()
{
    
    
    return 0;
}