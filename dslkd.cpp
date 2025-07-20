#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *first;

void khoiTao()
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

void themCuoi(int x) // kiem tra danh sach rong , neu rong thi first = p
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;

	if (first == NULL) // danh sach dang rong, them vao duoi cung chinh la them vao dau danh sach
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
		// het vong lap while la q dang o cuoi danh sach , gan q->link = p
		q->link = p;
	}
}

void xuat()
{
	Node *p = first;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}

Node *timKiem(int x)
{
	Node *p = first;

	while (p != NULL && p->info != x)
	{
		p = p->link;
	}

	return p;
}

int themSau(int y,int x) // chen x sau y
{
	Node *kq = timKiem(y);
	if (kq == NULL)
		return 0;
	Node *p = new Node;
	p->info = x;
	if (kq->link == NULL)
		p->link = NULL;
	else
		p->link = kq->link;
	kq->link = p;
	return 1;
}

int xoaDau()
{
	if (first != NULL) // kiem tra danh sach co dang rong hay khong
	{
		// con neu khong rong thi thuc hien cac cau lenh duoi day
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0; // neu rong thi return 0
}

int xoaCuoi()
{
	if (first != NULL)// kiem tra danh sach co dang rong hay khong
	{
		// con neu khong rong thi thuc hien cac cau lenh duoi day
		Node *q, *p;
		p = first;
		q = NULL;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		// het vong lap while la q ket cuoi
		if (p != first) // p duoc day di it nhat 1 lan va q chac chan duoc cap nhat , co nhieu hon 1 phan tu
			q->link = NULL;
		else // p van bang first , chi co 1 node
			first = NULL;
		delete p;
		return 1;
	}
	return 0; // neu rong thi return 0
}
int main()
{
	int luaChon, x;
	bool in = false;
	do
	{
		system("cls");
		cout << "MENU\n"
			<< "1.Khoi tao danh sach lien ket don.\n"
			<< "2.Them 1 phan tu vao dau danh sach lien ket don.\n"
			<< "3.Them 1 phan tu vao cuoi danh sach lien ket don.\n"
			<< "4.Them 1 phan tu vao sau 1 node bat ky danh sach lien ket don.\n"
			<< "5.Xuat cac phan tu trong danh sach lien ket don!\n"
			<< "6.Tim kiem gia tri trong danh sach lien ket don.\n"
			<< "7.Xoa 1 phan tu dau danh sach lien ket don.\n"
			<< "8.Xoa 1 phan tu cuoi danh sach lien ket don.\n"
			<< "9.Xoa 1 phan tu sau 1 node bat ky danh sach lien ket don.\n"
			<< "10.Thoat chuong trinh.\n"
			<< ">>Ban chon: ";
		cin >> luaChon;

		switch (luaChon)
		{
		case 1:
			khoiTao();
			in = true;
			break;
		case 2:
			if (in)
			{
				cout << "Nhap gia tri them vao dau: ";
				cin >> x;
				themDau(x);
				cout << "Them vao dau thanh cong , vui long chon xuat mang de xem ket qua!" << endl;
			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 3:
			if (in)
			{
				cout << "Nhap gia tri them vao cuoi: ";
				cin >> x;
				themCuoi(x);
				cout << "Them vao cuoi thanh cong , vui long chon xuat mang de xem ket qua!" << endl;
			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 4:
			if (in)
			{
				int y;
				cout << "Nhap gia tri node can them vao sau: ";
				cin >> y;
				cout << "Nhap gia tri them: ";
				cin >> x;
				if (themSau(y, x))
					cout << "Them thanh cong , vui long chon xuat danh sach lien ket don de xem ket qua!" << endl;
				else
					cout << "Them khong thanh cong vi khong tim thay " << y << " trong danh sach lien ket don!" << endl;
			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 5:
			if (in)
			{
				cout << "Danh sach lien ket don dang luu tru la: " << endl;
				xuat();
			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 6:
			if (in)
			{
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				if (timKiem(x) != NULL)
				{
					cout << x << " co trong danh sach lien ket don!" << endl;
				}
				else
				{
					cout << x << " khong co trong danh sach lien ket don!" << endl;
				}
			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 7:
			if (in)
			{
				if (xoaDau())
				{
					cout << "Xoa phan tu dau danh sach lien ket don thanh cong , vui long chon xuat danh sach de kiem tra thong tin!" << endl;
				}
				else
				{
					cout << "Xoa dau khong thanh cong!" << endl;
				}
			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 8:
			if (in)
			{
				if (xoaCuoi())
				{
					cout << "Xoa phan tu cuoi danh sach lien ket don thanh cong, vui long chon xuat danh sach de kiem tra thong tin!" << endl;
				}
			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 9:
			if (in)
			{

			}
			else
				cout << "Vui long khoi tao danh sach lien ket don!" << endl;
			break;
		case 10:
			cout << "Ban chon thoat chuong trinh!" << endl;
			break;
		default:
			cout << "Lua chon khong hop le!" << endl;
			break;
		}
		_getch();
	} while (luaChon >= 1 || luaChon <= 10);
	return 0;
}