//Ôn tập : Quản lý một danh sách sinh viên có số lượng lớn(danh sách liên kết kep).Mỗi sinh viên
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
		cout << "==============================" << endl;
		cout << maSo << "," << hoTen << "," << ngaySinh << "," << dtb << endl;
	}

	void nhap()
	{
		cout << "Nhap ma so sinh vien: ";
		cin >> maSo;
		cin.ignore();
		cout << "Nhap ho va ten sinh vien: ";
		getline(cin, hoTen);
		cout << "Nhap ngay thang nam sinh cua sinh vien: ";
		getline(cin, ngaySinh);
		cout << "Nhap diem trung binh cua sinh vien: ";
		cin >> dtb;
	}
};

struct Node
{
	SinhVien info;
	Node *next, *prev;
};

struct dssv
{
	Node *first, *last;
	int sl;

	dssv()
	{
		first = last = NULL;
		sl = 0;
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

	Node *taoNode(SinhVien sv)
	{
		Node *p = new Node;
		p->info = sv;
		p->next = NULL;
		p->prev = NULL;
		return p;
	}

	bool isEmpty()
	{
		return first == NULL && last == NULL;
	}

	void themDau(SinhVien sv)
	{
		Node *p = taoNode(sv);
		p->next = first;

		//kiem tra first co rong hay khong
		if (first != NULL)
			first->prev = p;
		else
			last = p;
		first = p;
		sl++;
	}

	void themCuoi(SinhVien sv)
	{
		Node *p = taoNode(sv);
		p->prev = last;
		//kiem tra last co rong hay khong
		if (last != NULL)
			last->next = p;
		else
			first = p;
		last = p;
		sl++;
	}

	int xoaDau()
	{
		if (!isEmpty())
		{
			Node *p = first;
			first = first->next;

			if (first != NULL) //kiem tra first khac NULL hay khong
				first->prev = NULL;
			else
				last = NULL;

			delete p;
			sl--;
			return 1;
		}
		return 0;
	}

	int xoaCuoi()
	{
		if (!isEmpty())
		{
			Node *p = last;
			last = last->prev;

			if (last != NULL)
				last->next = NULL;
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

	void xuatXuoiDssv()
	{
		Node *p = first;

		while (p != NULL)
		{
			p->info.xuat();
			p = p->next;
		}
	}

	void xuatNguocDssv()
	{
		Node *p = last;

		while (p != NULL)
		{
			p->info.xuat();
			p = p->prev;
		}
	}

	Node *timKiemTheoTen()
	{
		string ten;
		cout << "Nhap ho va ten cua sinh vien muon kiem tra: ";
		getline(cin, ten);

		Node *p = first;

		while (p != NULL)
		{
			if (p->info.hoTen == ten)
			{
				cout << "Da tim thay sinh vien: " << endl;
				p->info.xuat();
				return p;
			}
			p = p->next;
		}

		cout << "Khong tim thay sinh vien!" << endl;
		return NULL;
	}
	
	int themTruoc(SinhVien sv,int x)
	{
		if (!isEmpty())
		{
			Node *q = taoNode(sv);
			Node *p = first;
			Node *t = NULL;

			while (p != NULL && p->info.maSo != x)
			{
				t = p;
				p = p->next;
			}

			if (p == NULL)
				return 0;
			if (p == first)
			{
				themDau(sv);
				return 1;
			}

			q->next = p;
			p->prev = q;
			t->next = q;
			q->prev = t;
			sl++;
			return 1;
		}
		return 0;
	}

	int themSau(SinhVien sv, int x)
	{
		if (!isEmpty())
		{
			Node *p = first;
			Node *q = taoNode(sv);

			while (p != NULL && p->info.maSo != x)
			{
				p = p->next;
			}

			if (p == NULL)
				return 0;

			q->next = p->next;
			q->prev = p;
			p->next = q;

			if (p != last) //kiem tra neu p = last thi sao
				p->next->prev = q;
			else
				last = q;
			sl++;
			return 1;
		}
		return 0;
	}

	int xoaTruoc(int x)
	{
		if (!isEmpty())
		{
			Node *p = first;
			Node *t = NULL;

			while (p != NULL && p->info.maSo != x)
			{
				t = p;
				p = p->next;
			}

			if (p == NULL)
				return 0;
			if (p == first)
				return 0;
			if (t == first)
			{
				xoaDau();
				return 1;
			}
	
			t->prev->next = p;
			p->prev = t->prev;
			delete t;
			sl--;
			return 1;
		}
		return 0;
	}

	int xoaSau(int x)
	{
		if (!isEmpty())
		{
			Node *p = first;

			while (p != NULL && p->info.maSo != x)
			{
				p = p->next;
			}

			if (p == NULL)
				return 0;
			if (p == last)
				return 0;

			Node *t = p->next; //tim thay p da r moi gan t = p->next

			if (t == last)
			{
				xoaCuoi();
				return 1;
			}

			p->next = t->next;
			t->next->prev = p;
			delete t;
			sl--;
			return 1;
		}
		return 0;
	}

	int xoaSv(int x)
	{
		if (!isEmpty())
		{
			Node *p = first;
			Node *t = NULL;

			while (p != NULL && p->info.maSo != x)
			{
				t = p;
				p = p->next;
			}

			if (p == NULL)
				return 0;
			if (p == first)
			{
				xoaDau();
				return 1;
			}
			if (p == last)
			{
				xoaCuoi();
				return 1;
			}

			t->next = p->next;
			p->next->prev = t;
			delete p;
			sl--;
			return 1;
		}
		return 0;
	}

	void xuatSvI(SinhVien sv, int x)
	{
		for (int i = 0; i < sl; i++)
		{
			if (sv.maSo == x)
			{
				cout << "Da tim thay sinh vien co ma so la: " << x << " : " << endl;
				sv.xuat();
				return;
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
		cout << "+Danh sach sinh vien co diem trung binh giam dan duoc sap xep theo thuat toan Selection Short la: " << endl;
		int min_pos;
		for (int i = 0; i < sl-1; i++)
		{
			min_pos = i;
			for (int j = i + 1; j < sl; j++)
			{
				if (at(j)->info.dtb > at(min_pos)->info.dtb)
				{
					min_pos = j;
				}
			}
			hoanDoi(at(min_pos)->info, at(i)->info);
		}
	}

	void sapXepTheoInsertionShort()
	{
		cout << "Danh sach sinh vien co diem trung binh giam dan duoc sap xep theo thuat toan Insertion Short la: " << endl;

		int j;
		SinhVien x;

		for (int i = 1; i < sl; i++)
		{
			x = at(i)->info;
			j = i - 1;
			while (0 <= j && x.dtb > at(i)->info.dtb)
			{
				at(j + 1)->info = at(j)->info;
				j--;
			}
			at(j + 1)->info = x;
		}
	}

	void sapXepTheoBubbleShort()
	{
		cout << "Danh sach sinh vien co diem trung binh giam dan duoc sap xep theo thuat toan Bubble Short la: " << endl;

		for (int i = 0; i < sl - 1; i++)
		{
			for (int j = sl - 1; j > i; j--)
			{
				if (at(j-1)->info.dtb < at(j)->info.dtb)
				{
					hoanDoi(at(j)->info, at(j-1)->info);
				}
			}
		}
	}

	void sapXepTheoInterchageShort()
	{
		cout << "Danh sach sinh vien co diem trung binh tang dan duoc sap xep theo thuat toan Interchage Short la: " << endl;

		for (int i = 0; i < sl - 1; i++)
		{
			for (int j = i + 1; j < sl; j++)
			{
				if (at(j)->info.dtb > at(i)->info.dtb)
				{
					hoanDoi(at(i)->info, at(j)->info);
				}
			}
		}
	}
};
int main()
{
	dssv ds;
	SinhVien sv;
	int luaChon, x;
	bool in = false;

	do
	{
		system("cls");

		cout << "===MENU===\n"
			<< "1.Doc file SinhVien.txt\n"
			<< "2.Them 1 sinh vien vao dau danh sach.\n"
			<< "3.Them 1 sinh vien vao cuoi danh sach.\n"
			<< "4.Them 1 sinh vien vao truoc 1 sinh vien bat ky.\n"
			<< "5.Them 1 sinh vien vao sau 1 sinh vien bat ky.\n"
			<< "6.Xoa sinh vien o dau danh sach.\n"
			<< "7.Xoa sinh vien o cuoi danh sach.\n"
			<< "8.Xoa 1 sinh vien sau 1 sinh vien bat ky.\n"
			<< "9.Xoa 1 sinh vien truoc 1 sinh vien bat ky.\n"
			<< "10.Xoa 1 sinh vien theo ma so.\n"
			<< "11.Xuat toan bo danh sach sinh vien.\n"
			<< "12.Xuat theo chieu xuoi toan bo danh sach sinh vien.\n"
			<< "13.Xuat theo chieu nguoc toan bo danh sach sinh vien.\n"
			<< "14.Xuat sinh vien theo chi so.\n"
			<< "15.Tim kiem sinh vien theo ho va ten cua sinh vien.\n"
			<< "16.Sap xep danh sach sinh vien giam dan theo diem trung binh theo thuat toan Selection Short.\n"
			<< "17.Sap xep danh sach sinh vien giam dan theo diem trung binh theo thuat toan Insertion Short.\n"
			<< "18.Sap xep danh sach sinh vien giam dan theo diem trung binh theo thuat toan Bubble Short.\n"
			<< "19.Sap xep danh sach sinh vien giam dan theo diem trung binh theo thuat toan Interchage Short.\n"
			<< "20.Thoat chuong trinh!\n"
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
				sv.nhap();
				ds.themDau(sv);
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 3:
			if (in)
			{
				sv.nhap();
				ds.themCuoi(sv);
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 4:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de them 1 sinh vien truoc sinh vien do: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				sv.nhap();
				ds.themTruoc(sv, x);
				cout << "Danh sach sinh vien sau khi them la: " << endl;
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 5:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de them 1 sinh vien sau sinh vien do: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				sv.nhap();
				ds.themSau(sv, x);
				cout << "Danh sach sinh vien sau khi them la: " << endl;
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 6:
			if (in)
			{
				ds.xoaDau();
				cout << "Danh sach sinh vien sau khi xoa dau la: " << endl;
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 7:
			if (in)
			{
				ds.xoaCuoi();
				cout << "Danh sach sinh vien sau khi xoa cuoi la: " << endl;
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 8:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de xoa 1 sinh vien phia sau: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.xoaSau(x);
				cout << "Danh sach sau khi xoa la: " << endl;
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 9:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de xoa 1 sinh vien phia truoc: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.xoaTruoc(x);
				cout << "Danh sach sau khi xoa la: " << endl;
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 10:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de xoa 1 sinh vien do: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.xoaSv(x);
				cout << "Danh sach sinh vien sau khi xoa la: " << endl;
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 11:
			if (in)
			{
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 12:
			if (in)
			{
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 13:
			if (in)
			{
				ds.xuatNguocDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 14:
			if (in)
			{
				do
				{
					cout << "Nhap ma so sinh vien de xuat thong tin sinh vien do: ";
					cin >> x;
					if (x <= 0)
						cout << "Ma so sinh vien khong hop le! Nhap lai: ";
				} while (x <= 0);

				ds.xuatSvI(sv, x);
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 15:
			if (in)
			{
				ds.timKiemTheoTen();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 16:
			if (in)
			{
				ds.sapXepTheoSelectionShort();
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 17:
			if (in)
			{
				ds.sapXepTheoInsertionShort();
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 18:
			if (in)
			{
				ds.sapXepTheoBubbleShort();
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 19:
			if (in)
			{
				ds.sapXepTheoInterchageShort();
				ds.xuatXuoiDssv();
			}
			else
				cout << "Ban chua chon doc file SinhVien.txt . Vui long chon chuc nang 1!" << endl;
			break;
		case 20:
			cout << "Ban da chon thoat chuong trinh! Cam on da su dung!" << endl;
			break;
		default:
			cout << "Lua chon cua ban khong hop le! Vui long kiem tra lai!" << endl;
			break;
		}
		_getch();
	} while (luaChon >= 1 && luaChon <= 19);
	return 0;
}