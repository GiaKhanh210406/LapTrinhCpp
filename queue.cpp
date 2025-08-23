#include <iostream>
using namespace std;

struct queue
{
	int *q;
	int font, rear, max;

	queue(int n = 50)
	{
		max = n;
		q = new int[max];
		font = rear = -1;
	}

	bool isEmpty()
	{
		return font == -1;
	}

	bool isFull()
	{
		return rear - font == max - 1 || rear - font == -1;
	}

	int pushTinhTien(int x)
	{
		if (!isFull())
		{
			if (font == -1) //neu hang doi rong thi them 1 phan tu thi font tang len 0
				font = 0;
			if (rear == max - 1) //neu hang doi bi tran
			{
				for (int i = font; i <= rear; i++)
				{
					q[i - font] = q[i]; //tinh tien
				}
				rear = max - 1 - font; //cap nhat lai rear
				font = 0; //font xuong lai 0
			}

			//truong hop nao cung tang rear len roi gan cho x
			q[++rear] = x;
			return 1;
		}
		return 0;
	}

	int pushVong(int x)
	{
		if (!isFull())
		{
			if (font == -1) //neu hang doi rong thi them 1 phan tu vao thi tang len 1
				font = 0;
			if (rear == max - 1) //neu rear bi tran thi dua rear xuong -1
			{
				rear = -1;
			}
			//truong hop nao cung tang rear len roi gan cho x
			q[++rear] = x;
			return 1;
		}
		return 0;
	}

	int pop(int &x)
	{
		if (!isEmpty())
		{
			x = q[font++];
			if (font > rear) //hang doi co 1 phan tu , neu lay phan tu do ra thi hang doi rong
				font = rear = -1;
			return 1;
		}
		return 0;
	}

	void xuatqueue()
	{
		if (!isEmpty())
		{
			for (int i = font; i <= rear; i++)
			{
				cout << q[i] << '\t';
			}
		}
		return;
	}

	int daoNguocSo(int x)
	{
		while (x > 0)
		{
			pushTinhTien(x % 10);
			x /= 10;
		}

		int dn = 0;
		while (!isEmpty())
		{
			int x;
			pop(x);
			dn = dn * 10 + x;
		}
		return dn;
	}
};
int main()
{
	queue q;
	int x;

	cin >> x;
	int kq = q.daoNguocSo(x);
	cout << "So dao nguoc la: " << kq << endl;

	return 0;
}