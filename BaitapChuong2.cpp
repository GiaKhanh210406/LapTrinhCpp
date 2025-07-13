#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
	string maSo;
	string hoTen;
	string ngaySinh;
	double diemTB;
	SinhVien* prev;
	SinhVien* next;
};

struct DanhSach {
	SinhVien* head;
	SinhVien* tail;
};

void khoiTao(DanhSach& ds) {
	ds.head = ds.tail = nullptr;
}

SinhVien* taoSinhVien(string ma, string ten, string ns, double dtb) {
	SinhVien* sv = new SinhVien;
	sv->maSo = ma;
	sv->hoTen = ten;
	sv->ngaySinh = ns;
	sv->diemTB = dtb;
	sv->next = sv->prev = nullptr;
	return sv;
}

void themCuoi(DanhSach& ds, SinhVien* sv) {
	if (ds.head == nullptr) {
		ds.head = ds.tail = sv;
	}
	else {
		ds.tail->next = sv;
		sv->prev = ds.tail;
		ds.tail = sv;
	}
}

void xoaDau(DanhSach& ds) {
	if (ds.head == nullptr) return;

	SinhVien* temp = ds.head;
	ds.head = ds.head->next;

	if (ds.head != nullptr) {
		ds.head->prev = nullptr;
	}
	else {
		ds.tail = nullptr;
	}

	delete temp;
}


void xuatNguoc(DanhSach ds) {
	SinhVien* p = ds.tail;
	while (p != nullptr) {
		cout << "Ma: " << p->maSo
			<< " | Ten: " << p->hoTen
			<< " | Ngay sinh: " << p->ngaySinh
			<< " | Diem TB: " << p->diemTB << endl;
		p = p->prev;
	}
}


int demDiemLonHonX(DanhSach ds, double x) {
	int dem = 0;
	SinhVien* p = ds.head;
	while (p != nullptr) {
		if (p->diemTB > x)
			dem++;
		p = p->next;
	}
	return dem;
}


void themTruocMaX(DanhSach& ds, string maX, SinhVien* svMoi) {
	SinhVien* p = ds.head;
	while (p != nullptr && p->maSo != maX)
		p = p->next;

	if (p == nullptr) {
		cout << "Khong tim thay sinh vien co ma: " << maX << endl;
		return;
	}

	svMoi->next = p;
	svMoi->prev = p->prev;

	if (p->prev != nullptr) {
		p->prev->next = svMoi;
	}
	else {
		ds.head = svMoi;
	}

	p->prev = svMoi;
}


SinhVien* nhapSinhVien() {
	string ma, ten, ns;
	double dtb;
	cout << "Nhap ma so: "; getline(cin, ma);
	cout << "Nhap ho ten: "; getline(cin, ten);
	cout << "Nhap ngay sinh: "; getline(cin, ns);
	cout << "Nhap diem TB: "; cin >> dtb;
	cin.ignore(); 
	return taoSinhVien(ma, ten, ns, dtb);
}


void nhapDanhSachSinhVien(DanhSach& ds) {
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cin.ignore(); 

	for (int i = 0; i < n; ++i) {
		cout << "\nNhap thong tin sinh vien thu " << (i + 1) << ":\n";
		SinhVien* sv = nhapSinhVien();
		themCuoi(ds, sv);
	}
}


void menu() {
	cout << "\n===== MENU =====\n";
	cout << "1. Nhap danh sach sinh vien\n";
	cout << "2. Xoa sinh vien o dau\n";
	cout << "3. Xuat danh sach theo chieu nguoc\n";
	cout << "4. Dem sinh vien co diem TB > X\n";
	cout << "5. Them SV moi truoc SV co ma X\n";
	cout << "0. Thoat\n";
	cout << "================\n";
}

int main() {
	DanhSach ds;
	khoiTao(ds);
	int luaChon;
	do {
		menu();
		cout << "Nhap lua chon: ";
		cin >> luaChon;
		cin.ignore(); 

		switch (luaChon) {
		case 1: {
			cout << "\n== Nhap danh sach sinh vien ==\n";
			nhapDanhSachSinhVien(ds);
			break;
		}
		case 2: {
			cout << "\n== Xoa SV o dau ==\n";
			xoaDau(ds);
			break;
		}
		case 3: {
			cout << "\n== Danh sach theo chieu nguoc ==\n";
			xuatNguoc(ds);
			break;
		}
		case 4: {
			double x;
			cout << "\nNhap diem trung binh X: ";
			cin >> x;
			cin.ignore();
			int dem = demDiemLonHonX(ds, x);
			cout << "Co " << dem << " sinh vien co diem TB > " << x << endl;
			break;
		}
		case 5: {
			cout << "\n== Them SV moi truoc SV co ma X ==\n";
			string maX;
			cout << "Nhap ma sinh vien X: ";
			getline(cin, maX);
			SinhVien* sv = nhapSinhVien();
			themTruocMaX(ds, maX, sv);
			break;
		}
		case 0: {
			cout << "Thoat chuong trinh.\n";
			break;
		}
		default:
			cout << "Lua chon khong hop le!\n";
		}

	} while (luaChon != 0);

	return 0;
}
