#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Kieu du lieu phan so
struct PhanSo {
    int tu; // tu so
    int mau; // mau so

    // Ham tinh gia tri cua phan so
    double giaTri() {
        return (double)tu / mau;
    }

	// Kiem tra neu hai phan so bang nhau
    bool soSanhBang(const PhanSo& b) {
        return tu * b.mau == b.tu * mau;
    }
};

// Ham so sanh phan so de sap xep
bool cmp(const PhanSo& a, const PhanSo& b) {
	return a.tu * b.mau < b.tu * a.mau;
}

// Ham tim tap con co tich bang phan so dich bang phuong phap de quy
void findSubsets(const vector<PhanSo>& PhanSos, PhanSo target,
    vector<PhanSo>& bestSubset, vector<PhanSo>& currentSubset,
    int index) {

    // Tinh tich cua cac phan so trong currentSubset
    PhanSo tich = { 1, 1 };
    for (const auto& frac : currentSubset) {
        tich.tu *= frac.tu;
		tich.mau *= frac.mau;
    }

	//Kiem tra neu tich bang phan so dich
    if (currentSubset.size() > 0 && tich.soSanhBang(target)) {
		// Neu tap hop nho hon tap hop bestSubset thi cap nhat lai bestSubset
        if (bestSubset.empty() || currentSubset.size() < bestSubset.size()) {
            bestSubset = currentSubset;
        }
        return;
    }

	// Neu da duyet het phan so thi ket thuc
    if (index >= PhanSos.size()) return;

	// Bo qua phan so hien tai va tim tap hop con khac
    findSubsets(PhanSos, target, bestSubset, currentSubset, index + 1);

	// Them phan so hien tai vao tap hop con
    currentSubset.push_back(PhanSos[index]);

	// Tim tap hop con tiep theo
    findSubsets(PhanSos, target, bestSubset, currentSubset, index + 1);

	// Xoa phan so hien tai khoi tap hop con
    currentSubset.pop_back();
}

int main() {
    int n;
    cout << "Nhap so luong phan so n: ";
    cin >> n;

	// Khoi tao vector chua cac phan so
    vector<PhanSo> PhanSos(n);

	// Nhap cac phan so
    for (int i = 0; i < n; ++i) {
        do {
            cout << "Nhap phan so thu " << i + 1 << " (tu mau): ";
            cin >> PhanSos[i].tu >> PhanSos[i].mau;

            // Kiem tra mau so cua phan so phai khac 0
			if (PhanSos[i].mau == 0) 
				cout << "Mau so phai khac 0! Vui long nhap lai.\n\n";
        } while (PhanSos[i].mau == 0);
    }

    // Nhap phan so dich
    PhanSo target;
    do {
        cout << "Nhap phan so dich (tu mau): ";
        cin >> target.tu >> target.mau;

		// Kiem tra mau so cua phan so phai khac 0
		if (target.mau == 0)
			cout << "Mau so phai khac 0! Vui long nhap lai.\n\n";
	} while (target.mau == 0);

	vector<PhanSo> bestSubset;     // Tap hop con tot nhat
	vector<PhanSo> currentSubset;  // Tap hop con hien tai

	// Tim tap hop con co tich bang phan so dich
    findSubsets(PhanSos, target, bestSubset, currentSubset, 0);

	// Kiem tra tap hop con co ton tai hay khong
    if (!bestSubset.empty()) {
		// Sap xep tap hop con theo thu tu tang dan
        sort(bestSubset.begin(), bestSubset.end(), cmp);

		// In cac phan so trong tap hop con
        cout << "\nTap hop con co tich bang phan so dich: ";
        for (const auto& frac : bestSubset) {
            cout << frac.tu << "/" << frac.mau << " ";
        }
        cout << '\n';
    }
    return 0;
}
