#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node *next;
};

struct stack
{
	Node *sp; //dinh cua stack

	stack()
	{
		sp == NULL;
	}

	void push(int x)
	{
		Node *p = new Node;
		p->info = x;
		p->next = sp;
		sp = p;
	}

	int pop(int &x)
	{
		if (sp != NULL)
		{
			Node *p = sp;
			x = p->info;
			sp = sp->next;
			delete p;
			return 1;
		}
		return 0;
	}

	int isEmpty()
	{
		if (sp == NULL)
			return 1;
		return 0;
	}

	void xuat()
	{
		cout << "Cac phan tu co trong stack la: " << endl;
		Node *p = sp;

		while (p != NULL)
		{
			cout << p->info << endl;
			p = p->next;
		}
	}

	void xoaStack()
	{
		while (sp != NULL)
		{
			Node *p = sp;
			sp = sp->next;
			delete p;
		}
		cout << "Xoa toan bo stack thanh cong!" << endl;
	}

	int chuyen10sang2(int tp)
	{
		if (!isEmpty())
		{
			xoaStack();
		}

		int np = 0;
		while (tp != 0)
		{
			int soDu = tp % 2;
			push(soDu);
			tp /= 2;
		}
		int so;
		while (sp != NULL)
		{
			if (!pop(so))
				return -1;
			np = np * 10 + so;
		}
		return np;
	}
};
int main()
{
	stack st;
	int luaChon;
	int x,n;
	do
	{
		system("cls");
		cout << "===MENU===\n"
			<< "1.Them 1 phan tu vao stack.\n"
			<< "2.Lay 1 phan tu ra khoi stack.\n"
			<< "3.Xuat cac gia tri co trong stack.\n"
			<< "4.Chuyen tu he 10 sang he 2.\n"
			<< "5.Thoat chuong trinh.\n"
			<< ">>Lua chon cua ban la: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			cout << "Nhap gia tri muon them vao stack: ";
			cin >> x;
			st.push(x);
			cout << "Da them thanh cong! Vui long chon xuat de kiem tra!" << endl;
			break;
		case 2:
			if (st.pop(x))
				cout << "Gia tri vua lay ra khoi stack la: " << x << endl;
			else
				cout << "Lay phan tu ra khoi stack khong thanh cong!" << endl;
			break;
		case 3:
			st.xuat();
			cout << endl;
			break;
		case 4:
			cout << "Nhap so thap phan muon chuyen sang nhi phan: ";
			cin >> x;
			n = st.chuyen10sang2(x);
			if (st.chuyen10sang2(x) != -1)
				cout << "He nhi phan la: " << n << endl;
			else
				cout << "Qua trinh chuyen khong thanh cong!" << endl;
			break;
		case 5:
			st.xoaStack();
			cout << "Ban da chon thoat chuong trinh!" << endl;
			break;
		default:
			cout << "Lua chon cua ban khong hop le!" << endl;
			break;
		}
		_getch();
	} while (luaChon >= 1 && luaChon <= 5);
	return 0;
}