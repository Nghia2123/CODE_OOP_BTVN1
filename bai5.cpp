#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ham kiem tra xem hinh chu nhat co ria bang 0 hay khong
bool hasZeroBorder(const vector<vector<int>>& matrix, int x, int y, int w, int h, int m, int n) {
    // Kiem tra canh tren va canh duoi cua hinh chu nhat
    for (int j = x; j < x + w; ++j) {
        if ((y > 0 && matrix[y - 1][j] != 0) || (y + h < m && matrix[y + h][j] != 0)) {
            return false;
        }
    }
    // Kiem tra canh trai va canh phai cua hinh chu nhat
    for (int i = y; i < y + h; ++i) {
        if ((x > 0 && matrix[i][x - 1] != 0) || (x + w < n && matrix[i][x + w] != 0)) {
            return false;
        }
    }
    return true;
}

// Ham kiem tra xem hinh chu nhat co toan bo la 1 hay khong
bool isFillWith1(const vector<vector<int>>& matrix, int x, int y, int w, int h) {
    for (int i = y; i < y + h; ++i) {
        for (int j = x; j < x + w; ++j) {
            if (matrix[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

// Ham de tim hinh chu nhat co kich thuoc toi thieu la 2x2
vector<vector<int>> findRectangles(const vector<vector<int>>& matrix, int m, int n) {
    vector<vector<int>> rectangles;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int x = j, y = i;
                int w = 0, h = 0;

                // Tim chieu rong cua hinh chu nhat
                while (x + w < n && matrix[i][x + w] == 1) ++w;

                // Tim chieu cao cua hinh chu nhat
                while (y + h < m && matrix[y + h][j] == 1) ++h;

                // Danh dau cac phan tu cua hinh chu nhat la da tham neu thoa dieu kien
                if (w >= 2 && h >= 2 && hasZeroBorder(matrix, j, i, w, h, m, n)
                    && isFillWith1(matrix, j, i, w, h)) {

                    // Them hinh chu nhat vao danh sach
                    rectangles.push_back({ j, i, w, h });

                    // Danh dau cac phan tu cua hinh chu nhat la da tham
                    for (int p = i; p < i + h; ++p)
                        for (int q = j; q < j + w; ++q)
                            visited[p][q] = true;
                }
            }
        }
    }

    // Sap xep danh sach cac hinh chu nhat tu trai sang phai va tu tren xuong duoi
    sort(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
        });

    return rectangles;
}

int main() {
    int m, n;
    cin >> m >> n;

    // Nhap ma tran
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Tim cac hinh chu nhat
    vector<vector<int>> rectangles = findRectangles(matrix, m, n);

    // Xuat cac hinh chu nhat
    for (const auto& rect : rectangles) {
        cout << "[" << rect[0] << ", " << rect[1] << ", " << rect[2] << ", " << rect[3] << "]\n";
    }

    return 0;
}

