#include <iostream>
#include <algorithm>
using namespace std;

// Xay dung kieu du lieu PhanSo
struct PhanSo {
	int tu = 1, mau = 0;
};

bool cmp(const PhanSo& a, const PhanSo& b) {
	return a.tu * b.mau < a.mau * b.tu;
}

int main() {
	int n, k; // So luong phan so n va so nguyen k
	cout << "Nhap so luong phan so n va so nguyen k (n k): ";
	cin >> n >> k;

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

	// Sap xep mang phan so theo thu tu tang dan
	sort(ps, ps + n, cmp);
	
	if (k > n) return 0;
	if (k < 1) return 0;


	PhanSo mxk; // Phan so lon thu k
	PhanSo mnk; // Phan so nho thu k

	// Tim phan so be thu k
	for (int i = 0; i < n; i++) {
		if (i == k - 1) {
			mnk = ps[i];
			break;
		}
	}

	// Tim phan so lon thu k
	for (int i = n - 1; i >= 0; i--) {
		if (n-i == k) {
			mxk = ps[i];
			break;
		}
	}

	// Xuat ket qua
	cout << "Phan so be thu " << k << ": " << mnk.tu << "/" << mnk.mau << "\n";
	cout << "Phan so lon thu " << k << ": " << mxk.tu << "/" << mxk.mau << "\n";
}