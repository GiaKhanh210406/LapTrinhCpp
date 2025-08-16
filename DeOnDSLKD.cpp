//Ôn tập : Quản lý một danh sách sinh viên có số lượng lớn(danh sách liên kết đơn).Mỗi sinh viên
//bao gồm : mã số, họ tên, ngày sinh, điểm trung bình.Thực hiện các yêu cầu sau :
//a.Khai báo cấu trúc sinh viên và danh sách sinh viên.
//b.Viết thủ tục thêm một sinh viên vào đầu và cuối danh sách.
//c.Viết thủ tục xoá một sinh viên ở đầu và cuối danh sách.
//d.Viết thủ tục đọc danh sách sinh viên từ file SinhVien.txt.
//e.Viết thủ tục xuất danh sách sinh viên(bao gồm tất cả thông tin của sinh viên).
//f.Viết thủ tục trả về sinh viên thứ i(i là chỉ số do người dùng nhập từ 0 đến số lượng sinh viên - 1).
//g.Viết thủ tục tìm kiếm một sinh viên theo tên(có thể trùng nhau).
//h.Viết thủ tục thêm một sinh viên trước sinh viên có mã số do người dùng nhập.
//i.Viết thủ tục thêm một sinh viên sau sinh viên có mã số do người dùng nhập.
//j.Viết thủ tục xóa một sinh viên có mã số là X(X do người dùng nhập).
//k.Viết thủ tục sắp xếp danh sách sinh viên tăng dần theo điểm trung bình.

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;


struct SinhVien
{
	int maSo;
	string hoTen;
	string ngaySinh;
	double dtb;

	void xuat()
	{
		cout << maSo << "," << hoTen << "," << ngaySinh << "," << dtb << endl;
	}

	
};

struct Node
{
	Node *next;
	SinhVien info;
};

struct dssv
{
	Node *first;
	int sl;

	dssv()
	{
		first = NULL;
		sl = 0;
	}

	Node *taoNode(SinhVien sv)
	{
		Node *p = new Node;
		p->info = sv;
		p->next = NULL;
		return p;
	}

	bool isEmpty()
	{
		return first == NULL;
	}

	void themDau(SinhVien sv)
	{
		Node *p = taoNode(sv);
		p->next = first;
		first = p;
		sl++;
	}

	void themCuoi(SinhVien sv)
	{
		Node *p = taoNode(sv);
		if (isEmpty()) 
		{
			themDau(sv);
			return;
		}
		Node *q = first;
		while (q->next != NULL)
		{
			q = q->next;
		}
		q->next = p;
		sl++;
	}

	int xoaDau()
	{
		if (first != NULL)
		{
			Node *p = first;
			first = first->next;
			delete p;
			sl--;
			return 1;
		}
		return 0;
	}

	int xoaCuoi()
	{
		if (first != NULL)
		{
			Node *p, *q;
			p = first;
			q = NULL;
			while (p->next != NULL)
			{
				q = p;
				p = p->next;
			}
			if (p != first)
				q->next = NULL;
			else
				first = NULL;
			delete p;
			sl--;
			return 1;
		}
		return 0;
	}

