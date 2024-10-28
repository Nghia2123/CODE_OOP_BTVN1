#include <iostream>
using namespace std;

// Xay dung kieu du lieu PhanSo
struct PhanSo {
	int tu, mau;
};

// Ham tinh gia tri thuc cua phan so
double gtriPS(PhanSo ps) {
	return (double)ps.tu / ps.mau;
}

int main() {
	int n; // So luong phan so
	cout << "Nhap so luong phan so: ";
	cin >> n;

	// Cap phat bo nho cho mang phan so
	PhanSo* ps = new PhanSo[n];

	// Nhap danh sach phan so
	for (int i = 0; i < n; i++) {
		do {
			cout << "Nhap phan so thu " << i + 1 << " (tu mau): ";
			cin >> ps[i].tu >> ps[i].mau;
			
			// Kiem tra mau so khac 0
			if (ps[i].mau == 0)
				cout << "Mau so phai khac 0. Vui long nhap lai!" << "\n\n";

			if (ps[i].mau < 0) {
				ps[i].tu = -ps[i].tu;
				ps[i].mau = -ps[i].mau;
			}

		} while (ps[i].mau == 0);
	}

	PhanSo mx = ps[0]; // Phan so lon nhat
	PhanSo mn = ps[0]; // Phan so nho nhat

	// Tim phan so lon nhat va nho nhat
	for (int i = 1; i < n; i++) {
		if (gtriPS(ps[i]) > gtriPS(mx)) {
			mx = ps[i];
		}

		if (gtriPS(ps[i]) < gtriPS(mn)) {
			mn = ps[i];
		}
	}

	// Xuat ket qua
	cout << '\n';
	cout << "Phan so nho nhat: " << mn.tu << "/" << mn.mau << endl;
	cout << "Phan so lon nhat: " << mx.tu << "/" << mx.mau << endl;
	
}