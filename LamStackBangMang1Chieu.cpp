#include <iostream>
using namespace std;

struct arryStack
{//lam stack voi mang 1 chieu
  int *stack; //cap phat dong mang 1 chieu
  int top; //dinh cua stack
  int max; // so luong toi da cua stack
  
  arryStack(int n = 100) //khoi tao stack rong
  {
    max = n;
    stack = new int[max];
    top = -1;
  }
  
  bool isFull()
  {
    return top == max-1;
  }
  
  bool isEmpty()
  {
    return top < 0;
  }
  
  void push(int x)
  {
    if (isFull())
    {
      cout << "Stack day\n" << endl;
    }
    else
    {
      stack[++top] = x;
    }
  }
  
  int pop(int &x)
  {
    if (isEmpty())
    {
      cout << "stack rong\n";
      return 0;
    }
    else
    {
      x = stack[top--];
      return 1;
    }
  }
  
  int layPhanTuTop(int &x)
  {
    if (isEmpty())
    {
      cout << "stack dang rong\n";
      return 0;
    }
    else
    {
      x = stack[top];
      return 1;
    }
  }
  
  void xuatStack()
  {
    while (!isEmpty())
    {
      int x;
      pop(x);
      cout << x << "\t";
    }
    cout << endl;
  }
  
  int chuyen10sang2(int x)
  {
      while (x > 0)
      {
          int soDu = x % 2;
          push(soDu);
          x = x / 2;
      }
      
      int soNhiphan = 0;
      while (!isEmpty())
      {
          int so;
          pop(so);
          soNhiphan = soNhiphan * 10 + so;
      }
      return soNhiphan;
  }
  
};

int main() 
{
    arryStack st;
    st.push(11);
    st.push(13);
    st.push(20);
    
    st.xuatStack();
    int x;
    cout << "Nhap so muon chuyen tu he 10 sang he 2: ";
    cin >> x;
    int np = st.chuyen10sang2(x);
    cout << "So nhi phan tuong ung la: " << np << endl;
    return 0;
}