	void docFile(string tenFile)
	{
		ifstream fin(tenFile);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				SinhVien sv;
				fin >> sv.maSo;
				fin.ignore();
				getline(fin, sv.hoTen, ',');
				getline(fin, sv.ngaySinh, ',');
				fin >> sv.dtb;

				themCuoi(sv);
			}
			fin.close();
		}
		else
			cout << "Khong mo file thanh cong!" << endl;
	}

	void xuatSv()
	{
		Node *p = first;
		while (p != NULL)
		{
			p->info.xuat();
			p = p->next;
		}
	}

	Node *timKiemTheoTen()
	{
		string ten;
		cout << "Nhap ho va ten muon tim kiem: ";
		getline(cin, ten);

		Node *p = first;
		while (p != NULL)
		{
			if (p->info.hoTen == ten)
			{
				xuatSv();
				return p;
			}
			p = p->next;
		}
		return NULL;
	}

	void themSauSv(SinhVien sv, int x)
	{
		Node *q = first;
		while (q != NULL)
		{
			if (q->info.maSo == x)
			{
				Node *p = taoNode(sv);
				p->next = q->next;
				q->next = p;
				sl++;
				return;
			}
			q = q->next;
		}
	}

	int xoaSauSv(int x)
	{
		if (!isEmpty())
		{
			Node *p = first;
			while (p != NULL && p->info.maSo != x)
			{
				p = p->next;
			}

			if (p == NULL || p->next == NULL)
				return 0;

			Node *t = p->next;
			p->next = t->next;
			delete t;
			sl--;
			return 1;
		}
		return 0;
	}
	
	int themTruocSv(SinhVien sv,int x)
	{
		if (!isEmpty())
		{
			if (first->info.maSo == x)
			{
				themDau(sv);
				sl++;
				return 1;
			}

			Node *p = first;
			Node *q = NULL;

			while (p != NULL && p->info.maSo != x)
			{
				q = p;
				p = p->next;
			}

			if (p == NULL) // neu khong tim thay thi dung
				return 0;

			Node *tmp = taoNode(sv);
			tmp->next = p;
			q->next = tmp;
			sl++;
			return 1;
		}
		return 0;
	}

	Node *at(int idx)
	{
		Node *p = first;
		int i = 0;
		while (p != NULL)
		{
			if (i == idx)
				return p;
			i++;
			p = p->next;
		}
	}

	Node *timKiem(int x)
	{
		Node *p = first;
		while (p != NULL && p->info.maSo != x)
		{
			p = p->next;
		}
		return p;
	}

	int xoaSv(SinhVien sv,int x)
	{
		if (!isEmpty())
		{
			Node *p = first;
			Node *q = NULL;
			while (p != NULL && p->info.maSo != x)
			{
				q = p;
				p = p->next;
			}

			if (p == NULL)
				return 0;
			if (p == first)
				return xoaDau();
			else
				q->next = p->next;
			delete p;
			sl--;
			return 1;
		}
		return 0;
	}

	void xuatSvI(SinhVien sv,int x)
	{
		for (int i = 0; i < sl; i++)
		{
			if (sv.maSo == x)
			{
				sv.xuat();
			}
		}
	}

	void hoanDoi(SinhVien &a, SinhVien &b)
	{
		SinhVien c = a;
		a = b;
		b = c;
	}

	void sapXepTheoSelectionShort()
	{
		cout << "==============" << endl;
		cout << "Danh sach sinh vien co diem trung binh tang dan duoc sap xep theo thuat toan Selection Short la: " << endl;
		
		int min_pos;
		for (int i = 0; i < sl - 1; i++)
		{
			min_pos = i;
			for (int j = i + 1; j < sl; j++)
			{
				if (at(j)->info.dtb < at(min_pos)->info.dtb)
				{
					min_pos = j;
				}
			}
			hoanDoi(at(min_pos)->info, at(i)->info);
		}
	}

	void sapXepTheoInsertionShort()
	{
		cout << "==============" << endl;
		cout << "Danh sach sinh vien co diem trung binh tang dan duoc sap xep theo thuat toan Insertion Short la: " << endl;
		int j;
		for (int i = 1; i < sl; i++)
		{
			SinhVien key = at(i)->info;
			j = i - 1;

			while (0 <= j && key.dtb < at(j)->info.dtb)
			{
				at(j + 1)->info = at(j)->info;
				j--;
			}

			at(j + 1)->info = key;

		}
	}

	void sapXepTheoBubbleShort()
	{
		cout << "==============" << endl;
		cout << "Danh sach sinh vien co diem trung binh tang dan duoc sap xep theo thuat toan Bubble Short la: " << endl;\

		for (int i = 0; i < sl-1; i++)
		{
			for (int j = sl - 1; j > i; j--)
			{
				if (at(j - 1)->info.dtb > at(j)->info.dtb)
				{
					hoanDoi(at(j)->info, at(j - 1)->info);
				}
			}
		}
	}

	void sapXepTheoInterchangeShort()
	{
		cout << "==============" << endl;
		cout << "Danh sach sinh vien co diem trung binh tang dan duoc sap xep theo thuat toan Bubble Short la: " << endl; \

			for (int i = 0; i < sl - 1; i++)
			{
				for (int j = i+1; j < sl; j++)
				{
					if (at(i)->info.dtb > at(j)->info.dtb)
					{
						hoanDoi(at(i)->info, at(j)->info);
					}
				}
			}
	}

	int suaSV()
	{
		int x;
		cout << "Nhap ma so sinh vien muon sua thong tin: ";
		cin >> x;
		cin.ignore();

		Node *p = first;
		while (p != NULL && p->info.maSo != x)
		{
			p = p->next;
		}
		if (p == NULL)
			return 0;
		cout << "Nhap ho va ten moi cua sinh vien: ";
		getline(cin, p->info.hoTen);
		cout << "Nhap ngay thang nam sinh moi cua sinh vien: ";
		getline(cin, p->info.ngaySinh);
		cout << "Nhap diem trung binh moi cua sinh vien: ";
		cin >> p->info.dtb;
		return 1;
	}

	void nhapSvMoi()
	{
		int mssv;
		string hoTen, ngaySinh;
		double dtb;

		cout << "Nhap ma so sinh vien can them vao danh sach: ";
		cin >> mssv;
		cin.ignore();
		cout << "Nhap ho va ten sinh vien can them vao danh sach: ";
		getline(cin, hoTen);
		cout << "Nhap ngay thang nam sinh cua sinh vien can them vao danh sach: ";
		getline(cin, ngaySinh);
		cout << "Nhap diem trung binh cua sinh vien can them vao danh sach: ";
		cin >> dtb;
	}
};
int main()
{
	dssv ds;
	SinhVien sv;
	int luaChon,x;
	bool in = false;

	do
	{
		system("cls");
		cout << "===MENU===\n"
			<< "1.Doc File SinhVien.txt.\n"
			<< "2.Them 1 sinh vien vao dau danh sach.\n"
			<< "3.Them 1 sinh vien vao cuoi danh sach.\n"
			<< "4.Xoa 1 sinh vien o dau danh sach.\n"
			<< "5.Xoa 1 sinh vien o cuoi danh sach.\n"
			<< "6.Xoa sinh vien theo ma so sinh vien.\n"
			<< "7.Xoa 1 sinh vien sau 1 sinh vien bat ky.\n"
			<< "8.Them 1 sinh vien vao truoc 1 sinh vien bat ky.\n"
			<< "9.Them 1 sinh vien vao sau 1 sinh vien bat ky.\n"
			<< "10.Xuat toan bo danh sach sinh vien.\n"
			<< "11.Tra ve thong tin cua sinh vien co trong danh sach.\n"
			<< "12.Tim kiem sinh vien theo ho va ten.\n"
			<< "13.Sua thong tin sinh vien theo ma so sinh vien.\n"
			<< "14.Sap xep danh sach sinh vien tang dan theo diem trung binh theo thuat toan Selection Short.\n"
			<< "15.Sap xep danh sach sinh vien tang dan theo diem trung binh theo thuat toan Insertion Short.\n"
			<< "16.Sap xep danh sach sinh vien tang dan theo diem trung binh theo thuat toan Bubble Short.\n"
			<< "17.Sap xep danh sach sinh vien tang dan theo diem trung binh theo thuat toan Interchage Short.\n"
			<< "18.Thoat chuong trinh.\n"
			<< ">>Lua chon cua ban la: ";
		cin >> luaChon;

		switch (luaChon)
		{
		case 1:
			ds.docFile("SinhVien.txt");
			cout << "Da doc file thanh cong! Thuc hien cac chuc nang tiep theo!" << endl;
			in = true;
			break;
		case 2:
			if (in)
			{
				ds.themDau(sv);
				ds.nhapSvMoi();
				cout << "Da them sinh vien moi vao dau danh sach! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 3:
			if (in)
			{
				ds.themCuoi(sv);
				ds.nhapSvMoi();
				cout << "Da them sinh vien moi vao cuoi danh sach! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 4:
			if (in)
			{
				ds.xoaDau();
				cout << "Da xoa sinh vien dau danh sach thanh cong! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 5:
			if (in)
			{
				ds.xoaCuoi();
				cout << "Da xoa sinh vien cuoi danh sach thanh cong! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 6:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de xoa sinh vien khoi danh sach: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.xoaSv(sv, x);
				cout << "Da xoa sinh vien thanh cong! Vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 7:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de xoa sau: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.xoaSauSv(x);
				cout << "Da xoa sau sinh vien " << x << " , vui long chon xuat danh sach de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 8:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de them 1 sinh vien vao truoc: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.themTruocSv(sv, x);
				cout << "Da them 1 sinh vien vao truoc sinh vien " << x << " thanh cong! Vui long chon xuat de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 9:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de them 1 sinh vien vao sau: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.themSauSv(sv, x);
				cout << "Da them 1 sinh vien vao sau sinh vien " << x << " thanh cong! Vui long chon xuat de kiem tra thong tin!" << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 10:
			if (in)
			{
				cout << "====DANH SACH TOAN BO SINH VIEN====" << endl;
				ds.xuatSv();
				cout << endl;
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 11:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de thong tin: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.xuatSvI(sv, x);
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 12:
			if (in)
			{
				ds.timKiemTheoTen();
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 13:
			if (in)
			{
				ds.suaSV();
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 14:
			if (in)
			{
				ds.sapXepTheoSelectionShort();
				ds.xuatSv();
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 15:
			if (in)
			{
				ds.sapXepTheoInsertionShort();
				ds.xuatSv();
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 16:
			if (in)
			{
				ds.sapXepTheoBubbleShort();
				ds.xuatSv();
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 17:
			if (in)
			{
				ds.sapXepTheoInterchangeShort();
				ds.xuatSv();
			}
			else
				cout << "Vui long chon doc file SinhVien.txt truoc khi thuc hien thao tac nay!" << endl;
			break;
		case 18:
			cout << "Ban chon thoat chuong trinh! Cam on da su dung!" << endl;
			break;
		default:
			cout << "Lua chon cua ban khong hop le! Vui long kiem tra lai!" << endl;
			break;
		}
		_getch();
	} while (luaChon >= 1 || luaChon <= 18);
	return 0;
}