#include <iostream>
using namespace std;


struct queue 
{
    int *queue;
    int font,rear,max;
    
    queue(int n = 20) //khoi tao hang doi 
    {
        max = n;
        queue = new int[max];
        font = rear = -1;
    }
    
    bool isEmpty()
    {
        return font < 0; //kiem tra hang doi rong
    }
    
    bool isFull()
    {
        return (rear - font == MAX-1) || (rear - font == -1); //day ;a 2 truong hop hang doi bi day
    }
    
    void pushTinhTien(int x)
    {
        if (isFull()) //neu hang doi day thi dung
            return 0;
            
        if (font == -1) //neu hang doi rong thi them 1 phan tu vao
            font = 0;
        if (rear == MAX-1) //hang doi bi tran
            {
                for (int i = font; i <= rear; i++) //vong for di tu font den rear tinh tien xuong cuoi hang doi
                {
                    queue[i-font] = queue[i]; //tinh tien
                }
                
                rear = MAX-1-font; //cap nhat lai rear
                font = 0; //gan font o duoi cung hang doi
            }
        // truong hop nao cung tang rear len 1 va gan gia tri = x   
        queue[++rear] = x;
    }
    
    int pop(int &x)
    {
        if (isEmpty()) //neu hang doi rong thi dung ko lay nua
            return 0;
        else
            {
                x = queue[font++];
                
                if (font > rear) //truong hop co 1 phan tu, sau khi xoa phan tu do xong hang doi rong
                {
                    font = rear = -1;
                }
                return 1;
            }
    }
    
    void pushVong(int x)
    {
        if (isFull()) //hang doi day
            return 0;
        //xet hang doi rong
        if (font == -1)
            font = 0;
        if (rear == MAX - 1) //hang doi bi tran, cho rear vong xuong duoi
            rear = -1;
        queue[++rear] = x;
        return 1;
    }
};
int main()
{
    
    
    return 0;
}