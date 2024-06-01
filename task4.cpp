#include <iostream>

using namespace std;

float tinhDinhThucMaTran(float matrix[2][2])
{
	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

bool tinhMaTranNghichDao(float matrix[2][2], float inverse[2][2]) {
    float det = tinhDinhThucMaTran(matrix);

    if (det == 0) {
        cout << "Ma tran khong co nghich dao." << endl;
        return false;
    }

    inverse[0][0] = matrix[1][1] / det;
    inverse[0][1] = -matrix[0][1] / det;
    inverse[1][0] = -matrix[1][0] / det;
    inverse[1][1] = matrix[0][0] / det;

    return true;
}
void inMaTran(float matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    float matrix[2][2];
    float inverse[2][2];

    cout << "Nhap cac phan tu cua ma tran 2x2:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Nhap phan tu thu [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Ma tran nhap vao:" << endl;
    inMaTran(matrix);

    if (tinhMaTranNghichDao(matrix, inverse)) {
        cout << "Ma tran nghich dao:" << endl;
        inMaTran(inverse);
    }
	return 0;
}