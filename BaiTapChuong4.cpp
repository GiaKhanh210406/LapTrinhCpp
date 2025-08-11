//Dạ thưa thầy là câu g.Viết thủ tục tính chiều cao cây em không biết làm ạ.

#include <iostream>
#include <conio.h>
using namespace std;

const int dem1 = 10;

struct Node
{
	int info;
	Node *left, *right;
};

struct BST
{
	Node *root;

	BST()
	{
		root = NULL;
	}

	void themNode(Node *&p, int x)
	{
		if (p == NULL)
		{
			p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
		}
		else
		{
			if (p->info == x)
				return;
			else if (p->info > x)
				return themNode(p->left, x);
			else
				return themNode(p->right, x);
		}
	}

	void tim(Node *&p, Node *&q)
	{
		if (p->left == NULL)
		{
			p->info = q->info;
			p = q;
			q = q->right;
		}

		else
			tim(p, q->left);
	}

	int xoaNode(Node *&T, int x)
	{
		if (T == NULL)
			return 0;
		if (T->info == x)
		{
			Node *p = T;

			if (T->left == NULL)
				T = T->right;
			else if (T->right == NULL)
				T = T->left;
			else
				tim(p, T->right);

			delete p;
			return 1;
		}

		if (T->info > x)
			return xoaNode(T->left, x);
		if (T->info < x)
			return xoaNode(T->right, x);
	}

	void duyetLNR(Node *p)
	{
		if (p != NULL)
		{
			duyetLNR(p->left);
			cout << p->info << " ";
			duyetLNR(p->right);
		}
	}

	int dem(Node *p, int &la, int &motCon, int &haiCon)
	{
		if (p == NULL)
			return 0;

		if (p->left == NULL && p->right == NULL)
		{
			la++;
		}

		else if (p->left == NULL && p->right != NULL || p->left != NULL && p->right == NULL)
		{
			motCon++;
		}

		else
			haiCon++;

		dem(p->left, la, motCon, haiCon);
		dem(p->right, la, motCon, haiCon);
	}

	void xuatDemNode(Node *p)
	{
		int la = 0, bac1 = 0, bac2 = 0;
		dem(p, la, bac1, bac2);


		cout << "So node la cua cay nhi phan tim kiem la: " << la << endl;
		cout << "So node bac 1 cua cay nhi phan tim kiem la: " << bac1 << endl;
		cout << "So node bac 2 cua cay nhi phan tim kiem la: " << bac2 << endl;
	}

	int tongNode(Node *p)
	{
		if (p == NULL)
			return 0;
		return p->info + tongNode(p->left) + tongNode(p->right);
	}

	int demNode(Node *p)
	{
		if (p == NULL)
			return 0;
		return 1 + demNode(p->left) + demNode(p->right);
	}

	double trungBinhcay(Node *p)
	{
		if (p == NULL)
			return 0;
		int node = demNode(p);
		int tong = tongNode(p);
		return tong * 1.0/ node;
	}

	void xuatDangHinhCay(Node *p, int space)
	{
		if (p == NULL)
			return;
		space += dem1;
		xuatDangHinhCay(p->right, space);
		cout << endl;

		for (int i = dem1; i < space; i++)
		{
			cout << " ";
		}

		cout << p->info << endl;
		xuatDangHinhCay(p->left, space);
	}
};


int main()
{
	BST bst;
	int x, luaChon;
	
	do
	{
		system("cls");
		cout << "---MENU---\n"
			<< "1.Them gia tri node vao cay nhi phan tim kiem.\n"
			<< "2.Xuat theo dang hinh cay nhi phan.\n"
			<< "3.Viet thu tuc xoa 1 phan tu trong cay nhi phan.\n"
			<< "4.Viet thu tuc duyet cay theo thu tu LNR de kiem tra (de quy).\n"
			<< "5.Viet thu tuc dem so node la,so node 1 con,so node 2 con,in ket qua ra man hinh.\n"
			<< "6.Viet thu tuc tinh gia tri trung binh cua cay.\n"
			<< "7.Thoat chuong trinh!\n"
			<< ">>Lua chon cua ban la: ";
		cin >> luaChon;

		switch (luaChon)
		{
		case 1:
				bst.themNode(bst.root, 20);
				bst.themNode(bst.root, 40);
				bst.themNode(bst.root, 10);
				bst.themNode(bst.root, 9);
				bst.themNode(bst.root, 1);
				bst.themNode(bst.root, 2);
				bst.themNode(bst.root, 25);
				bst.themNode(bst.root, 22);
				bst.themNode(bst.root, 7);
			break;
		case 2:
				cout << "Cay nhi phan ban dau la: " << endl;
				bst.xuatDangHinhCay(bst.root, 0);
			break;
		case 3:
			cout << "Nhap gia tri node muon xoa: ";
			cin >> x;
			if (bst.xoaNode(bst.root, x))
				cout << "Da xoa node " << x << " thanh cong.\n";
			else
				cout << "Khong tim thay node " << x << " trong cay.\n";
			cout << "Cay nhi phan sau khi xoa node la:\n";
			bst.xuatDangHinhCay(bst.root, 0);
			break;
		case 4:
				cout << "Duyet cay theo thu tuc LNR la: " << endl;
				bst.duyetLNR(bst.root);
			break;
		case 5:
				bst.xuatDemNode(bst.root);
			break;
		case 6:
				cout << "Gia tri trung binh cua cay nhi phan la: " << bst.trungBinhcay(bst.root);
			break;
		case 7:
			cout << "Ban da chon thoat chuong trinh! Cam on ban da su dung!" << endl;
			break;
		default:
			cout << "Lua chon cua ban khong hop le! Vui long kiem tra lai!" << endl;
			break;
		}
		_getch();
	} while (luaChon >= 1 && luaChon <= 7);
	return 0;
}