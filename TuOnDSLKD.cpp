// Khai bao danh sach lien ket don
//Ham khoi tao danh sach lien ket don
//Ham tim kiem
//Ham them 1 phan tu vao dau
//Ham them 1 phan tu vao cuoi
//Ham them 1 phan tu sau 1 node bat ky
//Ham xoa phan tu dau
//Ham xoa phan tu cuoi
//Ham xoa sau 1 node bat ky
//Ham main: Thuc hien menu

#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};

Node *first;

void intit()
{
	first = NULL;
}

void themDau(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

void themCuoi(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}

		q->link = p;
	}
}

Node* timKiem(int x)
{
	Node *p = first;
	p->info = x;

	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}
int themSau(int x, int y) // chen x sau y
{
	Node *kq = timKiem(y);

	if (kq == NULL)
	{
		return 0;
	}

	Node *p = new Node;
	p->info = x;

	if (kq->link == NULL)
		p->link = NULL;
	else
		p->link = kq->link;

	kq->link = p;

	return 1;
}

void xuatDS()
{
	Node *p = first;

	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
}

int xoaDau()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
int main()
{
	int luaChon,x,y;
	bool in = false;

	do
	{
		system("cls");
		cout << "MENU\n"
			<< "1.Khoi tao danh sach lien ket don.\n"
			<< "2.Tim kiem trong danh sach lien ket don.\n"
			<< "3.Them 1 phan tu vao dau danh sach lien ket don.\n"
			<< "4.Them 1 phan tu vao cuoi danh sach lien ket don.\n"
			<< "5.Them 1 phan tu sau 1 node bat ky trong danh sach lien ket don.\n"
			<< "6.Xoa phan tu dau danh sach lien ket don.\n"
			<< "7.Xoa phan tu cuoi danh sach lien ket don.\n"
			<< "8.Xoa phan tu sau 1 node bat ky danh sach lien ket don.\n"
			<< "9.Xuat danh sach lien ket don.\n"
			<< "10.Thoat chuong trinh.\n"
			<< ">Lua chon cua ban la: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
			intit();
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Nhap gia tri can tim kiem trong danh sach lien ket don: ";
				cin >> x;

				if (timKiem(x) != NULL)
					cout << "Co " << x << " trong danh sach lien ket don!" << endl;
				else
					cout << "Khong co " << x << " trong danh sach lien ket don!" << endl;
			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 3:
			if (in)
			{
				cout << "Nhap gia tri can them vao dau danh sach lien ket don: ";
				cin >> x;
				themDau(x);
				cout << "Da them vao dau danh sach thanh cong! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 4:
			if (in)
			{
				cout << "Nhap gia tri can them vao cuoi danh sach lien ket don: ";
				cin >> x;
				themCuoi(x);
				cout << "Da them vao cuoi danh sach thanh cong! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 5:
			if (in)
			{
				cout << "Nhap gia tri muon them sau: ";
				cin >> y;
				cout << "Nhap gia tri node can them phia sau: ";
				cin >> x;

				if (themSau(x, y))
					cout << "Da them thanh cong! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
				else
					cout << "Them khong thanh cong!" << endl;
			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 6:
			if (in)
			{
				if (xoaDau())
					cout << "Xoa dau danh sach lien ket thanh cong! Vui long chon xuat danh sach lien ket de kiem tra thong tin!" << endl;
				else
					cout << "Xoa dau khong thanh cong!" << endl;
			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 7:
			if (in)
			{

			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 8:
			if (in)
			{

			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 9:
			if (in)
			{
				cout << "Danh sach lien ket don dang luu tru la: " << endl;
				xuatDS();
			}
			else
				cout << "Ban chua khoi tao danh sach lien ket don!" << endl;
			break;
		case 10:
			cout << "Thoat chuong trinh!" << endl;
			return 0;
			break;
		default:
			cout << "Lua chon cua ban khong hop le!" << endl;
			break;
		}
		_getch();
	} while (luaChon >= 1 || luaChon <= 10);

	return 0;
}