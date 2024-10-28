#include <iostream>
#include <vector>
using namespace std;

void arnoldsCatMap(vector<vector<int>>& matrix, int m) {
    vector<vector<int>> temp = matrix; // Tao mot ma tran tam thoi
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int new_i = (2 * i + j) % m;
            int new_j = (i + j) % m;
            temp[new_i][new_j] = matrix[i][j]; // Gan gia tri moi 
        }
    }
    matrix = temp; // Cap nhat ma tran
}

// Ham kiem tra hai ma tran co giong nhau khong
bool isEqual(const vector<vector<int>>& a, const vector<vector<int>>& b, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int m;
    cin >> m;

    // Nhap ma tran ban dau
    vector<vector<int>> matrix(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << '\n';

    // Luu lai ma tran ban dau de so sanh
    vector<vector<int>> original_matrix = matrix;

    int k = 0; // Bien dem so lan bien doi
    do {
        arnoldsCatMap(matrix, m); // Thuc hien bien doi Arnold's Cat Map
        k++;                      // Tang bien dem so lan bien doi len 1
    } while (!isEqual(matrix, original_matrix, m));
    // Dung khi ma tran ban dau duoc phuc hoi

    // Xuat so lan bien doi
    cout << k << '\n';

    return 0;
}