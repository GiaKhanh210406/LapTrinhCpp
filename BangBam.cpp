/*
Bài 1: Dùng cấu trúc bảng băm – phương pháp kết nối trực tiếp, quản lý 11 phần tử kiểu số int.

a. Khai báo cấu trúc bảng băm
b. Viết thủ tục khởi bảng băm rỗng
c. Viết thủ tục thêm một phần tử vào bảng băm
d. Viết thủ tục tìm kiếm một phần tử trong bảng băm
e. Viết thủ tục xuất các giá trị tại các địa chỉ (heads), giá trị đang lưu trữ trong 1 địa chỉ nào đó của bảng băm. (1 head)
f. Viết thủ tục xuất toàn bộ giá trị đang lưu trữ theo từng địa chỉ trong bảng băm. (heads)
g. Viết thủ tục xóa toàn bộ phần tử trong 1 địa chỉ nào đó của bảng băm. (1 head)
h. Viết thủ tục xóa toàn bộ
i. Xoa 1 gia tri nao do khoi bang bam.

main : Thuc hien menu de kiem chung.
*/


#include <iostream>
#include <conio.h>
using namespace std;

const int M = 11;

struct Node
{
	int key;
	Node *next;
};


struct HT
{
	Node *head[M];
	Node *z;

	HT() //khoi tao
	{
		z = new Node;
		z->next = z;

		for (int i = 0; i < M; i++)
		{
			head[i] = z;
		}
	}

	int hash(int k)  //tra ve khoa thu may trong bang bam
	{
		return k % M;
	}

	void them(int k)
	{
		int index = hash(k);
		Node *t = head[index];
		Node *x = new Node;
		x->key = k;
		z->key = k;

		if (t->key >= k)
		{
			x->next = t;
			head[index] = x;
		}

		else
		{
			Node *p = t->next;
			while (p->key < k)
			{
				t = t->next;
				p = t->next;
			}

			t->next = x;
			x->next = p;
		}
	}

	Node *timKiem(int k)
	{
		int index = hash(k);
		Node *t = head[index];

		while (t->key < k)
		{
			t = t->next;
		}

		if (t->key != k)
			return z;
		return t;
	}

	void xuatTaiHead(Node *b)
	{
		Node *t = b;
		while (t != z)
		{
			cout << t->key << "\t";
			t = t->next;
		}
		cout << endl;
	}

	void xuatToanBoHT()
	{
		for (int i = 0; i < M; i++)
		{
			cout << "head[" << i << "]: ";
			xuatTaiHead(head[i]);
		}
	}

	void xoaHead(Node *&b)
	{
		Node *t = b;

		while (t != z)
		{
			Node *s = t;
			t = t->next;
			delete s;
		}
		b = z;
	}

	void xoaToanBo()
	{
		for (int i = 0; i < M; i++)
		{
			xoaHead(head[i]);
		}
	}

	int xoaKey(int &k)
	{
		int index = hash(k);
		Node *t = head[index];

		if (timKiem(k))
		{
			Node *s = t->next;

		}

		return 0;
	}
};


int main()
{
	HT ht;
	int luaChon, k;

	do
	{
		system("cls");
		cout << "+ MENU Bang Bam Ket Noi Truc Tiep\n"
			<< "1.Thu tuc them 1 phan tu vao bang bam.\n"
			<< "2.Thu tuc tim kiem 1 phan tu trong bang bam.\n"
			<< "3.Thu tuc xuat tat ca cac gia tri tai 1 head bat ky.\n"
			<< "4.Thu tuc xuat toan bo cac gia tri co trong bang bam.\n"
			<< "5.Thu tuc xoa toan bo gia tri tai 1 head bat ky.\n"
			<< "6.Thu tuc xoa toan bo gia tri cua bang bam.\n"
			<< "7.Xoa bat ky 1 gia tri nao do khoi bang bam.\n"
			<< "8.Thoat chuong trinh!.\n"
			<< ">> Lua chon cua ban la: ";
		cin >> luaChon;

		switch (luaChon)
		{
		case 1:
			cout << "Nhap gia tri can them vao bang bam: ";
			cin >> k;

			ht.them(k);

			cout << "Vui long chon xuat bang bam de kiem tra thong tin!" << endl;
			break;

		case 2:
			cout << "Nhap gia tri can tim trong bang bam: ";
			cin >> k;

			if (ht.timKiem(k) == ht.z) // duyet den cuoi
			{
				cout << "Khong tim thay " << k << " trong bang bam!" << endl;
			}

			else
				cout << "Gia tri can tim " << k << " co trong bang bam!" << endl;
			break;

		case 3:
			do
			{
				cout << "Ban muon xuat gia tri cua head thu: ";
				cin >> k;

				if (k < 0 || k > M - 1)
					cout << "Head khong hop le! Vui long nhap lai: ";

			} while (k < 0 || k > M - 1);

			ht.xuatTaiHead(ht.head[k]);
			break;

		case 4:
			cout << "Gia tri toan bo cua bang bam la: " << endl;
			ht.xuatToanBoHT();
			break;

		case 5:
			do
			{
				cout << "Ban muon xoa head thu: ";
				cin >> k;

				if (k < 0 || k > M - 1)
					cout << "Head muon xoa khong hop le! Vui long nhap lai: ";
			} while (k < 0 || k > M - 1);

			ht.xoaHead(ht.head[k]);
			cout << "Da xoa thanh cong, vui long chon xuat bang bam de kiem tra thong tin!" << endl;
			break;
		case 6:
			ht.xoaToanBo();
			cout << "Da xoa thanh cong, vui long chon xuat bang bam de kiem tra thong tin!" << endl;
			break;
		case 7:
			break;
		case 8:
			cout << "Ban da chon thoat chuong trinh , cam on ban da su dung!" << endl;
			break;
		default:
			cout << "Lua chon cua ban khong hop le! Vui long kiem tra lai!" << endl;
			break;
		}
		_getch();
	} while (luaChon >= 1 && luaChon <= 8);

	return 0;
}